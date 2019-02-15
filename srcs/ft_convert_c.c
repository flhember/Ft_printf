/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:32:16 by flhember          #+#    #+#             */
/*   Updated: 2019/02/07 15:49:07 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
//#include "../Libft/includes/libft.h"
#include <stdio.h>

static char	*ft_width_min(char *str, char var)
{
	size_t	nb_space;
	size_t	i;
	char	*tmp;

	i = 0;
	str++;
	nb_space = ft_atoi(str);
	if (!(tmp = (char*)malloc(sizeof(char) * (nb_space + 1))))
		return (0);
	while (i < nb_space)
	{
		tmp[i] = ' ';
		i++;
	}
	tmp[i - 1] = var;
	tmp[i] = '\0';
	return (tmp);
}

char		*ft_convert_c(void *var, char *str)
{
	int		i;

	i = 1;
	if (str[i] == 'c' && i == 1)
	{
		str[0] = (char)var;
		str[1] = '\0';
		return (str);
	}
	return (ft_width_min(str, (char)var));
}
