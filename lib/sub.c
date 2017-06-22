#include <stdio.h>
#include <stdlib.h>
#include "../include/my_complex.h"

char function[10] = "Sub";

my_complex* sub(my_complex *x, my_complex *y)
{
        my_complex *result = malloc(sizeof(my_complex));

        result->real = x->real - y->real;
        result->image = x->image - y->image;

//        print_result(result);

        return result;
}

