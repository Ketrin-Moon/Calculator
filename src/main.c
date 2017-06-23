#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
#include "../include/my_complex.h"

int main()

{
	int  count = 0;
	char path[255] = "/home/2017/maklashkina/calc/Calculator/plugin";
	char **filenames = direct(path, &count);

	open(filenames, count, path);

	return 0;
}
