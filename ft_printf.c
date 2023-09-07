/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:38:01 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/09/08 01:31:25 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <libft.h>

/**
 * @brief Helper receiving a string-related conversion character, and writes the
 * current vararg from ap into stdout, replacing said character.
 * 
 * @param fmtc String-formatter related character
 * @param ap Vararg list of printf
 * @return int Number of characters written
 */
int	printf_char(const char *fmtc, va_list ap)
{
	int	chrs;

	chrs = 1;
	if (*fmtc == 'c')
		ft_putchar_fd((char) va_arg(ap, int), STDOUT_FD);
	else if (*fmtc == 's')
		chrs = ft_prints(va_arg(ap, char *));
	else if (*fmtc == '%')
		chrs = ft_prints("%");
	return (chrs);
}

/**
 * @brief Helper receiving a number-related conversion character, and writes the
 * current vararg from ap into stdout, replacing said character.
 * 
 * @param fmtc Number-formatter related character
 * @param ap Vararg list of printf
 * @return int Vararg list of printf
 */
int	printf_nbr(const char *fmtc, va_list ap, size_t flags)
{
	int		chrs;
	char	*cstr;

	chrs = 1;
	cstr = NULL;
	if (*fmtc == 'p')
		cstr = ft_ultoph(va_arg(ap, size_t), 'a');
	else if (*fmtc == 'd' || *fmtc == 'i')
		cstr = ft_itoa(va_arg(ap, int));
	else if (*fmtc == 'u')
		cstr = ft_utoa(va_arg(ap, unsigned int));
	else if (*fmtc == 'x' || *fmtc == 'X')
		cstr = ft_parse_hex_flags(fmtc, va_arg(ap, unsigned int), flags);
	chrs = ft_prints(cstr);
	free(cstr);
	return (chrs);
}

/**
 * @brief Parses a conversion character, and calls a helper for writing the
 * necessary value specified at the varargs list into stdout.
 * 
 * @param fmts Format specifier start (ie: %)
 * @param ap Varargs list from printf
 * @return int Number of characters written. Should be returned by the helper.
 */
int	ft_parse_con(const char *fmts, va_list ap, size_t flags)
{
	const char	*fmtc = fmts + sizeof(char);
	int			chrs;

	chrs = 0;
	if (ft_isinset(*fmtc, STR_FORM_CVS))
		chrs = printf_char(fmtc, ap);
	else if (ft_isinset(*fmtc, NBR_FORM_CVS))
		chrs = printf_nbr(fmtc, ap, flags);
	return (chrs);
}

int	ft_printf(const char *str, ...)
{
	const char	*cstr;
	int			chrs;
	size_t		flags; // FIXME: this should be moved to the loop function after refactor
	va_list		ap;

	va_start(ap, str);
	cstr = str;
	chrs = 0;
	flags = 0;
	while (cstr && *cstr)
	{
		if (*cstr == '%')
		{
			while (ft_isinset(*(cstr + sizeof(char)), FORM_FLAGS))
			{
				if (*(cstr + sizeof(char)) == '#')
					flags |= FLAG_ALT_FORM;
				else if (*(cstr + sizeof(char)) == ' ')
					flags |= FLAG_SPACE;
				else if (*(cstr + sizeof(char)) == '+')
					flags |= FLAG_PLUS;
				cstr++;
			}
			if (ft_isinset(*(cstr + sizeof(char)), FORM_CVS))
			{
				chrs += ft_parse_con(cstr, ap, flags);
				cstr += 2 * sizeof(char);
				continue ; // FIXME: if this gets refactored, return here a value so the putchar part isn't evaluated
			}
		}
		ft_putchar_fd(*cstr, STDOUT_FD);
		chrs++;
		cstr++;
	}
	va_end(ap);
	return (chrs);
}
