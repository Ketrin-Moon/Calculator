#include <stdio.h>
#include <stdlib.h>
#include "my_complex.h"

void enter_data(struct my_complex *x, struct my_complex *y)
{

	printf("\nEnter real and image part of the first number:\t");
        scanf("%d %d", &x->real, &x->image);
	printf("Enter real and image part of the second number:\t");
        scanf("%d %d", &y->real, &y->image);
}

void print_result(int res_real, int res_image)
{
	if(res_image > 0)
		printf("\n\nResult:\t%d+%di\n", res_real, res_image);
	else
		printf("\n\nResult:\t%d%di\n", res_real, res_image);

}
void add(struct my_complex *x, struct my_complex *y)
{
	struct my_complex *result = malloc(sizeof(int));

	result->real = x->real + y->real;
	result->image = x->image + x->image;

	print_result(result_real, result_image);
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
