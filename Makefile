# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afretta- <afretta-@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/15 15:40:08 by afretta-          #+#    #+#              #
#    Updated: 2025/12/16 13:44:15 by afretta-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT     = $(LIBFT_DIR)/libft.a

INCLUDES  = -Iincludes -I$(LIBFT_DIR)/includes
