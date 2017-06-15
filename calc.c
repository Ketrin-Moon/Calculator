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

	printf("\n\nWhat operation do you want to perfome?\nChoose 1 - 5:\n1. Add\n2. Sub\n3. Mul\n4. Div\n5. Quit\n");
	user_char = getchar();
	while(1){
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
		}

		printf("Want to get out? [Yes - 1/No - 0]\n");
		scanf("%c", &ch);
		if(ch == 1)
		    exit(0);
	}

	return 0;
}
