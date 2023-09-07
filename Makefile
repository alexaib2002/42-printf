# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/30 17:38:05 by aaibar-h          #+#    #+#              #
#    Updated: 2023/09/07 22:28:23 by aaibar-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target library
NAME=libftprintf.a
OUT=.
BUILD_DIR=$(CURDIR)
export BUILD_DIR

# Dependencies
LIBFT=libft
LIBFT_NAME=libft.a

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

# Clean compiled objects
clean:
	@echo "Cleaning objects"
	@rm -f $(OBJS)
	@make -C $(LIBFT) clean

# Clean all
fclean: clean
	@echo "Cleaning all"
	@rm -f $(OUT)/$(NAME) $(OUT)/$(BIN)

# Re-make all, same as calling clean && all
re: fclean all

# Test rule
test: $(BIN)
	@./$(BIN)

# Test binary
$(BIN): $(NAME) $(SRCS_TEST)
	@$(CC) $(DFLAGS) -o $(BIN) $(OBJS) $(SRCS_TEST) $(LIBFT)/libft.a

# File compiling rules
$(NAME): $(OBJS)
	@make -C $(LIBFT) OUT=$(BUILD_DIR) all
	@mv $(BUILD_DIR)/$(LIBFT_NAME) $(BUILD_DIR)/$(NAME)
	@ar rcs $(NAME) $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<
