/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 16:31:01 by flhember          #+#    #+#             */
/*   Updated: 2019/03/13 17:17:57 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <libft.h>

#include <stdio.h>

char			*ft_ftoa(long double n)
{
	float tmp;
	long int	dec;
	char		*str;

	str = NULL;
	dec = n;
	tmp = n - dec;
	//tmp = (int)n;
	printf("tmp = %f\n", tmp);
	printf("test = %.20f\n", 23.2323);
	return (str);
}

int 		main()
{
	float 	f = 23.2323;
	char	*str;
	
	printf("test = %.50f\n", 23.2323);
	printf("f = %s\n", ft_ftoa(f));

	return (0);
}
