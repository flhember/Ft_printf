/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 14:17:49 by flhember          #+#    #+#             */
/*   Updated: 2019/02/14 14:34:56 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc != 3)
		return 0;
	int width = atoi(argv[1]);
	int prec = atoi(argv[2]);
	printf("-----------------------NORMAL------------------------------\n");
	printf("%d\n", 12);
	printf("%d\n", -12);
	printf("%f\n", 12.123);
	printf("%f\n", -12.123);
	printf("width = %d prec = %d\n", width, prec);
	printf("------------------------WIDTH------------------------------\n");
	printf("d-----------------------POSITIF----------------------------\n");
	printf("plus  :%+*d|\n",width, 12);
	printf("space :% *d|\n",width, 12);
	printf("moins :%-*d|\n",width, 12);
	printf("0     :%0*d|\n",width, 12);
	printf("f----------------------------------------------------------\n");
	printf("plus  :%+*f|\n",width, 12.123);
	printf("space :% *f|\n",width, 12.123);
	printf("moins :%-*f|\n",width, 12.123);
	printf("0     :%0*f|\n",width, 12.123);
	printf("d-----------------------NEGATIF----------------------------\n");
	printf("plus  :%+*d|\n",width, -12);
	printf("space :% *d|\n",width, -12);
	printf("moins :%-*d|\n",width, -12);
	printf("0     :%0*d|\n",width, -12);
	printf("f----------------------------------------------------------\n");
	printf("plus  :%+*f|\n",width, -12.123);
	printf("space :% *f|\n",width, -12.123);
	printf("moins :%-*f|\n",width, -12.123);
	printf("0     :%0*f|\n",width, -12.123);
	printf("------------------------PRECISION---------------------------\n");
	printf("d-----------------------POSITIF-----------------------------\n");
	printf("plus  :%+.*d|\n",prec, 12);
	printf("space :% .*d|\n",prec, 12);
	printf("moins :%-.*d|\n",prec, 12);
	printf("0     :%0.*d|\n",prec, 12);
	printf("f----------------------------------------------------------\n");
	printf("plus  :%+.*f|\n",prec, 12.123);
	printf("space :% .*f|\n",prec, 12.123);
	printf("moins :%-.*f|\n",prec, 12.123);
	printf("0     :%0.*f|\n",prec, 12.123);
	printf("d-----------------------NEGATIF-----------------------------\n");
	printf("plus  :%+.*d|\n",prec, -12);
	printf("space :% .*d|\n",prec, -12);
	printf("moins :%-.*d|\n",prec, -12);
	printf("0     :%0.*d|\n",prec, -12);
	printf("f----------------------------------------------------------\n");
	printf("plus  :%+.*f|\n",prec, -12.123);
	printf("space :% .*f|\n",prec, -12.123);
	printf("moins :%-.*f|\n",prec, -12.123);
	printf("0     :%0.*f|\n",prec, -12.123);
	printf("------------------------DOUBLETTE---------------------------\n");
	printf("------------------------POSITIF-----------------------------\n");
	printf("plus  :%+*.*d|\n",width,prec, 12);
	printf("space :% *.*d|\n",width,prec, 12);
	printf("moins :%-*.*d|\n",width,prec, 12);
	printf("0     :%0*.*d|\n",width,prec, 12);
	printf("-----------------------------------------------------------\n");
	printf("plus  :%+*.*f|\n",width,prec, 12.123);
	printf("space :% *.*f|\n",width,prec, 12.123);
	printf("moins :%-*.*f|\n",width,prec, 12.123);
	printf("0     :%0*.*f|\n",width,prec, 12.123);
	printf("------------------------NEGATIF-----------------------------\n");
	printf("plus  :%+*.*d|\n",width,prec, -12);
	printf("space :% *.*d|\n",width,prec, -12);
	printf("moins :%-*.*d|\n",width,prec, -12);
	printf("0     :%0*.*d|\n",width,prec, -12);
	printf("-----------------------------------------------------------\n");
	printf("plus  :%+*.*f|\n",width,prec, -12.123);
	printf("space :% *.*f|\n",width,prec, -12.123);
	printf("moins :%-*.*f|\n",width,prec, -12.123);
	printf("0     :%0*.*f|\n",width,prec, -12.123);
	return 0;
}
