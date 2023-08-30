/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:38:01 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/08/31 00:57:13 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdarg.h>
#include <libft.h>

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	const char	*cstr;

	va_start(ap, str);
	cstr = str;
	while (*cstr)
	{
		ft_putchar_fd(*cstr, 1);
		cstr++;
	}
	return (cstr - str);
}
