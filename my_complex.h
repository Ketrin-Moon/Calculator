#ifndef MY_COMPLEX_H_
#define MY_COMPLEX_H_

typedef struct MyComplex{
	int real;
	int image;
} my_complex;

void enter_data(my_complex *x, my_complex *y);
void print_result(my_complex *result);
my_complex* add(my_complex *x, my_complex *y);
my_complex* sub(my_complex *x, my_complex *y);
my_complex* mul(my_complex *x, my_complex *y);

#endif
