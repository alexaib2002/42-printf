/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uhex_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 19:59:39 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/09/02 21:00:11 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <libft.h>
#include <stdlib.h>

/**
 * @brief Returns the number of digits of a given unsigned 
 * number after being converted to hexadecimal.
 *
 * @param n Number to be converted
 * @return size_t Digit count
 */
size_t	ft_uhdigs(size_t n)
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

char	*ft_ultoh(size_t n, char achr)
{
	char	*str;
	size_t	len;
	size_t	dig;

	len = ft_uhdigs(n);
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

char	*ft_ultoph(size_t n, char achr)
{
	const char		*pfx = "0x";
	const size_t	pfxlen = ft_strlen(pfx) + sizeof(char);
	char			*str;
	char			*tmp;

	str = ft_ultoh(n, achr);
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
