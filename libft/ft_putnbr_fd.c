/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:12:37 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/02/01 14:56:51 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	z;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
	}
	z = 1;
	while (ft_ndigs(z) < ft_ndigs(n))
		z *= 10;
	while (z)
	{
		ft_putchar_fd(ft_abs(n / z) + NUMS_PAD, fd);
		n -= z * (n / z);
		z /= 10;
	}
}
