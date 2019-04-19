#include "includes/ft_printf.h"
#include <float.h>
#include <math.h>

int 	main()
{
	int s1;
	int s2;
	double f = 23.23; // 9.9999 prec .

	printf("f = %.100lf\n", 0);
	ft_printf("m = %.100lf\n", 0);

	/*ft_printf("Okalmos : %c %.0d %.0x, %d|\n", 'A', 1235, 0, 56985);
	printf("Okalmos : %c %.0d %.0x, %d|\n", 'A', 1235, 0, 56985);

    s1 = ft_printf("asd%c", 0);
	s2 = printf("asd%c", 0);

	ft_printf("|\n");
	printf("|\n");

	printf("moi = %d, vrais = %d\n", s1, s2);*/

//	printf("salut " "ca " "va?");
//	ft_printf( RED "salut "GRN "ca " "va?" RESET);


	return (0);
}
