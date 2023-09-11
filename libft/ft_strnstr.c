/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexaib <alexaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 10:32:10 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/02/15 19:52:05 by alexaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*lptr;
	size_t		i;

	if (ft_strlen(little) == 0)
		return ((char *) big);
	lptr = little;
	while (*big && len)
	{
		i = 0;
		while (big[i] == lptr[i] && lptr[i] && big[i] && i < len)
			i++;
		if (!lptr[i])
			return ((char *) big);
		len--;
		big++;
	}
	return (0);
}
