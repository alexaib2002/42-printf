# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/30 17:38:05 by aaibar-h          #+#    #+#              #
#    Updated: 2023/09/02 21:01:27 by aaibar-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target library
NAME=libftprintf.a
OUT=.
TMPDIR=$(CURDIR)/out
export TMPDIR

# Dependencies
LIBFT=libft

# Compiler and flags
CC=gcc
CFLAGS=-Wall -Werror -Wextra -I$(LIBFT)
DFLAGS=-fsanitize=address -g -fno-builtin

# Sources
SRCS=ft_printf.c ft_printf_utils.c ft_hex_utils.c ft_uhex_utils.c

# Objects
OBJS=$(SRCS:.c=.o)

# Test sources
BIN=libftprintf.bin
SRCS_TEST=tt_printf_tester.c

.PHONY: libft clean fclean re test

# Compile all
all: $(NAME)

libft:
	@make -C $(LIBFT) OUT=$(TMPDIR) all

# Clean compiled objects
clean:
	@echo "Cleaning objects"
	@rm -f $(OBJS)
	@make -C $(LIBFT) clean

# Clean all
fclean: clean
	@echo "Cleaning all"
	@rm -f $(OUT)/$(NAME) $(OUT)/$(BIN)
	@make -C $(LIBFT) OUT=$(TMPDIR) fclean

# Re-make all, same as calling clean && all
re: fclean all

# Test rule
test: $(BIN)
	@./$(BIN)

# Test binary
$(BIN): $(NAME) $(SRCS_TEST)
	@$(CC) $(DFLAGS) -o $(BIN) $(OBJS) $(SRCS_TEST) $(LIBFT)/libft.a

# File compiling rules
$(NAME): $(OBJS) libft
	@mkdir -p $(TMPDIR) && cd $(TMPDIR) && ar x $(LIBFT).a && cd $(CURDIR)
	@ar rcs $(NAME) $(OBJS) $(TMPDIR)/*.o

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<
