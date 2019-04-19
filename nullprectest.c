/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nullprectest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:48:50 by flhember          #+#    #+#             */
/*   Updated: 2019/04/10 17:34:45 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int main()
{
	float		nb;
	nb = 0;
	ft_printf("null prec : %+.0f\n", nb);
	dprintf(2, "null prec : %+.0f\n", nb);
	nb = 12.5;
	ft_printf("null prec : %+.0f\n", nb);
	dprintf(2, "null prec : %+.0f\n", nb);
	nb = -25632.2541;
	ft_printf("null prec : %+.0f\n", nb);
	dprintf(2, "null prec : %+.0f\n", nb);
	nb = -1.0123;
	ft_printf("null prec : %+.0f\n", nb);
	dprintf(2, "null prec : %+.0f\n", nb);
	nb = 12354.569874;
	ft_printf("null prec : %+.0f\n", nb);
	dprintf(2, "null prec : %+.0f\n", nb);

	return (0);
}
