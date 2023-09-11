/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:16:24 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/01/29 13:44:55 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	const int	l = ft_strlen(s1);
	char		*pdup;
	int			i;

	i = 0;
	pdup = malloc((l + 1) * sizeof(char));
	if (!pdup)
		return (NULL);
	while (i < l)
	{
		pdup[i] = s1[i];
		i++;
	}
	pdup[i] = 0;
	return (pdup);
}
