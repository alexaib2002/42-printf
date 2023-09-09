/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 22:28:22 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/09/09 17:40:59 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <unistd.h>
# ifndef FORM_CVS
#  define FORM_CVS "cspdiuxX%"
# endif
# ifndef FORM_FLAGS
#  define FORM_FLAGS "# +"
# endif
# ifndef FLAG_ALT_FORM // Defines #
#  define FLAG_ALT_FORM 0x1
# endif
# ifndef FLAG_SPACE // Defines ' '
#  define FLAG_SPACE 0x2
# endif
# ifndef FLAG_PLUS /// Defines +
#  define FLAG_PLUS 0x4
# endif
# ifndef STR_FORM_CVS
#  define STR_FORM_CVS "cs%"
# endif
# ifndef NBR_FORM_CVS
#  define NBR_FORM_CVS "pdiuxX"
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
int		ft_printf(const char *str, ...);

/**
 * @brief Writes into stdout any standard string.
 * 
 * @param str String to be printed.
 * @return int Upon success, returns the characters written, excluding NUL 
 * terminator.
 */
int		ft_prints(const char *str);

/**
 * @brief Returns a string after converting the int `n` to hexadecimal.
 * 
 * @param n Number to be converted
 * @param achr Character to be used as the first character of the hexadecimal
 * @return char* String containing the hexadecimal representation of `n`.
 */
char	*ft_itoh(unsigned int n, char achr);

/**
 * @brief Returns a string after converting the int `n` to hexadecimal,
 * prefixed with `0x`.
 * 
 * @param n Number to be converted
 * @param achr Character to be used as the first character of the hexadecimal
 * @return char* String containing the hexadecimal representation of `n`.
 */
char	*ft_itoph(unsigned int n, char achr);

char	*ft_ultoh(size_t n, char achr);

/**
 * @brief Returns a string after converting the size_t `n` to hexadecimal,
 * prefixed with `0x`.
 * 
 * @param n Number to be converted
 * @param achr Character to be used as the first character of the hexadecimal
 * @return char* String containing the hexadecimal representation of `n`.
 */
char	*ft_ultoph(size_t n, char achr);

/**
 * @brief Takes a decimal number, and returns a string containing the decimal 
 * representation of the number, after applying the formatter flags.
 * 
 * @param dec Number to be converted
 * @param flags Variable containing bit flags
 * @return char* Resulting string
 */
char	*ft_parse_dec_flags(int dec, size_t flags);

/**
 * @brief Takes a hex format character ('x' or 'X') and a hexadecimal number,
 * and returns a string containing the hexadecimal representation of the number,
 * after applying the formatter flags.
 * 
 * @param fmtc Format character
 * @param hex Number to be converted
 * @param flags Variable containing bit flags
 * @return char* Resulting string
 */
char	*ft_parse_hex_flags(const char *fmtc, unsigned int hex, size_t flags);

#endif
