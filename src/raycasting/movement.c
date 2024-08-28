/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 06:30:06 by mregrag           #+#    #+#             */
/*   Updated: 2024/08/28 04:56:45 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	walk_player(t_cube *cube, double move_x, double move_y)
{
	int		map_y;
	int		map_x;
	int		new_x;
	int		new_y;

	new_x = floor(cube->plyer->x + move_x);
	new_y = floor(cube->plyer->y + move_y);
	map_x = (new_x / TILE_SIZE); //translate new position x to grid map
	map_y = (new_y / TILE_SIZE); //translate new position y to grid map

	//only set new player position if it is not colliding with the map walls
	if (cube->map->map2d[map_y][map_x] != '1')
	{
		cube->plyer->x = new_x;
		cube->plyer->y = new_y;
	}
}

void	movement(t_cube *cube, double move_x, double move_y)
{
	if (cube->plyer->turn == RIGHT)
		turnright(&cube->plyer->derection);
	else if (cube->plyer->turn == LEFT)
		turnleft(&cube->plyer->derection);
	else if (cube->plyer->walk == RIGHT)
	{
		move_x = -sin(cube->plyer->derection) * MOVE_SPEED;
		move_y = cos(cube->plyer->derection) * MOVE_SPEED;
	}
	else if (cube->plyer->walk == LEFT)
	{
		move_x = sin(cube->plyer->derection) * MOVE_SPEED;
		move_y = -cos(cube->plyer->derection) * MOVE_SPEED;
	}
	else if (cube->plyer->walk == UP)
	{
		move_x = cos(cube->plyer->derection) * MOVE_SPEED;
		move_y = sin(cube->plyer->derection) * MOVE_SPEED;
	}
	else if (cube->plyer->walk == DOWN)
	{
		move_x = -cos(cube->plyer->derection) * MOVE_SPEED;
		move_y = -sin(cube->plyer->derection) * MOVE_SPEED;
	}
	walk_player(cube, move_x, move_y);
}
