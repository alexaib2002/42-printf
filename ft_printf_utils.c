/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:24:17 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/09/08 01:45:21 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <libft.h>

int	ft_prints(const char *str)
{
	const char	*cstr = str;

	if (!str)
		return (ft_prints("(null)"));
	while (cstr && *cstr)
		ft_putchar_fd(*cstr++, STDOUT_FD);
	return (cstr - str);
}

char	*ft_parse_dec_flags(int dec, size_t flags)
{
	char	*str;

	str = NULL;
	if (flags & FLAG_SPACE && !(flags & FLAG_PLUS) && dec >= 0)
		str = ft_strjoin(" ", ft_itoa(dec));
	else if (flags & FLAG_PLUS && dec >= 0)
		str = ft_strjoin("+", ft_itoa(dec));
	else
		str = ft_itoa(dec);
	return (str);
}

char	*ft_parse_hex_flags(const char *fmtc, unsigned int hex, size_t flags)
{
	char	*str;

	str = NULL;
	if (*fmtc == 'x')
	{
		if (flags & FLAG_ALT_FORM && hex)
			str = ft_itoph(hex, 'a');
		else
			str = ft_itoh(hex, 'a');
	}
	else if (*fmtc == 'X')
	{
		if (flags & FLAG_ALT_FORM && hex)
			str = ft_itoph(hex, 'A');
		else
			str = ft_itoh(hex, 'A');
	}
	return (str);
}
