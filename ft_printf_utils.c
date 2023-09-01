/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:24:17 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/08/31 22:25:19 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <libft.h>

int	ft_prints(const char *str)
{
	const char	*cstr = str;

	while (cstr && *cstr)
		ft_putchar_fd(*cstr++, STDOUT_FD);
	return (cstr - str);
}
