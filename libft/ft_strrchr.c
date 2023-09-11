/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:05:53 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/01/29 17:17:01 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*f;

	f = 0;
	while (*s)
	{
		if (*s == (char) c)
			f = (char *) s;
		s++;
	}
	if (*s == (char) c)
		f = (char *) s;
	return (f);
}
