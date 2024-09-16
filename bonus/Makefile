# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/07 18:20:34 by mregrag           #+#    #+#              #
#    Updated: 2024/09/14 11:58:45 by mregrag          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D
LIBFT		= libft.a
LIBRAIRIE	= "lib/libft"
CC		= cc
CFLAGS		= -Wall -Wextra -Werror -fsanitize=address -g2
HEADERMLX	= ./MLX42/MLX42.h
HEADERLIBFT	= ./lib/Libft/libft.h
RM		= rm -rf

MLX		= ./MLX42/libmlx42.a
FLAG_MLX	= -framework Cocoa -framework OpenGL -framework IOKit -lglfw
INCLUDE		= -I/Users/${USER}/.brew/Cellar/glfw/3.4/include/GLFW
LIB		= -L/Users/${USER}/.brew/Cellar/glfw/3.4/lib

PARSING		:=	src/parsing/ft_parse_cube.c \
				src/parsing/ft_parse_clrs_txtrs.c src/parsing/ft_helpers.c  \
				src/parsing/ft_parse_map.c src/parsing/ft_check_dbl_keys.c\
				src/parsing/ft_fill_map2d.c src/parsing/ft_valid_caras_walls.c\

HEADERCUB	= ./include/cub3d.h \
		  ./include/macros.h \
		  ./include/objects.h

RAYCASTING	:=	src/raycasting/utils.c\
			src/raycasting/hooks.c \
			src/raycasting/raycasting.c \
			src/raycasting/movement.c \
			src/raycasting/utils1.c\
			src/raycasting/drawing.c \
			src/raycasting/minimap.c \
			src/raycasting/debug.c \

TEXTURS		:=	src/textures/texture.c

UTILS		:=	src/utils/ft_error.c src/utils/ft_print.c src/utils/ft_trim.c\

MAIN		:=	src/main.c

SRCS		:= $(MAIN) \
		   $(RAYCASTING) \
		   $(PARSING) \
		   $(UTILS) \
		   $(TEXTURS) \


# SRCS		:=	$(PARSING)\
# 			$(RAYCASTING)\
# 			$(TEXTURS)\
# 			$(UTILS)\
# 			$(MAIN)\

OBJS		:=	$(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	@make -C $(LIBRAIRIE)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(FLAG_MLX) $(LIB) $(OBJS) $(MLX) -L$(LIBRAIRIE) -o $(NAME) -lft

%.o: %.c $(HEADERCUB) $(HEADERLIBFT) $(HEADERMLX)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@make clean -C $(LIBRAIRIE)
	@$(RM) $(OBJS)

fclean: clean
	@make fclean -C $(LIBRAIRIE)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean
