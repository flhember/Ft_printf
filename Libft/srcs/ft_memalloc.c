/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:06:32 by flhember          #+#    #+#             */
/*   Updated: 2019/01/24 15:53:37 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memalloc(size_t size)
{
	void	*mem;

	mem = NULL;
	if (!(mem = (void *)malloc(sizeof(void) * size)))
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}
