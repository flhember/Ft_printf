/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:59:31 by flhember          #+#    #+#             */
/*   Updated: 2019/02/15 14:11:23 by flhember         ###   ########.fr       */
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

char	*ft_convert_hexa(unsigned long adr)
{
	int		i;
	char	*base;
	char	res[10];
	char	*final;

	final = NULL;
	i = 8;
	base = ft_strdup("0123456789abcdef");
	while ((adr / 16) > 0 || i >= 8)
	{
		res[i] = base[(adr % 16)];
		adr /= 16;
		i--;
	}
	res[i] = base[(adr % 16)];
	res[9] = '\0';
	final = ft_strjoin("0x", res);
	return (final);
}

char		*ft_convert_p(void *var, char *str)
{
	int				i;
	unsigned long	adr;

	adr = (unsigned long)var;
	i = 1;
	if (str[i] == 'p' && i == 1)
	{
		str = ft_convert_hexa(adr);
		return (str);
	}
	return (ft_width_min(str, ft_convert_hexa(adr)));
}
