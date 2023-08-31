/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:38:01 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/08/31 18:37:09 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdarg.h>
#include <libft.h>

int	ft_print_string(const char *str)
{
	const char	*cstr;

	cstr = str;
	while (cstr && *cstr)
	{
		ft_putchar_fd(*cstr++, 1);
	}
	return (cstr - str);
}

int	ft_find_format(const char *fmts, va_list ap)
{
	const char	*fmtc = fmts + sizeof(char);
	char		*arg;
	int			chrs;

	if (*fmtc == 's')
	{
		arg = va_arg(ap, char *);
		chrs = ft_print_string(arg);
	}
	else if (*fmtc == '%')
	{
		chrs = ft_print_string("%");
	}

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
	while (*cstr)
	{
		if (*cstr == '%' && cstr + 1
			&& ft_isinset(*(cstr + sizeof(char)), FORM_CVS))
		{
			chrs += ft_find_format(cstr, ap);
			cstr += 2 * sizeof(char);
			continue ;
		}
		ft_putchar_fd(*cstr, 1);
		chrs++;
		cstr++;
	}
	va_end(ap);
	return (chrs);
}
