/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:37:59 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/08/31 00:05:55 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

/**
 * @brief Produces an output based on a given formatted string. Additional 
 * arguments may be passed with varags.
 * 
 * @param str Formatted string about to be printed
 * @param ... Varargs containing values
 * @return int Uppon success, number of ouptutted characters of `str`, excluding
 * NUL character and including the ones inserted after formatting. 
 * A negative handle will be return if some error is found
 */
int	ft_printf(const char *str, ...);

#endif
