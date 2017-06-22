#include <stdio.h>
#include <stdlib.h>
#include "../include/my_complex.h"

void print_result(my_complex *result)
{
        if(result->image > 0)
                printf("\n\nResult:\t%.3f + %.3fi\n", result->real, result->image);
        else
                printf("\n\nResult:\t%.3f %.3fi\n", result->real, result->image);
}

