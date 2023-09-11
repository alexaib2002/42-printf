/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:53:18 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/01/24 18:47:15 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int	r;

	r = 0;
	while (n--)
	{
		r = *(unsigned char *)s1++ - *(unsigned char *)s2++;
		if (r)
			return (r);
	}
	return (0);
}
