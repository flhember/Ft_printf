/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:49:07 by flhember          #+#    #+#             */
/*   Updated: 2019/02/07 15:49:36 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
//#include "../Libft/includes/libft.h"
#include <stdio.h>

static char	*ft_width_min(char *str, char *var)
{
	size_t	nb_space;
	size_t	i;
	char	*tmp;
	int		j;

	j = 0;
	i = 0;
	str++;
	nb_space = ft_atoi(str);
	if (nb_space <= ft_strlen(var))
		return (var);
	if (!(tmp = (char*)malloc(sizeof(char) * (nb_space))))
		return (0);
	while (i < nb_space)
	{
		tmp[i] = ' ';
		i++;
	}
	tmp[i] = '\0';
	i = i - ft_strlen(var);
	while (tmp[i])
		tmp[i++] = var[j++];
	return (tmp);
}

char		*ft_convert_s(void *var, char *str)
{
	int		i;

	i = 1;
	if (str[i] == 's' && i == 1)
	{
		str = ((char*)var);
		return (str);
	}
	return (ft_width_min(str, var));
}
