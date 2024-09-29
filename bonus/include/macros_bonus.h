/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:19:54 by aait-bab          #+#    #+#             */
/*   Updated: 2024/09/29 04:44:43 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_BONUS_H
# define MACROS_BONUS_H

# include <MLX42.h>
# include "../../lib/Libft/libft.h"
# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <fcntl.h>

#define MINIMAP_SIZE 120
#define WALL_COLOR 0xFFFFFF  // White
#define FLOOR_COLOR 0x808080 // Gray
#define PLAYER_COLOR 0xFF0000 // 
# define WIDTH 1700
# define HEIGHT 900
# define TILE_SIZE 32
# define FOV 60
# define ROTATION_SPEED 0.045
# define MOVE_SPEED 4
# define COLLISION  3
#define MINIMAP_SCALE 0.8
#define PLAYER_DOT_SIZE 3

#endif
