/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:24:17 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/09/11 15:02:28 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <libft.h>
#include <stdlib.h>

int	ft_prints(const char *str)
{
	const char	*cstr = str;
	ssize_t		err;

	err = 0;
	if (!str)
		return (ft_prints("(null)"));
	while (cstr && *cstr && err >= 0)
		err = ft_putchar_fd(*cstr++, STDOUT_FD);
	if (err < 0)
		return (err);
	return (cstr - str);
}

size_t	ft_read_flags(const char **pstr)
{
	const char	*str = *pstr;
	size_t		flags;

	flags = 0;
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
	*pstr = str;
	return (flags);
}

char	*ft_parse_dec_flags(int dec, size_t flags)
{
	const char	*str_nbr = ft_itoa(dec);
	char		*str;

	str = NULL;
	if (!str_nbr)
		return (NULL);
	if (flags & FLAG_SPACE && !(flags & FLAG_PLUS) && dec >= 0)
		str = ft_strjoin(" ", str_nbr);
	else if (flags & FLAG_PLUS && dec >= 0)
		str = ft_strjoin("+", str_nbr);
	else
		str = ft_strdup(str_nbr);
	free((char *) str_nbr);
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
