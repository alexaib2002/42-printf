/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:24:17 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/09/08 17:07:42 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <libft.h>

int	ft_prints(const char *str)
{
	const char	*cstr = str;
	ssize_t		err;

	err = 0;
	if (!str)
		return (ft_prints("(null)"));
	while (cstr && *cstr && err >= 0)
		err = ft_putchar_fd(*cstr++, STDOUT_FD);
	if (err < 0)
		return (err);
	return (cstr - str);
}
