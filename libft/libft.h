/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:49:15 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/09/08 16:54:56 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <unistd.h>
# ifndef CAPS_PAD
#  define CAPS_PAD 32
# endif
# ifndef NUMS_PAD
#  define NUMS_PAD 48
# endif

/*******************
* Type declarations
*****************/

/**
 * @struct s_list
 * @brief Represents a node on a list. Will have a reference to its content and
 * a reference to the next item, the latter being NULL when the end is reached.
 * @var s_list::content
 * References the data stored in this node
 * @var s_list::content
 * References the next node, will be NULL on the last node
 */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/*******************
* Checker functions
*****************/

/**
 * @brief Checks if given character is an alphabetic character
 * @param c Given character
 * @return Value greater than zero if the condition was met, else zero
 */
int		ft_isalpha(int c);
/**
 * @brief Checks if given character is a digit (0-9)
 * @param c Given character
 * @return Value greater than zero if the condition was met, else zero
 */
int		ft_isdigit(int c);
/**
 * @brief Checks if given character is an alphanumeric character, equivalent to
 * (isalpha(c) || isdigit(c)
 * @param c Given character
 * @return Value greater than zero if the condition was met, else zero
 */
int		ft_isalnum(int c);
/**
 * @brief Checks if given character is a valid ASCII one
 * @param c Given character
 * @return Value greater than zero if the condition was met, else zero
 */
int		ft_isascii(int c);
/**
 * @brief Checks if given character is printable (displays something on screen)
 * @param c Given character
 * @return Value greater than zero if the condition was met, else zero
 */
int		ft_isprint(int c);
/**
 * @brief Checks if given character is an uppercase letter
 * @param c Given character
 * @return Value greater than zero if the condition was met, else zero
 */
int		ft_isupper(int c);
/**
 * @brief Checks if given character is a lowercase letter
 * @param c Given character
 * @return Value greater than zero if the condition was met, else zero
 */
int		ft_islower(int c);
/**
 * @brief Checks if given character is a valid separator
 * @param c Given character
 * @return Value greater than zero if the condition was met, else zero
 */
int		ft_isseparator(int c);
/**
 * @brief Checks if given character is contained in a set of characters
 * @param c Given character
 * @param set Pointer to the set of characters to probe
 * @return Value greater than zero if the condition was met, else zero
 */
int		ft_isinset(const char c, const char *set);

/******************
* String functions
****************/

/**
 * @brief Calculates the length of a given string, excluding the NUL character
 * @param s Given string
 * @return Total length of the string
 */
size_t	ft_strlen(const char *s);
/**
 * @brief Copies up to (size - 1) a NUL-terminated source string, into a given
 *  destination, NUL-terminating the result.
 * @param dst Pointer to destination
 * @param src Source string
 * @param size Byte number about to copy, including the NUL terminator
 * @return Total length of the string attempted to create on dst. This value
 * should be validated against the real size of dst, for detecting truncation
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
/**
 * @brief Appends the NUL-terminated string src to the end of NUL-terminated
 * string dst. At most, (size - strlen(dst) - 1) bytes will be appended,
 * NUL-terminating the result afterwards.
 * @param dst NUL-terminated destination string
 * @param src NUL-terminated source string
 * @param size Byte number of the source string
 * @return Total length of the string attempted to create. Note that if after
 * traversing size characters without finding the NUL char, size will be
 * considered as the string size, and the dst string won't be NUL-terminated.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size);
/**
 * @brief Tries to locate the first occurrence of a character in a given string.
 * Note that NUL terminator is considered as part of the string.
 * @param s String about to be probed
 * @param c Searched character
 * @return Returns a pointer to the matched character, or NULL if it's not
 * found.
 */
char	*ft_strchr(const char *s, int c);
/**
 * @brief Tries to locate the last occurrence of a character in a given string.
 * Note that NUL terminator is considered as part of the string.
 * @param s String about to be probed
 * @param c Searched character
 * @return Returns a pointer to the matched character, or NULL if it's not
 * found.
 */
