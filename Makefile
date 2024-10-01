# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/20 17:26:43 by mregrag           #+#    #+#              #
#    Updated: 2024/09/30 22:49:13 by mregrag          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D
NAME_B		= cub3D_bonus

CC		= cc
CFLAGS		= -Wall -Wextra -Werror #-fsanitize=address -g2

RM		=  rm -f

LIBFT_A		= libft.a

LIBFT		= -L./lib/Libft -lft
LIB		= -L$(HOME)/.brew/Cellar/glfw/3.4/lib -lglfw
MLX		= -L$(HOME)/.local/lib -lmlx42

MACOS		= -framework Cocoa -framework OpenGL -framework IOKit

LIBFT_H		= $(shell find ./lib/Libft -name '*.h')
CUBE_H		= $(shell find ./mandatory/include -name '*.h')
CUBE_B_H	= $(shell find ./bonus/include -name '*_bonus.h')

SRCS		= $(shell find ./mandatory/src -name '*.c')
SRCSB		= $(shell find ./bonus/src -name '*_bonus.c')

OBJS            = $(SRCS:.c=.o)
OBJS_B	        = $(SRCSB:.c=.o)

all: $(NAME)

$(LIBFT_A):
	make -C ./lib/Libft

$(NAME): $(LIBFT_A) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MACOS) $(LIB) $(LIBFT) $(MLX) -o $(NAME) 

%.o: %.c $(CUBE_H) $(CUBE_B_H) $(LIBFT_H)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(LIBFT_A) $(OBJS_B)
	$(CC) $(CFLAGS) $(OBJS_B) $(MACOS) $(LIB) $(LIBFT) $(MLX) -o $(NAME_B)
clean:
	@make clean -C ./lib/Libft
	$(RM) $(OBJS)
	$(RM) $(OBJS_B)

fclean: clean
	make fclean -C ./lib/Libft
	$(RM) $(NAME)
	$(RM) $(NAME_B)

re: fclean all

.PHONY: clean
