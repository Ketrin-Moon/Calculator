#include <stdio.h>
#include <stdlib.h>
#include "../include/my_complex.h"

char function[10] = "Add";

my_complex* Add(my_complex *x, my_complex *y)
{
	printf("Add\n");
        my_complex *result = malloc(sizeof(my_complex));

        result->real = x->real + y->real;
        result->image = x->image + y->image;

        return result;
}

