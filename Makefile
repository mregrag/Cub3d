# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/07 18:20:34 by mregrag           #+#    #+#              #
#    Updated: 2024/09/17 11:47:46 by aait-bab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D
NAME_B		= cub3D_bonus
LIBFT		= libft.a
LIBRAIRIE	= "./lib/libft"
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -fsanitize=address -g2
HEADERMLX	= ./MLX42/MLX42.h
HEADERLIBFT	= ./lib/Libft/libft.h
RM			= rm -rf
MLX			= ./MLX42/libmlx42.a
FLAG_MLX	= -framework Cocoa -framework OpenGL -framework IOKit -lglfw
INCLUDE		= -I/Users/${USER}/.brew/Cellar/glfw/3.4/include/GLFW
LIB			= -L/Users/${USER}/.brew/Cellar/glfw/3.4/lib

HEADERCUB	= ./include/cub3d.h ./include/macros.h ./include/objects.h

SRCS		=	./mandatory/src/parsing/ft_parse_cube.c \
			./mandatory/src/parsing/ft_parse_clrs_txtrs.c \
			./mandatory/src/parsing/ft_helpers.c \
			./mandatory/src/parsing/ft_parse_map.c \
			./mandatory/src/parsing/ft_check_dbl_keys.c \
			./mandatory/src/parsing/ft_fill_map2d.c \
			./mandatory/src/parsing/ft_valid_caras_walls.c\
			./mandatory/src/raycasting/ft_helpers.c\
			./mandatory/src/raycasting/ft_hooks.c\
			./mandatory/src/raycasting/ft_raycasting.c\
			./mandatory/src/raycasting/ft_movement.c \
			./mandatory/src/raycasting/ft_helpers1.c \
			./mandatory/src/raycasting/ft_drawing.c\
			./mandatory/src/raycasting/ft_player_walk.c \
			./mandatory/src/textures/ft_texture.c\
			./mandatory/src/textures/ft_load_txrts.c \
			./mandatory/src/utils/ft_error.c \
			./mandatory/src/utils/ft_print.c \
			./mandatory/src/utils/ft_trim.c \
			./mandatory/src/utils/ft_clear_img.c \
			./mandatory/src/utils/ft_get_cube.c \
			./mandatory/src/utils/ft_destroy_all.c \
			./mandatory/src/utils/ft_init_cube.c \
			./mandatory/src/main.c

SRCSB		=	./bonus/src/parsing/ft_parse_cube_bonus.c \
			./bonus/src/parsing/ft_parse_clrs_txtrs_bonus.c \
			./bonus/src/parsing/ft_helpers_bonus.c \
			./bonus/src/parsing/ft_parse_map_bonus.c \
			./bonus/src/parsing/ft_check_dbl_keys_bonus.c \
			./bonus/src/parsing/ft_fill_map2d_bonus.c \
			./bonus/src/parsing/ft_valid_caras_walls_bonus.c\
			./bonus/src/sprites/ft_load_sprites_bonus.c\
			./bonus/src/sprites/ft_sprites_bonus.c\
			./bonus/src/raycasting/ft_helpers_bonus.c\
			./bonus/src/raycasting/ft_hooks_bonus.c\
			./bonus/src/raycasting/ft_raycasting_bonus.c\
			./bonus/src/raycasting/ft_movement_bonus.c \
			./bonus/src/raycasting/ft_helpers1_bonus.c \
			./bonus/src/raycasting/ft_drawing_bonus.c\
			./bonus/src/raycasting/ft_player_walk_bonus.c \
			./bonus/src/raycasting/ft_minimap_bonus.c\
			./bonus/src/raycasting/ft_draw_player_bonus.c\
			./bonus/src/textures/ft_texture_bonus.c \
			./bonus/src/textures/ft_load_txrts_bonus.c \
			./bonus/src/utils/ft_error_bonus.c \
			./bonus/src/utils/ft_print_bonus.c \
			./bonus/src/utils/ft_trim_bonus.c \
			./bonus/src/utils/ft_clear_img_bonus.c \
			./bonus/src/utils/ft_get_cube_bonus.c \
			./bonus/src/utils/ft_destroy_all_bonus.c \
			./bonus/src/utils/ft_init_cube_bonus.c \
			./bonus//src/minimap_debug.c \
			./bonus/src/main_bonus.c 

OBJS		=	$(SRCS:.c=.o)
OBJS_B		=	$(SRCSB:.c=.o)

all: $(NAME)

$(LIBFT):
	@make -C $(LIBRAIRIE)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(FLAG_MLX) $(LIB) $(OBJS) $(MLX) -L$(LIBRAIRIE) -o $(NAME) -lft

%.o: %.c $(HEADERCUB) $(HEADERLIBFT) $(HEADERMLX)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

bonus: $(OBJS_B)
	@make -C $(LIBRAIRIE)
	@$(CC) $(CFLAGS) $(FLAG_MLX) $(LIB) $(OBJS_B) $(MLX) -L$(LIBRAIRIE) -o $(NAME_B) -lft
clean:
	@make clean -C $(LIBRAIRIE)
	@$(RM) $(OBJS)
	@$(RM) $(OBJS_B)

fclean: clean
	@make fclean -C $(LIBRAIRIE)
	@$(RM) $(NAME)
	@$(RM) $(NAME_B)

re: fclean all

.PHONY: clean
