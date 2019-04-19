/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:50:51 by flhember          #+#    #+#             */
/*   Updated: 2019/04/12 17:59:28 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_convert_b(va_list ap, char *str)
{
	long double f;
	
	f = va_arg(ap, long double);
	str = ft_get_bin(&f, sizeof(f));

	return (str);
}
