/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:02:54 by flhember          #+#    #+#             */
/*   Updated: 2019/04/18 13:54:43 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_add_str(char *s1, char *s2)
{
	int		i;
	int		k;
	int		tmp;
	char	*res;
	int		retenu;

	k = 0;
	tmp = 0;
	retenu = 0;
	i = ft_strlen(s1);
	if (!(res = (char*)ft_memalloc(sizeof(char) * (5000))))
		return (NULL);
	while (--i >= 0)
	{
		tmp = (s1[i] - 48) + (s2[i] - 48) + retenu;
		if (tmp > 9)
		{
			retenu = tmp / 10;
			tmp = tmp % 10;
		}
		else
			retenu = 0;
		res[k++] = (char)tmp + 48;
	}
	if (retenu)
		res[k++] = (char)retenu + 48;
	ft_strdel(&s1);
	res = ft_str_rev(res);
	return (res);
}

static void	ft_verif_size(char **s1, char **s2)
{
	int		i;
	int		j;

	i = ft_strlen((*s1));
	j = ft_strlen((*s2));
	if (i < j)
		while (i++ < j)
			*s1 = ft_strjoinfree("0", *s1, 2);
	else if (j < i)
		while (j++ < i)
			*s2 = ft_strjoinfree("0", *s2, 2);
}

static char	*ft_mult(char *str_fl, int div)
{
	int		j;
	int		k;
	int		tmp;
	int		retenu;
	char	*res;

	k = 0;
	retenu = 0;
	j = ft_strlen(str_fl) - 1;
	if (!(res = (char*)ft_memalloc(sizeof(char) * (5000))))
		return (NULL);
	while (j >= 0)
	{
		if (str_fl[j] == '.')
			j--;
		tmp = div * ((int)str_fl[j--] - 48) + retenu;
		if (tmp > 9)
		{
			retenu = tmp / 10;
			tmp = tmp % 10;
		}
		else
			retenu = 0;
		res[k++] = (char)tmp + 48;
	}
	if (retenu)
		res[k++] = retenu + 48;
	return (res);
}

char	*ft_mult_str(char *str_fl, char *str_en)
{
	char	*str_final;
	char	*res;
	int		i;
	int		j;
	int		div;

	i = -1;
	str_final = NULL;
	res = NULL;
	while (++i < (int)ft_strlen(str_en))
	{
		div = (int)str_en[ft_strlen(str_en) - i - 1] - 48;
		if (div >= 0)
		{
			res = ft_mult(str_fl, div);
			j = 0;
			while (j++ < i)
				res = ft_strjoinfree("0", res, 2);
			res = ft_str_rev(res);
			if (!str_final)
				str_final = ft_strdup(res);
			else
			{
				ft_verif_size(&str_final, &res);
				str_final = ft_add_str(str_final, res);
			}
			ft_strdel(&res);
		}
//		if (str_final)
//			str_final = ft_clean_str(str_final);
	}
	return (str_final);
}

char			*ft_pow_to_str(long b)
{
	int		i;
	char	*tmp;
	char	*str;

	i = 1;
	tmp = ft_strdup("2");
	str = NULL;
	while (i++ < b)
	{
		str = ft_mult_str(tmp, "2");
		ft_strdel(&tmp);
		tmp = ft_strdup(str);
		ft_strdel(&str);
	}
	return (tmp);
}
