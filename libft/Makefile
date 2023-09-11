# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 18:44:01 by aaibar-h          #+#    #+#              #
#    Updated: 2023/09/01 22:16:05 by aaibar-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target library
NAME = libft.a
OUT = .
# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra

# Sources
SRCS = ft_abs.c ft_atoi.c ft_bzero.c ft_calloc.c ft_clamp.c ft_free_arr.c \
ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isinset.c ft_islower.c \
ft_isprint.c ft_isseparator.c ft_isupper.c ft_itoa.c ft_utoa.c ft_memchr.c \
ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_ndigs.c ft_putchar_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
ft_tolower.c ft_toupper.c ft_uclamp.c ft_undigs.c
SRCS_BONUS = ft_lstadd_back_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
ft_lstmap_bonus.c ft_lstsize_bonus.c ft_lstadd_front_bonus.c \
ft_lstdelone_bonus.c ft_lstlast_bonus.c ft_lstnew_bonus.c

# Object files
OBJS = $(SRCS:.c=.o)
OBJS_BONUS= $(SRCS_BONUS:.c=.o)

# Main rules
# Define PHONY rules
.PHONY: bonus clean fclean re

# Compile all
all: $(NAME)

# Compile the bonus functions
bonus: $(NAME)
	@echo "Compiling bonus target"
	@make $(NAME) SRCS="$(SRCS_BONUS)"

# Clean compiled objects
clean:
	@echo "Cleaning objects"
	@rm -f $(OBJS) $(OBJS_BONUS)

# Clean all
fclean: clean
	@echo "Cleaning all"
	@rm -f $(OUT)/$(NAME)

# Re-make all, same as calling clean && all
re: fclean all

# File compiling rules
$(NAME): $(OBJS)
	@ar rcs $(OUT)/$(NAME) $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<
