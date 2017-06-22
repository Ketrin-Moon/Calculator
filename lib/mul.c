#include <stdio.h>
#include <stdlib.h>
#include "../include/my_complex.h"

char function[10] = "Mul";

my_complex* mul(my_complex *x, my_complex *y)
{
        my_complex *result = malloc(sizeof(my_complex));

        result->real = x->real * y->real - x->image * y->image;
        result->image = x->real * y->image + x->image * y->real;

        return result;
}

