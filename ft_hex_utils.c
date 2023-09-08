/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 19:51:34 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/09/08 17:57:43 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <libft.h>
#include <stdlib.h>

/**
 * @brief Returns the number of digits of a given number after being converted
 * to hexadecimal.
 *
 * @param n Number to be converted
 * @return size_t Digit count
 */
int	ft_hdigs(unsigned int n)
{
	int	d;

	d = 1;
	while (n / 16)
	{
		n /= 16;
		d++;
	}
	return (d);
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
	const int		pfxlen = ft_strlen(pfx) + sizeof(char);
	char			*str;
	char			*tmp;

	str = ft_itoh(n, achr);
	if (!str)
		return (NULL);
	tmp = ft_calloc(ft_strlen(str) + pfxlen, sizeof(char));
	if (!tmp)
	{
		free(str);
		return (NULL);
	}
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
