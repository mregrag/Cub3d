# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/20 17:26:43 by mregrag           #+#    #+#              #
#    Updated: 2024/10/04 15:11:48 by mregrag          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project names
NAME        = cub3D
NAME_B      = cub3D_bonus

# Compiler and flags
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -f

LIBFT_A     = ./lib/Libft/libft.a
LIBFT       = -L./lib/Libft -lft

GLFW        = -L$(HOME)/.brew/Cellar/glfw/3.4/lib -lglfw
MLX         = -L$(HOME)/.local/lib -lmlx42
MACOS       = -framework Cocoa -framework OpenGL -framework IOKit

# Headers
LIBFT_H     = $(shell find ./lib/Libft -name '*.h')
CUBE_H      = $(shell find ./mandatory/include -name '*.h')
CUBE_B_H    = $(shell find ./bonus/include -name '*_bonus.h')

# Source  Files
SRCS        = $(shell find ./mandatory/src -name '*.c')
SRCS_B      = $(shell find ./bonus/src -name '*_bonus.c')
SRCS_LIBFT  = $(shell find ./lib/Libft -name '*.c')

# Object Files
OBJS_LIBFT  = $(SRCS_LIBFT:.c=.o)
OBJS        = $(SRCS:.c=.o)
OBJS_B      = $(SRCS_B:.c=.o)

all: $(NAME)

bonus: $(NAME_B)

$(NAME): $(LIBFT_A) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MACOS) $(GLFW) $(LIBFT) $(MLX) -o $(NAME)

$(NAME_B): $(LIBFT_A) $(OBJS_B)
	$(CC) $(CFLAGS) $(OBJS_B) $(MACOS) $(GLFW) $(LIBFT) $(MLX) -o $(NAME_B)

$(LIBFT_A): $(OBJS_LIBFT) $(LIBFT_H)
	ar -rcs $(LIBFT_A) $(OBJS_LIBFT)

./lib/Libft/%.o: ./lib/Libft/%.c $(LIBFT_H)
	$(CC) $(CFLAGS) -c $< -o $@

./mandatory/%.o: ./mandatory/%.c $(CUBE_H)
	$(CC) $(CFLAGS) -c $< -o $@

./bonus/%.o: ./bonus/%.c $(CUBE_B_H)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_B)
	make clean -C ./lib/Libft

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_B)
	make fclean -C ./lib/Libft

re: fclean all

.PHONY: clean
