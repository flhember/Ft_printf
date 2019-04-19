/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:50:29 by flhember          #+#    #+#             */
/*   Updated: 2019/04/11 14:18:52 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

static char	**ft_filling(char *str, char **tab, int k, size_t i)
{
	size_t	j;

	i = -1;
	while (++i < ft_strlen(str))
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
		if (i > j)
			tab[k++] = ft_strsub(str, j, ((i - j) + 1));
	}
	return (tab);
}

char		**ft_set_tab(char *str, char **tab_final)
{
	int		size;
	int		k;
	size_t	i;

	i = 0;
	k = 0;
	size = nb_word(str, i);
	if (!(tab_final = (char**)malloc(sizeof(char*) * (size + 1))))
		return (0);
	i = -1;
	tab_final = ft_filling(str, tab_final, k, i);
	tab_final[size] = NULL;
	return (tab_final);
}
