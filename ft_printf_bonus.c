/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:38:01 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/09/09 20:29:20 by aaibar-h         ###   ########.fr       */
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
int	printf_nbr(const char *fmtc, va_list ap, size_t flags)
{
	int		chrs;
	char	*cstr;

	chrs = 1;
	cstr = NULL;
	if (*fmtc == 'p')
		cstr = ft_ultoph(va_arg(ap, size_t), 'a');
	else if (*fmtc == 'd' || *fmtc == 'i')
		cstr = ft_parse_dec_flags(va_arg(ap, int), flags);
	else if (*fmtc == 'u')
		cstr = ft_utoa(va_arg(ap, unsigned int));
	else if (*fmtc == 'x' || *fmtc == 'X')
		cstr = ft_parse_hex_flags(fmtc, va_arg(ap, unsigned int), flags);
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

/**
 * @brief Parses a format specifier, including its flags, and calls a helper for
 * writing the necessary value specified at the varargs list into stdout.
 * Afterwards, it moves the pointer to the end of the format specifier.
 * 
 * @param pstr Pointer to the format specifier start (ie: %)
 * @param ap Varargs list from printf
 * @return int Number of characters written. Should be returned by the helper.
 */
int	ft_parse_format(const char **pstr, va_list ap)
{
	const char	*str = *pstr;
	size_t		flags;
	int			chrs;

	flags = 0;
	chrs = 0;
	while (ft_isinset(*(str + sizeof(char)), FORM_FLAGS))
	{
		if (*(str + sizeof(char)) == '#')
			flags |= FLAG_ALT_FORM;
		else if (*(str + sizeof(char)) == ' ')
			flags |= FLAG_SPACE;
		else if (*(str + sizeof(char)) == '+')
			flags |= FLAG_PLUS;
		str++;
	}
	if (ft_isinset(*(str + sizeof(char)), FORM_CVS))
	{
		chrs = ft_parse_con(str, ap, flags);
		if (chrs < 0)
			return (-1);
		str += 2 * sizeof(char);
	}
	*pstr = str;
	return (chrs);
}

int	ft_printf(const char *str, ...)
{
	int			chrs;
	int			wchrs;
	va_list		ap;

	va_start(ap, str);
	chrs = 0;
	while (str && *str)
	{
		if (*str == '%')
		{
			wchrs = ft_parse_format(&str, ap);
			if (wchrs < 0)
				return (-1);
			else
				chrs += wchrs;
			continue ;
		}
		if (ft_putchar_fd(*(str++), STDOUT_FD) < 0)
			return (-1);
		chrs++;
	}
	va_end(ap);
	return (chrs);
}
