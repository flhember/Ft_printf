/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 11:56:15 by brpinto           #+#    #+#             */
/*   Updated: 2019/02/07 15:49:55 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
//#include "../Libft/includes/libft.h"

void	free_list(t_conv **list)
{
	int		j;

	j = 0;
	if ((*list)->next)
		free_list(&(*list)->next);
	free(*list);
}
