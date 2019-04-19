/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:59:41 by flhember          #+#    #+#             */
/*   Updated: 2019/04/11 13:27:39 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*ft_check_percent(char *str)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == '%')
		{
			tmp = ft_strsub(str, 0, i);
			tmp2 = ft_strsub(str, i + 1, ft_strlen(str) - i);
			str = ft_strjoinfree(tmp, tmp2, 3);
		}
		i++;
	}
	return (str);
}

long long		ft_print_tab(char **tab)
{
	int			i;
	long long	size_tab;

	size_tab = 0;
	i = 0;
	while (tab[i])
	{
		tab[i] = ft_check_percent(tab[i]);
		if (ft_strcmp(tab[i], "%c") == 0)
		{
			ft_putchar('\0');
			size_tab--;
		}
		else
			ft_putstr(tab[i]);
		size_tab += ft_strlen(tab[i]);
		i++;
	}
	return (size_tab);
}
