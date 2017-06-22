#include <stdio.h>
#include <stdlib.h>
#include "../include/my_complex.h"

char function[10] = "Div";

my_complex* my_div(my_complex *x, my_complex *y)
{
        my_complex *result = malloc(sizeof(my_complex));
        my_complex *var = malloc(sizeof(my_complex));

        var->real = y->real;
        var->image = -y->image;

        x->real = x->real * var->real - x->image * var->image;
	x->image = x->real * var->image + x->image * var->real;
        y->real = y->real * var->real - y->image * var->image;
	y->image = y->real * var->image + y->image * var->real;

        if(y->real){
                result->real = x->real/y->real;
                result->image = x->image/y->real;
        }
        if(y->image){
                result->real = x->real/y->image;
                result->image = x->image/y->real;
        }

        return result;
}

