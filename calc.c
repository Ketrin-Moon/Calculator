#include <stdio.h>
#include <stdlib.h>
#include "my_complex.h"

int main()
{
	int user_char, ch;
	struct my_complex x, y;

	while(user_char != 5){

		printf("\nEnter real and image part of the first number:\t");
		scanf("%d %d", &x.real, &x.image);
		printf("Enter real and image part of the second number:\t");
		scanf("%d %d", &y.real, &y.image);

		system("clear");

		if((x.image < 0) && (y.image < 0))
				printf("You entered:\nX:\t%d%di\nY:\t%d%di\n", x.real, x.image, y.real, y.image);
		else{
			if(y.image < 0)
				printf("You entered:\nX:\t%d+%di\nY:\t%d%di\n", x.real, x.image, y.real, y.image);
			else{
				if(x.image < 0)
					printf("You entered:\nX:\t%d%di\nY:\t%d+%di", x.real, x.image, y.real, y.image);
				else
					printf("You entered:\nX:\t%d+%di\nY:\t%d+%di", x.real, x.image, y.real, y.image);
			}
		}

		printf("\n\nWhat operation do you want to perfome?\nChoose 1 - 5:\n1. Add\n2. Sub\n3. Mul\n4. Div\n5. Quit\n");
		scanf("%d", &user_char);
		if(user_char == 1)
			add(x.real, x.image, y.real, y.image);
		else
			if(user_char == 2)
				sub(x.real, x.image, y.real, y.image);
			else
				if(user_char == 3)
					mul(x.real, x.image, y.real, y.image);
		x.real = 0; x.image = 0; y.real = 0; y.image = 0;
		printf("\nYou want to go out? [Yes - 1/No - 0]\n");
		scanf("%d", &ch);
		if(ch == 1)
			exit(0);
		else
			continue;
		system("clear");
	}
//	switch(user_char){
//		case '1':
//			add(x.real, x.image, y.real, y.image);
//			case '2':
//				sub();
//			case '3':
//				mul();
//			case '4':
//				div();
//	}
//	}
	return 0;
}
