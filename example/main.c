#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "func.h"

int main()
{
	void *lib;
	int (*fptr)(int, int);

	lib = dlopen("plugin/libfunc.so", RTLD_NOW);
	if(lib == NULL){
		fprintf(stderr, "Errorr in dlopen: %s\n", dlerror ());
		return 1;
	}
	fptr = dlsym(lib, "mul");
	if(lib == NULL){
		fprintf(stderr, "Error in dlsym: %s\n", dlerror ());
		return 1;
	}
	int x = 5, y = 6;
	(*fptr)(x,y);

	dlclose(lib);

	return;
}
