#include <stdio.h>
#include <stdlib.h>
#include "my_complex.h"

int main()
{
	int user_char, ch;
	struct my_complex *x = malloc(sizeof(int));
	struct my_complex *y = malloc(sizeof(int));

	while(1){
		printf("\n\nWhat operation do you want to perfome?\nChoose 1 - 5:\n1. Add\n2. Sub\n3. Mul\n4. Div\n5. Quit\n");
		user_char = getchar();
		switch(user_char){
			case '1':
				enter_data(x,y);
				add(x,y);
			case '5':
				return 0;

		}
	/*	if(user_char == 1)
			add(x.real, x.image, y.real, y.image);
		else
			if(user_char == 2)
				sub(x.real, x.image, y.real, y.image);
			else
				if(user_char == 3)
					mul(x.real, x.image, y.real, y.image);
				else
					if(user_char == 5)
						exit(0);
	*/

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
