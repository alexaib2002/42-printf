/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:50:49 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/01/28 16:42:06 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	int	i;

	if (n == 0 || dst == src)
		return (dst);
	i = 0;
	while (n--)
	{
		if (src > dst)
		{
			*((unsigned char *) dst + i) = *((unsigned char *) src + i);
			i++;
		}
		else
			*(((unsigned char *) dst) + n) = *(((unsigned char *) src) + n);
	}
	return (dst);
}
