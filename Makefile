calculator: calc.o my_complex.o
	gcc calc.o my_complex.o -o calculator
calc.o: calc.c
my_complex: my_complex.c
