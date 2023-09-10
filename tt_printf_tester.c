#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <stdarg.h>

#ifndef BONUS
# define BONUS 0
#endif

void tt_integers()
{
	printf("%i\t%i\n\n",
			printf("%i\n", 1),
			ft_printf("%i\n", 1));
	printf("%i\t%i\n\n",
			printf("%i\n", INT_MIN),
			ft_printf("%i\n", INT_MIN));
	printf("%i\t%i\n\n",
		   printf("%i\n", -INT_MIN),
		   ft_printf("%i\n", -INT_MIN));
	printf("%i\t%i\n\n",
		   printf("%i\n", LONG_MAX),
		   ft_printf("%i\n", LONG_MAX));
	printf("%i\t%i\n\n",
		   printf("%i\n", LONG_MIN),
		   ft_printf("%i\n", LONG_MIN));
	printf("%i\t%i\n\n",
		   printf("%i\n", ULONG_MAX),
		   ft_printf("%i\n", ULONG_MAX));
	printf("%i\t%i\n\n",
		   printf("%i\n", 0),
		   ft_printf("%i\n", 0));
	printf("%i\t%i\n\n",
		   printf("%i\n", -42),
		   ft_printf("%i\n", -42));
	printf("%i\t%i\n\n",
		   printf("%i\n", 42),
		   ft_printf("%i\n", 42));
}


void tt_hex()
{
	printf("\n=> Hex\n");
	printf("%i\t%i\n\n",
		   printf("%x\n", 1),
		   ft_printf("%x\n", 1));
	printf("%i\t%i\n\n",
		   printf("%x\n", LONG_MAX),
		   ft_printf("%x\n", LONG_MAX));
	printf("%i\t%i\n\n",
		   printf("%x\n", LONG_MIN),
		   ft_printf("%x\n", LONG_MIN));
	printf("%i\t%i\n\n",
		   printf(" %x %x %x %x %x %x %x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42),
		   ft_printf(" %x %x %x %x %x %x %x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));

	printf("\n=> Hex caps\n");
	printf("%i\t%i\n\n",
		   printf("%X\n", 1),
		   ft_printf("%X\n", 1));
	printf("%i\t%i\n\n",
		   printf("%X\n", LONG_MAX),
		   ft_printf("%X\n", LONG_MAX));
	printf("%i\t%i\n\n",
		   printf("%X\n", LONG_MIN),
		   ft_printf("%X\n", LONG_MIN));
	printf("%i\t%i\n\n",
		   printf(" %X %X %X %X %X %X %X\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42),
		   ft_printf(" %X %X %X %X %X %X %X\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
}

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
		
		// %c
	printf("%i\t%i\n\n",
		   printf("%c\n", 'a'),
		   ft_printf("%c\n", 'a'));
	printf("%i\t%i\n\n",
		   printf("%c%c%c\n", 'a', 'b', 'c'),
		   ft_printf("%c%c%c\n", 'a', 'b', 'c'));
}


void tt_flags()
{
	printf("\n=> Flags\n");
	// # flag on xX
	printf("%i\t%i\n\n",
		   printf("%#x\n", 0),
		   ft_printf("%#x\n", 0));
	printf("%i\t%i\n\n",
		   printf("%#X\n", 0),
		   ft_printf("%#X\n", 0));
	printf("%i\t%i\n\n",
		   printf("%#x\n", 1),
		   ft_printf("%#x\n", 1));
	printf("%i\t%i\n\n",
		   printf("%#X\n", 1),
		   ft_printf("%#X\n", 1));
	printf("%i\t%i\n\n",
		   printf("%###x\n", 16),
		   ft_printf("%###x\n", 16));
	// ' ' flag on di
	printf("%i\t%i\n\n",
		   printf("% d\n", 1),
		   ft_printf("% d\n", 1));
	printf("%i\t%i\n\n",
		   printf("% d\n", -1),
		   ft_printf("% d\n", -1));
	printf("%i\t%i\n\n",
		   printf("%   d\n", 15),
		   ft_printf("%   d\n", 15));
	printf("%i\t%i\n\n",
		   printf("%+d\n", 1),
		   ft_printf("%+d\n", 1));
	printf("%i\t%i\n\n",
		   printf("%+d\n", -1),
		   ft_printf("%+d\n", -1));
	printf("%i\t%i\n\n",
		   printf("%+ d\n", 15),
		   ft_printf("%+ d\n", 15));

	printf("\n=> Flags mix\n");
	printf("%i\t%i\n\n",
		   printf("%# +d\n", 15),
		   ft_printf("%# +d\n", 15));
	printf("%i\t%i\n\n",
		   printf("%# +d\n", -15),
		   ft_printf("%# +d\n", -15));
	printf("%i\t%i\n\n",
		   printf("%# d\n", 15),
		   ft_printf("%# d\n", 15));
	printf("%i\t%i\n\n",
		   printf("%# %d\n", -15),
		   ft_printf("%# %d\n", -15));
	printf("%i\t%i\n\n",
		   printf("%+ d\n", 15),
		   ft_printf("%+ d\n", 15));
	printf("%i\t%i\n\n",
		   printf("%+ +d\n", 15),
		   ft_printf("%+ +d\n", 15));
	printf("%i\t%i\n\n",
		   printf("% + + d\n", 15),
		   ft_printf("% + + d\n", 15));
	printf("%i\t%i\n\n",
		   printf("%-#d\n", 91),
		   ft_printf("%-#d\n", 91));
	printf("=> Stress test\n");
	printf("%i\t%i\n\n",
		   printf("%+d, %+d, %+d, %+d, %+d, %+d, %+d, %+d\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX),
		   ft_printf("%+d, %+d, %+d, %+d, %+d, %+d, %+d, %+d\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX));

}

void tt_errors()
{
	printf("\n=> Errors\n");
	printf("%i\t%i\n\n",
		   printf(NULL),
		   ft_printf(NULL));
	printf("%i\t%i\n\n",
		   printf(NULL, 1),
		   ft_printf(NULL, 1));
	printf("%i\t%i\n\n",
		   printf("%s", NULL),
		   ft_printf("%s", NULL));
}

/**
 * @brief Needs to test cspdiuxX %
 *
 * @return int
 */
int main()
{
	printf("=> Starting test binary...\nmine: example out\nexample out\nsysout no\tmineout no\n");
	tt_integers();
	tt_hex();
	tt_strings();
	// tt_errors();
	if (BONUS)
		tt_flags();
	return (0);
}
