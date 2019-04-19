/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_real_float.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:15:52 by flhember          #+#    #+#             */
/*   Updated: 2019/04/18 14:10:19 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_check_size(char *str)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (str[i] != '.')
		i++;
	while (str[i++])
		j++;
	while (j++ <= 64) //52
		str = ft_strjoinfree(str, "0", 1);
	return (str);
}

char	*ft_put_point(char *str, int vir)
{
	int		i;
	char	*end;
	char	*start;
	char	*str_final;

	end = NULL;
	start = NULL;
	str_final = NULL;
	i = ft_strlen(str) - vir;
	start = ft_strsub(str, 0, vir);
	end = ft_strsub(str, vir, i);
	str_final = ft_strjoinfree(start, ".", 1);
	str_final = ft_strjoinfree(str_final, end, 3);
	ft_strdel(&str);
	return (str_final);
}

char		*ft_get_expo(t_ftoa **list)
{
	int			i;
	int			j;
	long double	tmp;
	char		*exp;

	i = 10;
	j = 0;
	tmp = 0;
	exp = NULL;
	while (ft_strlen((*list)->expo) != 11)
		(*list)->expo = ft_strjoinfree("0", (*list)->expo, 2);
	while (i >= 0)
	{
		if ((*list)->expo[i] == '1')
			tmp += ft_pow(2, j);
		j++;
		i--;
	}
	tmp -= 1023;
	if (tmp <= 0)
	{
		tmp = ft_pow(2, tmp);
		exp = ft_ld_in_str(tmp, 0);
	}
	else
		exp = ft_pow_to_str((long)tmp);
	ft_strdel(&(*list)->expo);
	return (exp);
}

char		*ft_get_mant(t_ftoa **list)
{
	int			i;
	int			j;
	long double	tmp;
	char		*mant;

	i = 0;
	j = -1;
	tmp = 0;
	mant = NULL;
	while (ft_strlen((*list)->mant) != 52)
		(*list)->mant = ft_strjoinfree("0", (*list)->mant, 2);
	while ((*list)->mant[i])
	{
		if ((*list)->mant[i] == '1')
			tmp += ft_pow(2, j);
		j--;
		i++;
	}
	mant = ft_ld_in_str(tmp, 1);
	ft_strdel(&(*list)->mant);
	return (mant);
}

char	*ft_get_bin(void *oct, int size)
{
	int		i;
	int		j;
	char	*str;
	char	*ptr;

	if (!(str = ft_memalloc(sizeof(char) * (size * 8) + 1)))
		return (NULL);
	ptr = (char*)oct;
	i = 8;
	j = size;
	while (j--)
	{
		i = 8;
		while (i--)
			str[(j * 8) + 8 - (i + 1)] = (*ptr >> i & 1) + '0';
		ptr++;
	}
	str[size * 8] = '\0';
	return (str);
}
