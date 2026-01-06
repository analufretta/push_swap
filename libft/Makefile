# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afretta- <afretta-@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/17 11:49:44 by afretta-          #+#    #+#              #
#    Updated: 2026/01/06 12:39:23 by afretta-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================= COLORS ================= #
GREEN = \033[0;32m
RED   = \033[0;31m
RESET = \033[0m

# ================= PROJECT ================= #
NAME = 	libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

# ================= SOURCES ================= #
SRC = 	ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c

OBJ = $(SRC:.c=.o)

# ================= RULES ================= #
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "$(GREEN)libft built$(RESET)"

clean:
	@rm -f $(OBJ)
	@echo "$(RED)libft objects removed$(RESET)"


fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)libft removed$(RESET)"

re: fclean all

.PHONY: all clean fclean re
