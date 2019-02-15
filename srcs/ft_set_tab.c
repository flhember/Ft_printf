/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_and_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:52:40 by flhember          #+#    #+#             */
/*   Updated: 2019/02/07 15:50:21 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

static int	nb_word(char *str, size_t i)
{
	int		nb;

	nb = 0;
	while (str[i] && i < ft_strlen(str))
	{
		if (str[i] != '%' || (str[i] == '%' && str[i + 1] == '%'))
		{
			nb++;
			while ((str[i] != '%' && str[i]) ||
					(str[i] == '%' && str[i + 1] == '%'))
			{
				if (str[i] == '%' && str[i + 1] == '%')
					i++;
				i++;
			}
		}
		if (str[i] == '%')
			nb++;
		while (str[i] && str[i] != 'c' && str[i] != 's' && str[i] != 'p' &&
				str[i] != 'd' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u'
				&& str[i] != 'x' && str[i] != 'X' && str[i] != 'f')
			i++;
		i++;
	}
	return (nb);
}

static int	*nb_letter(char *str, int k, int *nb_letter, size_t i)
{
	int		j;

	i = -1;
	while (str[++i] && i < ft_strlen(str))
	{
		j = i;
		if (str[i] != '%' || (str[i] == '%' && str[i + 1] == '%'))
		{
			while ((str[i] != '%' && str[i]) ||
					(str[i] == '%' && str[i + 1] == '%'))
			{
				if (str[i] == '%' && str[i + 1] == '%')
					i++;
				i++;
			}
			nb_letter[k++] = i - j;
			j = i;
		}
		while (str[i] && str[i] != 'c' && str[i] != 's' && str[i] != 'p' &&
				str[i] != 'd' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u'
				&& str[i] != 'x' && str[i] != 'X' && str[i] != 'f')
			i++;
		nb_letter[k++] = (i - j) + 1;
	}
	return (nb_letter);
}

static char	**ft_filling(char *str, char **tab, int k, size_t i)
{
	int		j;

	i = -1;
	while (str[++i] && i < ft_strlen(str))
	{
		j = i;
		if (str[i] != '%' || (str[i] == '%' && str[i + 1] == '%'))
		{
			while ((str[i] != '%' && str[i]) ||
					(str[i] == '%' && str[i + 1] == '%'))
			{
				if (str[i] == '%' && str[i + 1] == '%')
					i++;
				i++;
			}
			tab[k++] = ft_strsub(str, j, (i - j));
			j = i;
		}
		while (str[i] && str[i] != 'c' && str[i] != 's' && str[i] != 'p' &&
				str[i] != 'd' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u'
				&& str[i] != 'x' && str[i] != 'X' && str[i] != 'f')
			i++;
		tab[k++] = ft_strsub(str, j, (i - j) + 1);
	}
	return (tab);
}

static char	**ft_alloc(char **tab_final, int *tab, int size)
{
	int		j;
	int		i;

	i = 0;
	j = 0;
	if (!(tab_final = (char**)malloc(sizeof(char*) * (size + 1))))
		return (0);
	while (i < size - 1)
	{
		if (!(tab_final[i] = (char*)malloc(sizeof(char) * (tab[i]))))
			return (0);
		i++;
	}
	return (tab_final);
}

char		**ft_set_tab(char *str, char **tab_final)
{
	int		*tab;
	int		size;
	int		k;
	size_t	i;

	i = 0;
	k = 0;
	tab = NULL;
	size = nb_word(str, i);
	if (!(tab = (int*)malloc(sizeof(int) * (size + 1))))
		return (0);
	tab = nb_letter(str, k, tab, i);
	tab_final = ft_alloc(tab_final, tab, size);
	tab_final = ft_filling(str, tab_final, k, i);
	tab_final[size] = NULL;
	free(tab);
	return (tab_final);
}
