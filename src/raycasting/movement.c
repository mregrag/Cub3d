/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 06:30:06 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/13 04:55:00 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"


void	walk_player(t_cube *cube, double move_x, double move_y)
{
	int		map_y;
	int		map_x;
	int		new_x;
	int		new_y;

	new_x = roundf(cube->plyer->s.x + move_x);
	new_y = roundf(cube->plyer->s.y + move_y);
	map_x = (new_x / TILE_SIZE);
	map_y = (new_y / TILE_SIZE);
	if (cube->map->map2d[map_y][map_x] != '1' && \
	(cube->map->map2d[map_y][cube->plyer->s.x / TILE_SIZE] != '1' && \
	cube->map->map2d[cube->plyer->s.y / TILE_SIZE][map_x] != '1'))
	{
		cube->plyer->s.x = new_x;
		cube->plyer->s.y = new_y;
	}
}

void	movement(t_cube *cube, double move_x, double move_y)
{
	if (cube->plyer->turn == RIGHT)
		turnright(&cube->plyer->derection);
	if (cube->plyer->turn == LEFT)
		turnleft(&cube->plyer->derection);
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
