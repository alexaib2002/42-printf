/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:24:17 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/09/01 21:10:05 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <libft.h>
#include <stdlib.h>

/**
 * @brief Returns the number of digits of a given number after being converted
 * to hexadecimal.
 *
 * @param n Number to be converted
 * @return size_t Digit count
 */
size_t	ft_hdigs(unsigned int n)
{
	size_t	d;

	d = 1;
	while (n / 16)
	{
		n /= 16;
		d++;
	}
	return (d);
}

int	ft_prints(const char *str)
{
	const char	*cstr = str;

	while (cstr && *cstr)
		ft_putchar_fd(*cstr++, STDOUT_FD);
	return (cstr - str);
}

char	*ft_itoh(unsigned int n, char achr)
{
	char	*str;
	int		len;
	int		dig;

	len = ft_hdigs(n);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (len--)
	{
		dig = n % 16;
		if (dig > 9)
			str[len] = (dig - 10) + achr;
		else
			str[len] = dig + NUMS_PAD;
		n /= 16;
	}
	return (str);
}

char	*ft_itoph(unsigned int n, char achr)
{
	const char		*pfx = "0x";
	const size_t	pfxlen = ft_strlen(pfx) + sizeof(char);
	char			*str;
	char			*tmp;

	str = ft_itoh(n, achr);
	tmp = ft_calloc(ft_strlen(str) + pfxlen, sizeof(char));
	if (!str)
		return (NULL);
	if (ft_strlcat(tmp, pfx, pfxlen) == ft_strlen(pfx))
	{
		if (ft_strlcat(tmp, str, ft_strlen(str) + pfxlen) 
			!= ft_strlen(str) + ft_strlen(pfx))
		{
			free(tmp);
			tmp = NULL;
		}
	}
	free(str);
	return (tmp);
}
