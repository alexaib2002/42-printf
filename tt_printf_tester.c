#include "printf.h"
#include <stdio.h>
#include <limits.h>
#include <stdarg.h>

// void print_compare(char *str,
// 				   int (*sysfn)(),
// 				   int (*myfn)())
// {
// 	int sysres;
// 	int myres;

// 	printf("\nTest: %s\n", str);
// 	printf("\n===Results===\n");
// 	sysres = sysfn();
// 	myres = myfn();
// 	printf("System\tMine\n");
// 	printf("------------------\n");
// 	printf("%i\t%i\n", sysres, myres);
// }

// void char_test()
// {
// 	print_compare("hello world!",
// 				  printf("hello world!"),
// 				  ft_printf("hello world!"));
// 	print_compare("",
// 				  printf(""),
// 				  ft_printf(""));
// }

// void number_test()
// {
// 	// Unformatted stringsprintf("%i %i",
//    printf("hello world %s\n", "from my own function!"),
//    ft_printf("hello world %s\n", "from my own function!"));

// 	// Number format
// 	print_compare("%i",
// 				  printf("%i", 1),
// 				  ft_printf("%i", 1));
// 	print_compare("start%i",
// 				  printf("%i", 1),
// 				  ft_printf("%i", 1));
// 	print_compare("%iend",
// 				  printf("%i", 1),
// 				  ft_printf("%i", 1));
// 	print_compare("start%iend",
// 				  printf("%i", 1),
// 				  ft_printf("%i", 1));
// 	print_compare("%i",
// 				  printf("%i", 256),
// 				  ft_printf("%i", 256));
// 	print_compare("%i",
// 				  printf("%i", -18),
// 				  ft_printf("%i", -18));
// 	print_compare("%i",
// 				  printf("%i", INT_MAX),
// 				  ft_printf("%i", INT_MAX));
// 	print_compare("%i",
// 				  printf("%i", -INT_MAX),
// 				  ft_printf("%i", -INT_MAX));
// }

// String tests

void tt_strings()
{
	const char *tt0 = "hello world %s\n";
	const char *tt0a0 = "from my own function";
	const char *tt1 = "%s%s\n";
	const char *tt1a0 = "some";
	const char *tt1a1 = "test";
	const char *tt2 = "s%sss%%s\n"; // try to break the format parser
	const char *tt2a0 = "s";
	const char *tt2a1 = "s";

	printf("\n=> Strings\n");
	printf("%i\t%i\n\n",
		   printf(tt0, tt0a0),
		   ft_printf(tt0, tt0a0));
	printf("%i\t%i\n\n",
		   printf(tt1, tt1a0, tt1a1),
		   ft_printf(tt1, tt1a0, tt1a1));
	printf("%i\t%i\n\n",
		   printf(tt2, tt2a0, tt2a1),
		   ft_printf(tt2, tt2a0, tt2a1));
}

void tt_integer()
{
}

/**
 * @brief Needs to test cspdiuxX %
 *
 * @return int
 */
int main()
{
	printf("=> Starting test binary...\nmine: example out\nsys: example out\nsysout no\tmineout no\n");
	tt_strings();
}