char	*ft_strrchr(const char *s, int c);
/**
 * @brief Locates the first occurrence of the NUL-terminated string 'little'
 * in the string 'big', searching at most 'len' characters, nor characters after
 * a NUL terminator.
 * @param big String where the search will be performed
 * @param little String to be found on 'big'
 * @param len Number of characters that should be searched
 * @return Pointer to the first character of the first occurrence of little on
 * big.
 * Big when little is an empty string, or NULL when little is not found on
 * 'big'.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len);
/**
 * @brief Compares two strings 's1' and 's2' up to at most 'n' bytes.
 * @param s1 First string
 * @param s2 Second string
 * @param n Number of bytes to be compared.
 * @return 0 if s1 and s2 are equal.
 * Negative value if s1 is less than s2.
 * Positive value if s1 is greater than s2.
 * Note that this implementation will return the arithmetic result of the last
 * compared byte substraction between s1 and s2.
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);
/**
 * @brief Given a string, converts it to an integer.
 * @param nptr pointer to string about to be converted
 * @return Converted value, or 0 in case of error.
 */
int		ft_atoi(const char *nptr);
/**
 * @brief Generates a string from a given signed integer. The resulting string
 * is generated with malloc.
 * @param n Given signed integer
 * @return Resulting string, or NULL if malloc fails. If some error happens
 * during conversion, the resulting string will be the number up until that
 * point (can be an empty string).
 */
char	*ft_itoa(int n);
/**
 * @brief Generates a string from a given unsigned integer. The resulting string
 * is generated with malloc.
 * @param n Given unsigned integer
 * @return Resulting string, or NULL if malloc fails. If some error happens
 * during conversion, the resulting string will be the number up until that
 * point (can be an empty string).
 */
char	*ft_utoa(unsigned int n);
/**
 * @brief Converts a valid lower-case letter referenced by the char to its
 * corresponding upper-case one.
 * @param c Given character
 * @return The converted letter, or 'c' if the conversion was not possible
 */
int		ft_toupper(int c);
/**
 * @brief Converts a valid upper-case letter referenced by the char to its
 * corresponding lower-case one.
 * @param c Given character
 * @return The converted letter, or 'c' if the conversion was not possible
 */
int		ft_tolower(int c);
/**
 * @brief Duplicate a string, allocating memory for it with malloc.
 * @param s1 String to be duplicated
 * @return Pointer to the duplicated string, or NULL if the allocation failed.
 */
char	*ft_strdup(const char *s1);
/**
 * @brief Returns a new string created from the original string 's' with an
 * offset delimited by 'start' with 'len' characters. If 'len' is greater than
 * the size of 's', the resulting substring will be ended by the NUL terminator
 * of 's'.
 * @param s String for creating the substring
 * @param start Substring offset
 * @param len Length of substring
 * @return Pointer to the new string. NULL when memory cannot be allocated.
 */
char	*ft_substr(const char *s, unsigned int start, size_t len);
/**
 * @brief Concatenates two strings 's1' and 's2' into a new one allocated with
 * malloc.
 * @param s1 First string
 * @param s2 Last string
 * @return Pointer to the new string. NULL when memory cannot be allocated.
 */
char	*ft_strjoin(const char *s1, const char *s2);
/**
 * @brief Creates a new string based on 's1' without any characters indicated
 * on 'set' in its front and its back.
 * @param s1 String to be trimmed
 * @param set Characters for trimming
 * @return Pointer to the new string. NULL when memory cannot be allocated.
 */
char	*ft_strtrim(const char *s1, const char *set);
/**
 * @brief Creates an array of strings by splitting a string 's' with a
 * delimiter character 'c'. The resulting strings will be allocated in memory.
 * @param s String to split
 * @param c Delimiter character
 * @return Pointer to the array, with a NULL pointer at its end.
 * NULL when memory cannot be allocated.
 */
