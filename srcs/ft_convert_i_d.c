/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_c_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 15:10:23 by flhember          #+#    #+#             */
/*   Updated: 2019/02/15 16:50:36 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int		ft_intlen(void *n)
{
	int		size;

	size = 1;
	if (n < 0)
	{
		n = -n;
		size++;
	}
	while (n > 9)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_malloc_size(void *var, t_option **list)
{
	char	*str;
	size_t	i;
	int		size_malloc;
	char	*tmp;

	i = 0;
	if ((*list)->min > (*list)->prec && (*list)->min > ft_intlen((int)var))
	{
		printf("malloc de taille min\n");
		size_malloc = (*list)->min;
	}
	else if ((*list)->prec > (*list)->min && (*list)->prec > ft_intlen((int)var))
	{
		printf("malloc de taille prec\n");
		size_malloc = (*list)->prec;
	}
	else
		size_malloc = ft_intlen((int)var);
	if ((*list)->plus > 0 || (*list)->space > 0 || (int)var < 0)
		size_malloc++;
	if (!(str = (char*)malloc(sizeof(char) * (size_malloc + 1))))
		return (NULL);
	str[size_malloc + 1] = '\0';
	i = 0;
	tmp = ft_itoa((int)var);
	while (i < size_malloc)
	{
		str[i] = tmp[i];
		i++;
	}
	printf("str = %s\n", str);
	printf("size malloc = %d\n", size_malloc);
	return (str);
}

char	*ft_convert_i_d(void *var, char *str)
{
	t_option	*list;
	int		i;
	int		size_var;

	i = 1;
	list = NULL;
	if ((str[i] == 'i' || str[i] == 'd') && i == 1)
	{
		str = ft_itoa((int)var);
		return (str);	
	}
	list = ft_get_option(str);
	if (!list->size)
		str = ft_malloc_size((int*)var, &list);
	else if (list->size[0] == 'l')
	{
//		if (list->size[1] && list->size[1] == 'l')
//			str = ft_malloc_size((long long*)var, &list);
//			else
			str = ft_malloc_size((long*)var, &list);
	}
//	else if (list->size[0] == 'h')
//	{
		//if (list->size[1] == 'h')
		//	str = ft_malloc_size((char*)var, &list);
//		else
//			str = ft_malloc_size((short*)var, &list);
//	}
	printf("list prec = %d\n", list->prec);
	printf("list size = %s\n", list->size);
	printf("list option = %s\n", list->option);
	printf("list min = %d\n", list->min);
	printf("list plus = %d\n", list->plus);
	printf("list minus = %d\n", list->minus);
	printf("list hash = %d\n", list->hash);
	printf("list space = %d\n", list->space);
	printf("list zero = %d\n", list->zero);
	printf("%d\n", (int)var);
	printf("|%s|\n", str);
	free(list->size);
	free(list);
	return (str);
}
