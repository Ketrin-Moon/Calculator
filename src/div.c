#include <stdio.h>
#include <stdlib.h>
#include "../include/my_complex.h"

my_complex* my_div(my_complex *x, my_complex *y)
{
        my_complex *result = malloc(sizeof(my_complex));
        my_complex *var = malloc(sizeof(my_complex));

        var->real = y->real;
        var->image = -y->image;

        x = mul(x, var);
        y = mul(y, var);

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

