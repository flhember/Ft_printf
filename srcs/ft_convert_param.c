/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_param.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 12:22:17 by flhember          #+#    #+#             */
/*   Updated: 2019/02/15 13:07:35 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
//#include "../Libft/includes/libft.h"
#include <stdio.h>

char	**ft_convert_param(char **tab, t_conv **list, va_list ap)
{
	int		i;
	int		j;
	t_conv	*tmp;

	tmp = *list;
	i = 0;
	j = 0;
	while (tab[j])
	{
		if (tab[j][0] == '%' && tab[j][1] != '%')
		{
			while (tmp)
			{
				if (tmp->type == tab[j][(ft_strlen((tab[j]))) - 1])
					tab[j] = tmp->f(va_arg(ap, void*), tab[j]);
				tmp = tmp->next;
			}
			tmp = *list;
		}
		j++;
	}
	va_end(ap);
	return (tab);
}
