/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:38:01 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/09/09 17:17:07 by aaibar-h         ###   ########.fr       */
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
		chrs = ft_putchar_fd((char) va_arg(ap, int), STDOUT_FD);
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
		cstr = ft_ultoph(va_arg(ap, size_t), 'a');
	else if (*fmtc == 'd' || *fmtc == 'i')
		cstr = ft_itoa(va_arg(ap, int));
	else if (*fmtc == 'u')
		cstr = ft_utoa(va_arg(ap, unsigned int));
	else if (*fmtc == 'x')
		cstr = ft_itoh(va_arg(ap, size_t), 'a');
	else if (*fmtc == 'X')
		cstr = ft_itoh(va_arg(ap, size_t), 'A');
	if (cstr)
	{
		chrs = ft_prints(cstr);
		free(cstr);
		return (chrs);
	}
	return (-1);
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

	chrs = 0;
	if (ft_isinset(*fmtc, STR_FORM_CVS))
		chrs = printf_char(fmtc, ap);
	else if (ft_isinset(*fmtc, NBR_FORM_CVS))
		chrs = printf_nbr(fmtc, ap);
	return (chrs);
}

int	ft_printf(const char *str, ...)
{
	int			chrs;
	int			wchrs;
	va_list		ap;

	va_start(ap, str);
	chrs = 0;
	wchrs = 0;
	while (str && *str)
	{
		if (*str == '%' && ft_isinset(*(str + sizeof(char)), FORM_CVS))
		{
			wchrs = ft_parse_con(str, ap);
			if (wchrs < 0)
				return (-1);
			chrs += wchrs;
			str += 2 * sizeof(char);
			continue ;
		}
		if (ft_putchar_fd(*(str++), STDOUT_FD) < 0)
			return (-1);
		chrs++;
	}
	va_end(ap);
	return (chrs);
}
