/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 06:30:06 by mregrag           #+#    #+#             */
/*   Updated: 2024/08/25 23:41:30 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include <math.h>

void	turn_player(t_mlx *mlx, int turn)
{
	if (turn == RIGHT)
	{
		mlx->plyer->derection += ROTATION_SPEED;
		if (mlx->plyer->derection > 2 * M_PI)
			mlx->plyer->derection -= 2 * M_PI;
		// reset_angle(mlx->plyer->derection);
	}
	else if (turn == LEFT)
	{
		mlx->plyer->derection -= ROTATION_SPEED;
		if (mlx->plyer->derection < 0)
			mlx->plyer->derection += 2 * M_PI;
		// reset_angle(mlx->plyer->derection);
	}
}

void	walk_player(t_mlx *mlx, double move_x, double move_y)
{
	int		map_y;
	int		map_x;
	int		new_x;
	int		new_y;

	new_x = roundf(mlx->plyer->plyr_x + move_x);
	new_y = roundf(mlx->plyer->plyr_y + move_y);
	map_x = (new_x / TILE_SIZE);
	map_y = (new_y / TILE_SIZE);
	if (mlx->map->map2d[map_y][map_x] != '1' && \
	(mlx->map->map2d[map_y][mlx->plyer->plyr_x / TILE_SIZE] != '1' && \
	mlx->map->map2d[mlx->plyer->plyr_y / TILE_SIZE][map_x] != '1'))
	{
		mlx->plyer->plyr_x = new_x;
		mlx->plyer->plyr_y = new_y;
	}
}

void	movement(t_mlx *mlx, double move_x, double move_y)
{
	if (mlx->plyer->turn == RIGHT)
		turn_player(mlx, RIGHT);
	if (mlx->plyer->turn == LEFT)
		turn_player(mlx, LEFT);
	if (mlx->plyer->walk == RIGHT)
	{
		move_x = -sin(mlx->plyer->derection) * MOVE_SPEED;
		move_y = cos(mlx->plyer->derection) * MOVE_SPEED;
	}
	if (mlx->plyer->walk == LEFT)
	{
		move_x = sin(mlx->plyer->derection) * MOVE_SPEED;
		move_y = -cos(mlx->plyer->derection) * MOVE_SPEED;
	}
	if (mlx->plyer->walk == UP)
	{
		move_x = cos(mlx->plyer->derection) * MOVE_SPEED;
		move_y = sin(mlx->plyer->derection) * MOVE_SPEED;
	}
	if (mlx->plyer->walk == DOWN)
	{
		move_x = -cos(mlx->plyer->derection) * MOVE_SPEED;
		move_y = -sin(mlx->plyer->derection) * MOVE_SPEED;
	}
	walk_player(mlx, move_x, move_y);
}
