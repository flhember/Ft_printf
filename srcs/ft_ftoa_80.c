/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa_80.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:26:50 by flhember          #+#    #+#             */
/*   Updated: 2019/04/17 18:37:43 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <math.h>
#include <float.h>

char		*ft_get_expo_80(t_ftoa **list)
{
	int			i;
	int			j;
	long double	tmp;
	char		*exp;

	i = 14;
	j = 0;
	tmp = 0;
	while (ft_strlen((*list)->expo) != 15)
		(*list)->expo = ft_strjoinfree("0", (*list)->expo, 2);
	while (i >= 0)
	{
		if ((*list)->expo[i] == '1')
			tmp += ft_pow(2, j);
		j++;
		i--;
	}
	tmp -= 16383;
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

char		*ft_get_mant_80(t_ftoa **list)
{
	int			i;
	int			j;
	long double	tmp;
	char		*mant;

	i = 0;
	j = 0; //-1
	tmp = 0;
	mant = NULL;
	while (ft_strlen((*list)->mant) != 64)
		(*list)->mant = ft_strjoinfree("0", (*list)->mant, 2);
	while ((*list)->mant[i])
	{
		if ((*list)->mant[i] == '1')
			tmp += ft_pow(2, j);
		j--;
		i++;
	}
	mant = ft_ld_in_str(tmp, 0);
	ft_strdel(&(*list)->mant);
	return (mant);
}

void	ft_cut_bin_80(t_ftoa **list)
{
	(*list)->signe = (int)(*list)->bin[0] - 48;
	(*list)->expo = ft_strsub((*list)->bin, 1, 15);
	(*list)->mant = ft_strsub((*list)->bin, 16, 64);
	ft_strdel(&(*list)->bin);
}

char	*ft_ftoa_80(long double f, int prec, int hash)
{
	t_ftoa	*list;
	char	*str;
	int		vir;

	str = NULL;
	vir = ft_size_vir(f);
	if (!(list = malloc(sizeof(t_ftoa))))
		return (NULL);
	list->bin = ft_get_bin(&f, 10);
	ft_cut_bin_80(&list);
	list->mant = ft_get_mant_80(&list);
	list->expo = ft_get_expo_80(&list);
	list->signe = list->signe == 1 ? -1 : 1;
	str = ft_mult_str(list->mant, list->expo);
	str = ft_put_point(str, vir);
	if (hash || (prec != -1 && prec != 0))
		str = ft_check_size(str);
	str = ft_cut_prec(str, prec, vir, hash);
	if (list->signe == -1)
		str = ft_strjoinfree("-", str, 2);
	ft_free_ftoa(&list);
	return (str);
}
/*
int		main()
{
	long double	f = LDBL_MAX;
	char	*str;

	printf("f   = %.100Lf\n", f);
	str = ft_ftoa_80(f, 100, 0);
	printf("str = %s\n", str);
	return (0);
}*/
