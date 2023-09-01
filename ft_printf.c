/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:38:01 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/09/01 13:00:41 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
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
int	printf_nbr(const char *fmtc, va_list ap)
{
	int		chrs;
	char	*cstr;

	chrs = 1;
	cstr = NULL;
	if (*fmtc == 'p')
		fmtc ;
	else if (*fmtc == 'd' || *fmtc == 'i')
		cstr = ft_itoa(va_arg(ap, int));
	else if (*fmtc == 'u')
		cstr = ft_utoa(va_arg(ap, unsigned int));
	else if (*fmtc == 'x')
		fmtc ;
	else if (*fmtc == 'X')
		fmtc ;
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
int	ft_parse_con(const char *fmts, va_list ap)
{
	const char	*fmtc = fmts + sizeof(char);
	int			chrs;


	if (ft_isinset(*fmtc, STR_FORM_CVS))
		chrs = printf_char(fmtc, ap);
	else if (ft_isinset(*fmtc, NBR_FORM_CVS))
		chrs = printf_nbr(fmtc, ap);
	return (chrs);
}

int	ft_printf(const char *str, ...)
{
	const char	*cstr;
	int			chrs;
	va_list		ap;

	va_start(ap, str);
	cstr = str;
	chrs = 0;
	while (cstr && *cstr)
	{
		if (*cstr == '%' && ft_isinset(*(cstr + sizeof(char)), FORM_CVS))
		{
			chrs += ft_parse_con(cstr, ap);
			cstr += 2 * sizeof(char);
			continue ;
		}
		ft_putchar_fd(*cstr, STDOUT_FD);
		chrs++;
		cstr++;
	}
	va_end(ap);
	return (chrs);
}
