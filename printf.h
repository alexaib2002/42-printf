/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:37:59 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/09/01 11:31:18 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# ifndef FORM_CVS
#  define FORM_CVS "cspdiuxX%"
# endif
# ifndef STR_FORM_CVS
#  define STR_FORM_CVS "cs%"
# endif
# ifndef NBR_FORM_CVS
#  define NBR_FORM_CVS "pdiuxX"
# endif
# ifndef FLAG_CVS
#  define FLAG_CVS "# +"
# endif
# ifndef STDOUT_FD
#  define STDOUT_FD 1
# endif

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

/**
 * @brief Writes into stdout any standard string.
 * 
 * @param str String to be printed.
 * @return int Upon success, returns the characters written, excluding NUL 
 * terminator.
 */
int	ft_prints(const char *str);

#endif
