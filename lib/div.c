#include <stdio.h>
#include <stdlib.h>
#include "../include/my_complex.h"

/** Эта переменная содержит строку, описывающую функцию, которая выполняется
в программе. Это нужно для того, чтобы при запуске калькулятора определить
какие функции доступны калькулятору для выполнения.
*/

char function[10] = "Divi";

/**
@function Divi
Функция, которая осуществляет деление одного комплексного числа на другое.
@param my_comple *x - параметр, который передает указатель на структуру x типа
my_complex. Из этой переменной получаем реальную(real) и мнимую(image) часть
числа
@param my_complex *y - параметр, который передает указатель на структуру y типа
my_complex. Из этой переменной получаем реальную(real) и мнимую(image) часть
числа
@return возвращает результат выполненной операции(result)
*/

my_complex* Divi(my_complex *x, my_complex *y)
{
        my_complex *result = malloc(sizeof(my_complex));
        my_complex *var = malloc(sizeof(my_complex));

        var->real = y->real;
        var->image = -y->image;

        x->real = x->real * var->real - x->image * var->image;
	x->image = x->real * var->image + x->image * var->real;
        y->real = y->real * var->real - y->image * var->image;
	y->image = y->real * var->image + y->image * var->real;

        if(y->real){
                result->real = x->real/y->real;
                result->image = x->image/y->real;
        }
        if(y->image){
                result->real = x->real/y->image;
                result->image = x->image/y->real;
        }

        return result;
}

