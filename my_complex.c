#include <stdio.h>
#include <stdlib.h>
#include "my_complex.h"

void enter_data(my_complex *x, my_complex *y)
{

	printf("\nEnter real and image part of the first number:\t");
        scanf("%d %d", &x->real, &x->image);
	printf("Enter real and image part of the second number:\t");
        scanf("%d %d", &y->real, &y->image);
}

void print_result(my_complex *result)
{
	if(result->image > 0)
		printf("\n\nResult:\t%d+%di\n", result->real, result->image);
	else
		printf("\n\nResult:\t%d%di\n", result->real, result->image);

}

my_complex* add(my_complex *x, my_complex *y)
{
	my_complex *result = malloc(sizeof(my_complex));

	result->real = x->real + y->real;
	result->image = x->image + y->image;

	print_result(result);

	return result;
}

my_complex* sub(my_complex *x, my_complex *y)
{
	my_complex *result = malloc(sizeof(my_complex));

	result->real = x->real - y->real;
	result->image = x->image - y->image;

	print_result(result);

	return result;
}
my_complex* mul(my_complex *x, my_complex *y)
{
	my_complex *result = malloc(sizeof(my_complex));

	result->real = x->real * y->real - x->image * y->image;
	result->image = x->real * y->image + x->image * y->real;

	print_result(result);

	return result;
}

