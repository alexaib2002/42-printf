# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/30 17:38:05 by aaibar-h          #+#    #+#              #
#    Updated: 2023/09/10 17:16:16 by aaibar-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target library
NAME=libftprintf.a
OUT=.
BUILD_DIR=$(CURDIR)

# Dependencies
LIBFT=libft
LIBFT_NAME=libft.a

# Compiler and flags
CC=gcc
CFLAGS=-Wall -Werror -Wextra -I$(LIBFT)
DFLAGS=-fsanitize=address -g -fno-builtin

# Sources
SRCS_COMMON=ft_hex_utils.c ft_uhex_utils.c
SRCS=ft_printf.c ft_printf_utils.c $(SRCS_COMMON)
SRCS_BONUS=ft_printf_bonus.c ft_printf_utils_bonus.c $(SRCS_COMMON)

# Objects
OBJS=$(SRCS:.c=.o)
OBJS_BONUS=$(SRCS_BONUS:.c=.o)

# Test sources
BIN=libftprintf.bin
SRCS_TEST=tt_printf_tester.c

.PHONY: libft clean fclean re test bonus test_bonus

# Compile all
all: $(NAME)

bonus:
	@echo "Compiling bonus target"
	@make $(NAME) SRCS="$(SRCS_BONUS)"

# Clean compiled objects
clean:
	@echo "Cleaning objects"
	@rm -f $(OBJS)
	@rm -f $(OBJS_BONUS)
	@make -C $(LIBFT) clean

# Clean all
fclean: clean
	@echo "Cleaning all"
	@rm -f $(OUT)/$(NAME) $(OUT)/$(BIN)

# Re-make all, same as calling clean && all
re: fclean all

# Test rule
test:
	@make -B $(BIN)
	@./$(BIN)

test_bonus:
	@make -B $(BIN) DFLAGS+=-DBONUS SRCS="$(SRCS_BONUS)"
	@./$(BIN) bonus

# Test binary
$(BIN): $(NAME) $(SRCS_TEST)
	@$(CC) $(DFLAGS) -o $(BIN) $(SRCS_TEST) $(NAME)

# File compiling rules
$(NAME): $(OBJS)
	$(shell make -C $(LIBFT) OUT=$(BUILD_DIR) all)
	@mv $(BUILD_DIR)/$(LIBFT_NAME) $(BUILD_DIR)/$(NAME)
	@ar rcs $(NAME) $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<
