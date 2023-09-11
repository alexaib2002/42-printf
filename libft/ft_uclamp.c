/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uclamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:47:47 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/02/08 22:48:16 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_uclamp(size_t min, size_t max, size_t n)
{
	if (n < min)
		n = min;
	if (n > max)
		n = max;
	return (n);
}
