/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creatlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:12:25 by flhember          #+#    #+#             */
/*   Updated: 2019/02/07 15:49:45 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
//#include "../Libft/includes/libft.h"
#include <stdio.h>

static t_conv	*ft_creat_maillon(char c, char *(*ft)(void *var, char *str))
{
	t_conv	*new;

	new = NULL;
	if (!(new = (t_conv*)malloc(sizeof(t_conv))))
		return (NULL);
	new->type = c;
	new->f = ft;
	new->next = NULL;
	return (new);
}

static void		ft_add_maillon(t_conv **list, t_conv *new)
{
	new->next = *list;
	*list = new;
}

void			ft_creatlst(t_conv **list)
{
	t_conv	*tmp;

	tmp = ft_creat_maillon('c', &ft_convert_c);
	ft_add_maillon(list, tmp);
	tmp = ft_creat_maillon('s', &ft_convert_s);
	ft_add_maillon(list, tmp);
	tmp = ft_creat_maillon('p', &ft_convert_p);
	ft_add_maillon(list, tmp);
	tmp = ft_creat_maillon('i', &ft_convert_i_d);
	ft_add_maillon(list, tmp);
	tmp = ft_creat_maillon('d', &ft_convert_i_d);
	ft_add_maillon(list, tmp);
}
