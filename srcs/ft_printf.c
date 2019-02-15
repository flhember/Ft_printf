/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 13:47:44 by flhember          #+#    #+#             */
/*   Updated: 2019/02/15 16:50:45 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
//#include "../Libft/includes/libft.h"
#include <stdio.h>

int		ft_printf(char *str, ...)
{
	va_list		ap;
	t_conv		*list;
	char		**tab;
	int		i = 0; // a tej
	tab = NULL;
	list = NULL;
	if (str == NULL)
		return (-1);
	va_start(ap, str);
	ft_creatlst(&list);
	tab = ft_set_tab(str, tab);
	tab = ft_convert_param(tab, &list, ap);
	va_end(ap);
	while (tab[i])
	{
		ft_putstr(tab[i]);
		i++;
	}
	free_list(&list);
	return (0);
}

int 	main()
{
	char 	c = 'Y';
	char 	*s = "ouai ouai";
	char 	*d = "sws";
	int		nb = 2664;
	char	*f = "123.789";

	printf("\nsize = %d\n", printf("%20.20hd", nb));

	ft_putchar('\n');
	ft_printf("ft_printf = l'addresse du ptr est %10.20ld\n", nb);
	return (0);
}
