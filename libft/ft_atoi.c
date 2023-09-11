/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:56:06 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/02/07 21:42:37 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_movptr(const char **nptr, char *s)
{
	while (**nptr && ft_isseparator(**nptr))
		(*nptr)++;
	if (**nptr == '+' || **nptr == '-')
	{
		if (**nptr == '-' && *s != -1)
			*s = -1;
		(*nptr)++;
	}
}

int	ft_atoi(const char *nptr)
{
	char			c;
	char			s;
	unsigned int	n;

	c = 0;
	s = 1;
	n = 0;
	ft_movptr(&nptr, &s);
	while (*nptr && ft_isdigit(*nptr))
	{
		n *= 10;
		c = *nptr - (NUMS_PAD);
		n += c;
		nptr++;
	}
	return (n * s);
}
