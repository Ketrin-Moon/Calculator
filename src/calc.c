#include <stdio.h>
#include <stdlib.h>
#include "../include/my_complex.h"

int main()
{
	char user_char;
	int ch;

	my_complex *x = malloc(sizeof(my_complex));
	my_complex *y = malloc(sizeof(my_complex));
	my_complex *result = malloc(sizeof(my_complex));

	while(1){
	    printf("\n\nWhat operation do you want to perfome?\nChoose 1 - 5:\n1. Add\n2. Sub\n3. Mul\n4. Div\n5. Quit\n");
    	    user_char = getchar();
		switch(user_char){
			case '1':
				fflush(NULL);
				enter_data(x, y);
				result = add(x, y);
				break;
			case '2':
				fflush(NULL);
				enter_data(x, y);
				result = sub(x,y);
				break;
			case '3':
				fflush(NULL);
				enter_data(x, y);
				result = mul(x, y);
				printf("\nResult:\t %.1lf %.1lfi\n", result->real, result->image);
				break;
			case '4':
				fflush(NULL);
				enter_data(x, y);
				result = my_div(x, y);
				printf("\nResult:\t %.1lf %.1lfi\n", result->real, result->image);
				break;
			case '5':
				exit(0);
		}
	user_char = getchar();
	}

	return 0;
}
