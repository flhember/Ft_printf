/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest_infnan.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:18:25 by flhember          #+#    #+#             */
/*   Updated: 2019/04/18 15:41:16 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int main()
{
	double		nb;

    nb = 1.0/0.0;
	printf("--- 1.0/0.0 ---\n");
	ft_printf("m = %f|\n", nb);
	printf("l = %f|\n", nb);
	ft_printf("m = %12f|\n", nb);
	printf("l = %12f|\n", nb);
	ft_printf("m = %-12f|\n", nb);
	printf("l = %-12f|\n", nb);
	ft_printf("m = %5.9f|\n", nb);
	printf("l = %5.9f|\n", nb);

    nb = -1.0/0.0;
	printf("--- -1.0/0.0 ---\n");
	ft_printf("%f\n", nb);
	printf("%f\n", nb);
	ft_printf("%12f\n", nb);
	printf("%12f\n", nb);
	ft_printf("%-12f\n", nb);
	printf("%-12f\n", nb);
	ft_printf("%5.9f\n", nb);
	printf("%5.9f\n", nb);

	nb = 0.0/0.0;
	ft_printf("%f\n", nb);
	dprintf(2,"%f\n", nb);
	ft_printf("%12f\n", nb);
	dprintf(2,"%12f\n", nb);
	ft_printf("%-12f\n", nb);
	dprintf(2,"%-12f\n", nb);
	ft_printf("%5.9f\n", nb);
	dprintf(2,"%5.9f\n", nb);

	return (0);
}
