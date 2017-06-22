#include <stdio.h>
#include <stdlib.h>
#include "../include/my_complex.h"

void enter_data(my_complex *x, my_complex *y)
{

        printf("\nEnter real and image part of the first number:\t");
        scanf("%lf %lf", &x->real, &x->image);
        printf("Enter real and image part of the second number:\t");
        scanf("%lf %lf", &y->real, &y->image);
}

