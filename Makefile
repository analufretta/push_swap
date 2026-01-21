# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afretta- <afretta-@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/15 15:40:08 by afretta-          #+#    #+#              #
#    Updated: 2026/01/21 16:59:15 by afretta-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================= COLORS ================= #
GREEN = \033[0;32m
RED   = \033[0;31m
RESET = \033[0m

# ================= PROJECT ================= #
NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I. -I$(LIBFT_DIR)

# ================= SOURCES =================
SRCS = 	main.c \
		create_stack.c \
		errors_free.c \
		utils.c \
		algorithm/algo_utils.c \
		algorithm/algo_rotations.c \
		algorithm/cost_calculations.c \
		algorithm/find_in_stack.c \
		algorithm/push_swap.c \
		algorithm/set_in_stack.c \
		algorithm/set_rank_chunk.c \
		algorithm/tiny_sort.c \
		operations/push.c \
		operations/reverse.c \
		operations/rotate.c \
		operations/swap.c

OBJS = $(SRCS:.c=.o)

# ================= RULES =================

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)push_swap built$(RESET)"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

clean:
	@rm -f $(OBJS)
	@echo "$(RED)push_swap object files removed$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)push_swap removed$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
