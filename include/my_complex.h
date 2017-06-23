#ifndef MY_COMPLEX_H_
#define MY_COMPLEX_H_

/** Структура, описывающая вид комплексного числа, его реальную и мнимую части
*/

typedef struct MyComplex{
	double real;	/**< реальная часть комплексного числа*/
	double image;	/**< мнимая часть комплексного числа*/
} my_complex;

/** Прототип функции enter_data, которая позволяет пользователю вводить данные
в программу
*/

void enter_data(my_complex *x, my_complex *y);

/** Прототип функции open, которая считывает функции, доступные для выполнения
калькулятору
*/

void open(char** filenames, int count, char* path);

/** Прототип функции direct, которая считывает имена библиотек, хранящихся
в директории
*/

char** direct(char *dp, int* count);

#endif
