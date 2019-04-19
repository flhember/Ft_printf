/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:32:16 by flhember          #+#    #+#             */
/*   Updated: 2019/04/11 13:24:19 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_filling(char var, t_option **list)
{
	size_t	i;
	char	*str;

	i = 0;
	if ((*list)->min)
		str = ft_strnewspace((*list)->min);
	else
		str = ft_memalloc(2);
	if ((*list)->minus)
	{
		str[0] = var;
		return (str);
	}
	else if ((*list)->zero)
	{
		while (i < (*list)->min)
			str[i++] = '0';
		str[i - 1] = var;
	}
	else
	{
		i = ft_strlen(str);
		str[i - 1] = var;
	}
	return (str);
}

char		*ft_convert_c(va_list ap, char *str)
{
	t_option	*list;
	int			tmp;

	list = NULL;
	tmp = va_arg(ap, int);
	if (tmp == 0)
		return (ft_strdup("%c"));
	if (str[1] == 'c')
	{
		ft_strdel(&str);
		if (!(str = ft_memalloc(2)))
			return (NULL);
		str[0] = tmp;
		return (str);
	}
	list = ft_get_option(str);
	ft_strdel(&str);
	str = ft_filling(tmp, &list);
	ft_free_option(&list);
	return (str);
}
