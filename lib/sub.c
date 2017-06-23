#include <stdio.h>
#include <stdlib.h>
#include "../include/my_complex.h"

/** Эта переменная содержит строку, описывающую функцию, которая выполняется
в программе. Это нужно для того, чтобы при запуске калькулятора определить
какие функции доступны калькулятору для выполнения.
*/

char function[10] = "Sub";

/**
@function Sub
Функция, которая вычитает одно комплексное число из другого.
@param my_comple *x - параметр, который передает указатель на структуру x типа
my_complex. Из этой переменной получаем реальную(real) и мнимую(image) часть
числа
@param my_complex *y - параметр, который передает указатель на структуру y типа
my_complex. Из этой переменной получаем реальную(real) и мнимую(image) часть
числа
@return возвращает результат выполненной операции(result)
*/

my_complex* Sub(my_complex *x, my_complex *y)
{
        my_complex *result = malloc(sizeof(my_complex));

        result->real = x->real - y->real;
        result->image = x->image - y->image;

        return result;
}

