#include "printf.h"
#include <stdio.h>
#include <limits.h>
#include <stdarg.h>

void print_compare(char *str)
{
	int sysres;
	int myres;

	printf("\nTest: %s\n", str);
	printf("\n===Results===\n");
	printf("System\tMine\n");
	printf("------------------\n");
	printf("%i\t%i\n", sysres, myres);
}

int main()
{
	
}
