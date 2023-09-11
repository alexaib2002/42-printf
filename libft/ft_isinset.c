/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 12:09:51 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/01/22 12:10:24 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isinset(const char c, const char *set)
{
	unsigned int	has;

	has = 0;
	while (*set)
		if (c == *(set++))
			has = 1;
	return (has);
}
