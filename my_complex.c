#include <stdio.h>
#include <stdlib.h>
#include "my_complex.h"

void print_result(int res_real, int res_image)
{
	if(res_image > 0)
		printf("\n\nResult:\t%d+%di\n", res_real, res_image);
	else
		printf("\n\nResult:\t%d%di\n", res_real, res_image);

}
void add(int a, int aa, int b, int bb)
{
	int sum_real = a + b;
	int sum_image = aa + bb;

	print_result(sum_real, sum_image);
}

void sub(int a, int aa, int b, int bb)
{
	int sub_real = a - b;
	int sub_image = aa - bb;

	print_result(sub_real, sub_image);
}
void mul(int a, int aa, int b, int bb)
{
	int mul_real = a*b - aa * bb;
	int mul_image = a* bb + aa * b;

	print_result(mul_real, mul_image);
}
