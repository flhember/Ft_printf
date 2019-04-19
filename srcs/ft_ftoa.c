/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 18:12:12 by flhember          #+#    #+#             */
/*   Updated: 2019/04/19 13:22:33 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <math.h>
#include <float.h>
#include <limits.h>

void	ft_cut_bin_64(t_ftoa **list)
{
	(*list)->signe = (int)(*list)->bin[0] - 48;
	(*list)->expo = ft_strsub((*list)->bin, 1, 11);
	(*list)->mant = ft_strsub((*list)->bin, 12, 52);
	ft_strdel(&(*list)->bin);
}

char	*ft_nan_inf(t_ftoa **list)
{
	char	*str;
	size_t		i;

	i = 0;
	str = NULL;
	while ((*list)->expo[i] == '1')
		i++;
	if (i == ft_strlen((*list)->expo))
	{
		i = 0;
		if ((*list)->signe == 0)
			str = ft_strdup("inf");
		else if ((*list)->signe == 1)
			str = ft_strdup("-inf");
		while ((*list)->mant[i] == '0')
			i++;
		if (i < ft_strlen((*list)->mant) - 1)
		{
			free(str);
			str = ft_strdup("nan");
		}
	}
	if (str != NULL)
		ft_free_ftoa(list);
	return (str);
}

char	*ft_zero_prec(char *str, int i)
{
	char	*str_cpy;
	int		j;
	int		k;

	j = 0;
	k = ft_strlen(str) - 1;
	str_cpy = ft_strdup(str);
	while (str[j] != '.')
		j++;
	k -= j;
	while (k++ < i)
		str_cpy = ft_strjoinfree(str_cpy, "0", 1);
	ft_strdel(&str);
	return (str_cpy);
}

char	*ft_ftoa_64(double f, int prec, int hash)
{
	t_ftoa	*list;
	char	*str;
	int		vir;

	str = NULL;
	if (!(list = malloc(sizeof(t_ftoa))))
		return (NULL);
	list->bin = ft_get_bin(&f, sizeof(f));
	ft_cut_bin_64(&list);
	if ((str = ft_nan_inf(&list)) != NULL)
		return (str);
	list->mant = ft_get_mant(&list);
	list->expo = ft_get_expo(&list);
	vir = ft_size_vir(f);
	list->signe = list->signe == 1 ? -1 : 1;
	str = ft_mult_str(list->mant, list->expo);
	str = ft_put_point(str, vir);
//	if (hash || (prec != -1 && prec != 0))
//		str = ft_check_size(str);
	str = ft_cut_prec(str, prec, vir, hash);
	if ((long)(ft_strlen(str) - vir) < prec)
		str = ft_zero_prec(str, prec);
	if (list->signe == -1)
		str = ft_strjoinfree("-", str, 2);
	ft_free_ftoa(&list);
	return (str);
}
/*
#include <float.h>
#include <limits.h>

int		main()
{
	double	f = DBL_MIN;
	char	*str;

	printf("f   = %.5000lf\n", f);
	str = ft_ftoa_64(f, 100, 0);
	printf("str = %s\n", str);
	return (0);
}*/
