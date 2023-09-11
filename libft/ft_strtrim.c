/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:54:49 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/01/30 17:11:21 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*str;
	char	*eptr;
	int		size;

	eptr = (char *) s1 + ft_strlen(s1) - 1;
	while (s1 < eptr && ft_isinset(*s1, set))
		s1++;
	while (eptr >= s1 && ft_isinset(*eptr, set))
		eptr--;
	size = eptr - s1 + 1;
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, size);
	*(str + size) = 0;
	return (str);
}
