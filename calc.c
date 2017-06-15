#include <stdio.h>
#include <stdlib.h>
#include "my_complex.h"

int main()
{
	char user_char;
	char ch;

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
			case '2':
				fflush(NULL);
				enter_data(x, y);
				result = sub(x,y);
			case '3':
				fflush(NULL);
				enter_data(x, y);
				result = mul(x, y);
			case '4':
				fflush(NULL);
				enter_data(x, y);
				result = my_div(x, y);
				printf("\nResult:\t %.1lf%.1lfi\n", result->real, result->image);
			case '5':
				return 0;
		}

		printf("Want to get out? [Yes - 1/No - 0]\n");
		scanf("%c", &ch);
		if(ch == 1)
		    exit(0);
		else
			continue;
	}

	return 0;
}