char	**ft_split(const char *s, char c);
/**
 * @brief Applies the function 'f' to every character of string 's', giving as
 * parameters the index of the character and the character itself. Returns a new
 * string resulting from the modifications applied by 'f'.
 * @param s String about to be iterated
 * @param f Fucntion to apply for every character
 * @return The resulting string after calling 'f'. NULL when memory cannot be
 * allocated.
 */
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
/**
 * @brief Applies the function 'f' to every character of string 's', giving as
 * parameters the index of the character and the character itself, which can be
 * modified by 'f'. Thus, this function modifies the string indicated by 's'
 * @param s String about to be iterated
 * @param f Function to apply for every character
 * @return None
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/******************
* Memory functions
****************/

/**
 * @brief Erases data in the 'n' bytes of memory, starting at the location
 * pointed by 's', by writing zeroes to that area.
 * @param s Memory location about to be erased
 * @param n Byte number to be erased
 */
void	ft_bzero(void *s, size_t n);
/**
 * @brief Fills memory referenced by 's' with a constant byte 'c' up to 'n'
 * bytes.
 * @param s Memory area to be filled
 * @param c Constant byte
 * @param n Number of bytes to be filled
 * @return Pointer to the filled memory area 's'.
 */
void	*ft_memset(void *s, int c, size_t n);
/**
 * @brief Searches memory location 's' for the first ocurrence of byte 'c',
 * up to 'n' bytes.
 * @param s Memory area to be searched
 * @param c Given byte
 * @param n Number of bytes about to be searched.
 * @return Pointer to the matching byte, or NULL if the byte was not
 * found.
 */
void	*ft_memchr(const void *s, int c, size_t n);
/**
 * @brief Copies the first 'n' bytes from memory area 'src' to memory area
 * 'dest'.
 * Note the memory areas should not overlap. ft_memmove should be used on that
 * case.
 * @param dst Destination memory area.
 * @param src Source memory area.
 * @param n Number of bytes about to be copied.
 * @return Pointer to 'dst'.
 */
void	*ft_memcpy(void *dst, const void *src, size_t n);
/**
 * @brief Compares the first 'n' bytes, interpreted as unsigned char of the
 * memory areas s1 and s2.
 * @param s1 First memory area
 * @param s2 Second memory area
 * @param n Number of bytes to compare
 * @return Integer resulting from the difference between the pair of bytes
 * differing in s1 and s2.
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);
/**
 * @brief Copies 'n' bytes from memory area pointed by 'src' to memory area
 * 'dst'. Memory areas can overlap; initially the copy goes into a
 * temporary array without any overlapping and afterwards its moved to 'dest'.
 *
 * Note that this doesn't remove the src data, as such the src pointer
 * should be considered as unreliable after calling this function.
 * @param dst Destination memory area
 * @param src Source memory area
 * @param n Number of bytes about to be moved
 * @return Pointer to 'dst' memory area.
 */
void	*ft_memmove(void *dst, const void *src, size_t n);
/**
 * @brief Allocates memory for an array of 'count' elements, each of them
 * 'size' bytes long, and initializes all its bits to zero. Checks for integers
 * overflows with given parameters and zero values
 * @param count Number of elements to be allocated
 * @param size Size of each element
 * @return Pointer to the allocated memory, or NULL if the allocation failed.
 */
void	*ft_calloc(size_t count, size_t size);

/***************************
* File descriptor functions
*************************/

/**
 * @brief Sends the character 'c' into a file descriptor 'fd'.
 * @param c Character to send
 * @param fd File descriptor to be written
 * @return Number of bytes written. -1 if an error occurs.
 */
ssize_t	ft_putchar_fd(char c, int fd);
/**
 * @brief Sends the string 's' into a file descriptor 'fd'.
 * @param s String to send
 * @param fd File descriptor to be written
 */
