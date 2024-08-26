/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 06:30:06 by mregrag           #+#    #+#             */
/*   Updated: 2024/08/26 11:34:20 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	turn_player(t_cube *cube, int turn)
{
	if (turn == RIGHT)
	{
		cube->plyer->derection += ROTATION_SPEED;
		if (cube->plyer->derection > 2 * M_PI)
			cube->plyer->derection -= 2 * M_PI;
		// reset_angle(cube->plyer->derection);
	}
	else if (turn == LEFT)
	{
		cube->plyer->derection -= ROTATION_SPEED;
		if (cube->plyer->derection < 0)
			cube->plyer->derection += 2 * M_PI;
		// reset_angle(cube->plyer->derection);
	}
}

void	walk_player(t_cube *cube, double move_x, double move_y)
{
	int		map_y;
	int		map_x;
	int		new_x;
	int		new_y;

	new_x = roundf(cube->plyer->plyr_x + move_x);
	new_y = roundf(cube->plyer->plyr_y + move_y);
	map_x = (new_x / TILE_SIZE);
	map_y = (new_y / TILE_SIZE);
	if (cube->map->map2d[map_y][map_x] != '1' && \
	(cube->map->map2d[map_y][cube->plyer->plyr_x / TILE_SIZE] != '1' && \
	cube->map->map2d[cube->plyer->plyr_y / TILE_SIZE][map_x] != '1'))
	{
		cube->plyer->plyr_x = new_x;
		cube->plyer->plyr_y = new_y;
	}
}

void	movement(t_cube *cube, double move_x, double move_y)
{
	if (cube->plyer->turn == RIGHT)
		turn_player(cube, RIGHT);
	if (cube->plyer->turn == LEFT)
		turn_player(cube, LEFT);
	if (cube->plyer->walk == RIGHT)
	{
		move_x = -sin(cube->plyer->derection) * MOVE_SPEED;
		move_y = cos(cube->plyer->derection) * MOVE_SPEED;
	}
	if (cube->plyer->walk == LEFT)
	{
		move_x = sin(cube->plyer->derection) * MOVE_SPEED;
		move_y = -cos(cube->plyer->derection) * MOVE_SPEED;
	}
	if (cube->plyer->walk == UP)
	{
		move_x = cos(cube->plyer->derection) * MOVE_SPEED;
		move_y = sin(cube->plyer->derection) * MOVE_SPEED;
	}
	if (cube->plyer->walk == DOWN)
	{
		move_x = -cos(cube->plyer->derection) * MOVE_SPEED;
		move_y = -sin(cube->plyer->derection) * MOVE_SPEED;
	}
	walk_player(cube, move_x, move_y);
}
