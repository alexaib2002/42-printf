/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexaib <alexaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:18:35 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/02/09 23:04:26 by alexaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (start > ft_strlen(s))
		start = ft_strlen(s);
	if (start + len > ft_strlen(s) || (len + start) < len)
	{
		len = ft_strlen(s) - start;
	}
	sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	s += start;
	while (*s && i < len)
		sub[i++] = *(s++);
	sub[i] = 0;
	return (sub);
}