void	ft_putstr_fd(char *s, int fd);
/**
 * @brief Sends the string 's' into a file descriptor 'fd', followed by a line
 * break.
 * @param s String to send
 * @param fd File descriptor to be written
 */
void	ft_putendl_fd(char *s, int fd);
/**
 * @brief Sends the number 'n' into a file descriptor 'fd'.
 * @param n Number to send
 * @param fd File descriptor to be written
 */
void	ft_putnbr_fd(int n, int fd);

/****************
* List functions
**************/

/**
 * @brief Creates a new node, with its variable 'content' assigned to the given
 * 'content' argument, and its 'next' variable setted to NULL.
 * @param content Node content
 * @return The generated node
 */
t_list	*ft_lstnew(void *content);

/**
 * @brief Counts the number of nodes of a list.
 * @param lst Pointer to the first node of the list
 * @return List's node count
 */
int		ft_lstsize(t_list *lst);

/**
 * @brief Returns the last node of a list.
 * @param lst Pointer to the first node of the list
 * @return Last node of the list
 */
t_list	*ft_lstlast(t_list *lst);

/**
 * @brief Adds the 'new' node to the 'lst' list's front.
 * @param lst Pointer to the first node of the list
 * @param new Pointer to a new node about to be appended to the first index
 */
void	ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Adds the 'new' node to the 'lst' list's end.
 * @param lst Pointer to the first node of the list
 * @param new Pointer to a new node about to be appended to the last index
 */
void	ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Frees a node referenced by 'lst', and the memory allocated for its
 * 'content' with the function 'del'.
 * @param lst Node about to be freed
 * @param del Function for freeing the content of the node
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * @brief Removed recursively every node from 'lst' to the end of the list,
 * by calling 'del' and free. At the end, the pointer 'lst' will be NULL.
 * @param lst Pointer to the first node about to be freed
 * @param del Function for freeing the content of the nodes
 */
void	ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * @brief Iterates the list 'lst' and applies the function 'f' to the content
 * of every node.
 * @param lst Pointer to the first node
 * @param f Function about to be applied for every node
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Iterates the list 'lst' and applies the function 'f' to the content
 * of every node, appending the said node to a new list if the function 'f' ends
 * as expected. Function 'del' is called when necessary.
 * @param lst Pointer to the first node
 * @param f Function about to be applied for every node
 * @param del Function called when 'content' removal is required for a given
 * node
 * @return Pointer to the new list. NULL when memory allocation fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/****************
* Math functions
**************/

/**
 * @brief Returns the absolute value (positive) of a given number 'n'.
 * @param n Number
 * @return Absolute value of 'n'.
 */
int		ft_abs(int n);
/**
 * @brief Given a number 'n', limits its value with a minimum of 'min' and a
 * maximum of 'max'.
 * @param min Minimum value of 'n'
 * @param max Maximum value of 'n'
 * @param n Number to limit
 * @return Value of 'n' after clamping its value.
 */
long	ft_clamp(long min, long max, long n);

/**
 * @brief Given an unsigned number 'n', limits its value with a minimum of
 * 'min' and a maximum of 'max'.
 * @param min Minimum unsigned value of 'n'
 * @param max Maximum unsigned value of 'n'
 * @param n Unsigned number to limit
 * @return Unsigned value of 'n' after clamping its value.
 */
size_t	ft_uclamp(size_t min, size_t max, size_t n);

/**
 * @brief Calculates the number of digits of a given number 'n'.
 * @param n Number
 * @return Digits of 'n'.
 */
int		ft_ndigs(int n);

/**
 * @brief Calculates the number of digits of a given unsigned number 'n'.
 * @param n Unsigned number
 * @return Digits of 'n'.
 */
size_t	ft_undigs(unsigned int n);

/*****************
* Array functions
***************/

/**
 * @brief Frees an array
 * @param arr
 */
void	ft_free_arr(void **arr);

#endif
