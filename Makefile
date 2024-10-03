# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/20 17:26:43 by mregrag           #+#    #+#              #
#    Updated: 2024/10/03 19:07:22 by mregrag          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project names
NAME        = cub3D
NAME_B      = cub3D_bonus

# Compiler and flags
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -f

LIBFT_DIR   = lib/Libft
LIBFT_A     = $(LIBFT_DIR)/libft.a
LIBFT       = -L$(LIBFT_DIR) -lft

GLFW        = -L$(HOME)/.brew/Cellar/glfw/3.4/lib -lglfw
MLX         = -L$(HOME)/.local/lib -lmlx42
MACOS       = -framework Cocoa -framework OpenGL -framework IOKit

# Headers
LIBFT_H     = $(shell find $(LIBFT_DIR) -name '*.h')
CUBE_H      = $(shell find ./mandatory/include -name '*.h')
CUBE_B_H    = $(shell find ./bonus/include -name '*_bonus.h')

# Source and Object Files
SRCS        = $(shell find ./mandatory/src -name '*.c')
SRCS_B      = $(shell find ./bonus/src -name '*_bonus.c')
SRCS_LIBFT  = $(shell find ./lib/libft -name '*.c')

OBJS_LIBFT  = $(SRCS_LIBFT:.c=.o)
OBJS        = $(SRCS:.c=.o)
OBJS_B      = $(SRCS_B:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MACOS) $(GLFW) $(LIBFT) $(MLX) -o $(NAME)

bonus: $(LIBFT_A) $(OBJS_B)
	$(CC) $(CFLAGS) $(OBJS_B) $(MACOS) $(GLFW) $(LIBFT) $(MLX) -o $(NAME_B)

./mandatory/%.o: ./mandatory/%.c $(CUBE_H)
	$(CC) $(CFLAGS) -c $< -o $@

./bonus/%.o: ./bonus/%.c $(CUBE_B_H)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_A): $(OBJS_LIBFT) $(LIBFT_H)
	make -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS) $(OBJS_B)
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME) $(NAME_B)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: clean
