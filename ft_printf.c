/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:38:01 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/09/01 11:13:53 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdarg.h>
#include <libft.h>

/**
 * @brief Helper receiving a string-related conversion character, and writes the
 * current vararg from ap into stdout.
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
