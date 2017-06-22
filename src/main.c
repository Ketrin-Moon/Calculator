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

typedef struct MyComplex{
	double real;
	double image;
} my_complex;

void enter_data(my_complex *x, my_complex *y)
{
	printf("\nEnter real and image part of the first number:\t");
	scanf("%lf %lf", &x->real, &x->image);
	printf("Enter real and image part of the second number:\t");
	scanf("%lf %lf", &y->real, &y->image);
}

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
//	pointers[1] = malloc(20);

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
		pointers[i] = dlsym(lib, ptr[i]);
//		printf("%d\n", pointers[i]);
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
				//pointers[1] = dlsym(lib, ptr[1]);
				result = (pointers[1])( x, y);
				printf("result: %.1f %.1f\n", result->real, result->image);
			case '5':
				exit(0);
		}
		user_char = getchar();
	}

	dlclose(lib);
}

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

int main()

{
	int  count = 0;
	char path[255] = "/home/2017/maklashkina/calc/Calculator/plugin";
	char **filenames = direct(path, &count);

	open(filenames, count, path);
//	char **mas_point = open(filenames, count, path);
/*	char user_char;
	char *buf;
	void *lib;

	my_complex* (*ptr[10])(my_complex , my_complex );

	my_complex *x = malloc(sizeof(my_complex)*4);
	my_complex *y = malloc(sizeof(my_complex)*4);
	my_complex *result = malloc(sizeof(my_complex)*4);
*/
//	ptr[1] = malloc(sizeof(char)*255);
//	for(i = 1; i < count; ++i)
//		printf("%s\n", mas_point[i]);
/*
	while(1){
		printf("\nWhat operation do you want to perfome?\n\n");
		for(i = 1; i < count; ++i)
			printf("%d %s\n", i, mas_point[i]);
		printf("%d Quit\n", i);
 		user_char = getchar();
		switch(user_char){
			case '1':
				buf = calloc(100, sizeof(int)*255);
				ptr[1] = malloc(sizeof(char)*255);
				strcat(buf, path);
				strcat(buf, "/");
				strcat(buf, filenames[1]);
				enter_data(x,y);
				lib = dlopen(buf, RTLD_NOW);
				if(!lib){
					fprintf(stderr, "dlopen() error: %s\n", dlerror ());
					exit(1);
				}
				ptr[1] = dlsym(lib, mas_point[1]);
				result = (ptr[1])(*x,*y);
				printf("Success %s: %.1f %.1f\n", mas_point[1], result->real, result->image);
				free(buf);
				break;
			case '5':
				exit(0);
		}
		user_char = getchar();
	}
*/	return 0;
}
