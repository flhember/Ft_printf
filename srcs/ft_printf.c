/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 13:47:44 by flhember          #+#    #+#             */
/*   Updated: 2019/04/11 13:24:41 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(char *str, ...)
{
	va_list		ap;
	t_conv		*list;
	char		**tab;
	long long	size_tab;

	tab = NULL;
	list = NULL;
	if (str == NULL)
		return (-1);
	va_start(ap, str);
	ft_creatlst(&list);
	tab = ft_set_tab(str, tab);
	tab = ft_convert_param(tab, &list, ap);
	va_end(ap);
	size_tab = ft_print_tab(tab);
	ft_free_list(&list);
	if (tab)
		ft_free_tab(tab);
	return (size_tab);
}
