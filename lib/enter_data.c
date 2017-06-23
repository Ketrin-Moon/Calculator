#define _SVID_SOURCE
#include <stdlib.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <curses.h>
#include <stdio.h>
#include <malloc.h>
#include <dirent.h>
#include <string.h>
#include <dlfcn.h>
#include "../include/my_complex.h"

/**
@function enter_data
Функция, осуществляющая ввод пользовательских данных с клавиатуры.
@param my_comple *x - параметр, который передает указатель на структуру x типа
my_complex. Из этой переменной получаем реальную(real) и мнимую(image) часть
числа
@param my_complex *y - параметр, который передает указатель на структуру y типа
my_complex. Из этой переменной получаем реальную(real) и мнимую(image) часть
числа
*/

void enter_data(my_complex *x, my_complex *y)
{
        printf("\nEnter real and image part of the first number:\t");
        scanf("%lf %lf", &x->real, &x->image);
        printf("Enter real and image part of the second number:\t");
        scanf("%lf %lf", &y->real, &y->image);
}

/**
@function open
Функция, открывающая доступные библиотеки, в которых содержатся операции,
доступные в калькуляторе. Доступные функции отображаются на экране. С
помощью клавиш можно выбрать операцию, которую необходимо выполнить.
@param filenames - параметр, передающий все библиотеки, находящиеся в
директории
@param count - параметр, отвечающий за количество библиотек в директории
@param path - параметр, в котором содержится путь до директории
*/

void open(char** filenames, int count, char* path)
{
        int i;
        char *buf, user_char;
        void *lib;
        char **ptr;

        my_complex *x = malloc(sizeof(my_complex));
        my_complex *y = malloc(sizeof(my_complex));
        my_complex *result = malloc(sizeof(my_complex));

        my_complex* (*pointers[10])(my_complex *, my_complex *);

        ptr = malloc(sizeof(char*) * 10);

        for(i = 1; i < count; i++){
                buf = calloc(100, sizeof(int)*255);
                ptr[i] = malloc(255);
                pointers[i] = malloc(8);
                strcat(buf, path);
                strcat(buf, "/");
		strcat(buf, filenames[i]);
                lib = dlopen(buf, RTLD_NOW);
                if(!lib){
                        fprintf(stderr, "dlopen() error: %s\n", dlerror ());
                        exit(1);
                }
                ptr[i] = dlsym(lib, "function");
                pointers[i] = (my_complex* (*)(my_complex* , my_complex*))dlsym(lib, ptr[i]);
                free(buf);
        }
        while(1){
                for(i = 1; i < count; i++)
                        printf("%d\t%s\n", i, ptr[i]);
                printf("%d\tOuit\n", i);
                user_char = getchar();
		switch(user_char){
                        case '1':
                                enter_data(x, y);
                                result = (pointers[1])( x, y);
                                printf("result: %.1f %.1f\n", result->real, result->image);
                                break;
                        case '2':
                                enter_data(x, y);
                                result = (pointers[2])( x, y);
                                printf("result: %.1f %.1f\n", result->real, result->image);
                                break;
                        case '3':
                                enter_data(x, y);
                                result = (pointers[3])( x, y);
                                printf("result: %.1f %.1f\n", result->real, result->image);
                                break;
                        case '4':
                                enter_data(x, y);
                                result = (pointers[4])( x, y);
                                printf("result: %.1f %.1f\n", result->real, result->image);
                                break;
                        case '5':
                                exit(0);
                }
                user_char = getchar();
        }
	dlclose(lib);
}

/**
@function direct
Функция, которая считывает имена библиотек, находящихся в заданной директории.
Сохраняет их в массив в лексикографическом порядке.
@param dp - параметр, в котором содержится путь до директории
@param count - параметр, подсчитывающий сколько библиотек находится в
директории
@return возвращает массив имен библиотек(filenames)
*/

char** direct(char *dp, int *count)
{
        struct dirent **entry;
        char **filenames;
        int i;

        (*count) = 0;
        (*count) = scandir(dp, &entry, 0, alphasort);
        filenames = (char**)malloc(sizeof(char*)*(*count));
        for(i = 1; i < (*count); ++i){
                filenames[i - 1] = malloc(255);
                strcpy(filenames[i - 1], entry[i]->d_name);
	 }
        (*count)--;
        return filenames;
}

