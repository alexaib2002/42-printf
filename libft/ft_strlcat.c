/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexaib <alexaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:32:58 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/02/19 12:40:56 by alexaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	const size_t	dlen = ft_strlen(dst);
	const size_t	slen = ft_strlen(src);
	size_t			i;
	char			*ptr;

	i = dlen + 1;
	while (i && size)
	{
		i--;
		size--;
	}
	size = ft_uclamp(0, slen, size);
	ptr = dst + dlen;
	ft_memcpy(ptr, src, size);
	*(ptr + size) = 0;
	if (!i)
		return (slen + dlen);
	return (slen + (dlen - i) + 1);
}
