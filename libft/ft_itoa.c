/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:51:35 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/02/01 10:53:11 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*ft_stralloc(int n)
{
	int		strsize;

	strsize = ft_ndigs(n) + 1;
	if (n < 0)
		strsize++;
	return (malloc((strsize) * sizeof(char)));
}

char	*ft_itoa(int n)
{
	char			*str;
	int				i;
	int				z;

	str = ft_stralloc(n);
	if (!str)
		return (NULL);
	i = 0;
	z = 1;
	while (ft_ndigs(z) < ft_ndigs(n))
		z *= 10;
	if (n < 0)
	{
		str[i++] = '-';
	}
	while (z)
	{
		str[i++] = ft_abs(n / z) + NUMS_PAD;
		n -= z * (n / z);
		z /= 10;
	}
	str[i] = 0;
	return (str);
}
