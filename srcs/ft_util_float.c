/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 12:38:06 by flhember          #+#    #+#             */
/*   Updated: 2019/04/19 13:31:59 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ft_ld_in_str(long double res, int i)
{
	char	*str;
	int		j;

	j = 0;
	if (!(str = (char*)ft_memalloc(sizeof(char) * 1000)))
		return (NULL);
	if (i == 1)
		str[j++] = (int)res + 49;
	else if (i == 0)
		str[j++] = (int)res + 48;
	if ((int)res > 0)
		res = (res - (int)res);
	str[j++] = '.';
	while (res && j < 200)
	{
		res *=  10.00;
		str[j++] = (int)res + 48;
		res -= (int)res;
	}
	return (str);
}

int			ft_size_vir(long double f)
{
	int		i;

	i = 1;
	if ((int)f == 9)
		return(1);
	while (f > 9 || f < -9)
	{
		f /= 10;
		i++;
	}
	return (i);
}

char		*ft_get_rond(char *str, int i)
{
	char	*str_final;

	i = ft_strlen(str) - 1;
	str_final = NULL;
	if (str[i] == '.')
		i--;
	if (str[i] >= '5' && str[i] <= '9')
	{
		if (str[i - 1] == '.')
			i--;
		if (str[i - 1] != '9')
			str[i - 1] = str[i - 1] + 1;
		else
		{
			while (str[i - 1] == '9')
			{
				str[i - 1] = '0';
				i--;
				if (str[i - 1] == '.')//&& --i)
					i--;	//str[i - 1] += 1;
				if (str[i - 1] != '9')
					str[i - 1] += 1;
			}
			if (str[0] == '0')
				str = ft_strjoinfree("1", str, 2);
		}
	}
	str_final = ft_strsub(str, 0, (ft_strlen(str) - 1));
	ft_strdel(&str);
	return (str_final);
}

char		*ft_check_hash(char *str, int hash)
{
	char 	*str_final;

	str_final = NULL;
	if (str[ft_strlen(str) - 1] == '.')
	{
		if (!hash)
		{
			str_final = ft_strsub(str, 0, (ft_strlen(str) - 1));
			ft_strdel(&str);
			return (str_final);
		}
	}
	return (str);
}

char			*ft_round_after_vir(char *str, int i)
{
	int		flag;

	flag = 0;
	if (str[i - 2] == '9')
	{
		flag++;
		while (i > 0 && str[i - 2] == '9')
		{	
			str[i - 2] = 0;
			i--;
		}
		if (i - 2 >= 0)
			str[i - 2] += 1;
	}
	else
		str[i - 2] += 1;
	if (flag || i == 0)
		str = ft_strjoinfree("1", str, 2);
	return (str);
}

char			*ft_get_rond_null(char *str, int hash, int prec, int vir)
{
	int		i;
	char	*str_final;

	i = 0;
	if (!(str_final = (char *)ft_memalloc(sizeof(char) * (prec + vir + 4))))
		return (NULL);
	while (i < prec + vir + 3)
	{
		str_final[i] = str[i];
		i++;
	}
	str_final = ft_get_rond(str_final, i);
	i = ft_strlen(str_final) - 1;
	if (str_final[i] > '5' && str_final[i] <= '9')
		str_final = ft_round_after_vir(str_final, i);
	str_final = ft_strsub(str_final, 0, ft_strlen(str_final) - 2);
	if (hash)
		str_final = ft_strjoinfree(str_final, ".", 1);
	return (str_final);
}

char			*ft_cut_prec(char *str, int prec, int vir, int hash)
{
	char	*str_final;
	int		i;

	i = 0;
	str_final = NULL;
	if (prec == 0 || prec == - 1)
		return (str_final = ft_get_rond_null(str, hash, prec, vir));
	if (!(str_final = (char *)ft_memalloc(sizeof(char) * (prec + vir + 3))))
		return (NULL);
	while (i < prec + vir + 2)
	{
		str_final[i] = str[i];
		i++;
	}
	ft_strdel(&str);
	if (str_final[0] != '0' && str_final[1] != '\0')
	{
		str_final = ft_get_rond(str_final, i);
		str_final = ft_check_hash(str_final, hash);
	}
	else if (prec >= 0 && ft_strlen(str_final) > 1)
		return (ft_strsub(str_final, 0, ft_strlen(str_final) - 1));
	return (str_final);
}
