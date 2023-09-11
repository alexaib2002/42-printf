/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:13:17 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/01/29 13:47:34 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	const size_t	t = count * size;
	void			*ptr;
	size_t			i;

	if (!count || !size)
		return (malloc(0));
	if (t > INT_MAX)
		return (NULL);
	ptr = malloc(t);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < t && ptr)
		*((unsigned char *)ptr + i++) = 0;
	return (ptr);
}
