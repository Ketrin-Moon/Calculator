#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "func.h"

void add(int x, int y)
{
	int s;
	s = x + y;
	printf("R: %d\n", s);
}
void mul(int x, int y)
{
	int m;
	m = x * y;
	printf("R: %d\n", m);
}
