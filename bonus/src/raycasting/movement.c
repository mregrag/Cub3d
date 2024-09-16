/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 06:30:06 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/15 23:12:08 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include <math.h>

static void	walk_player(t_cube *cube, double move_x, double move_y, int flag_dir)
{
	int		map_y;
	int		map_x;
	int		new_x;
	int		new_y;

	(void)flag_dir;
	new_x = round(cube->plyer->s.x + move_x);
	new_y = round(cube->plyer->s.y + move_y);
	printf("new_x = %d, new_y = %d\n", new_x, new_y);
	map_x = (new_x / TILE_SIZE);
	map_y = (new_y / TILE_SIZE);
	//printf("map_x = %d, map_y = %d\n", map_x, map_y);
	// if (flag_dir == UP)
	// 	map_x -= 3;
	// else if (flag_dir == DOWN)
	// 	map_x += 3;
	// if (flag_dir == LEFT)
	// 	map_y -= 3;
	// else if (flag_dir == RIGHT)
	// 	map_y += 3;
	if (cube->map->map2d[map_y][map_x] != '1')
	{
		cube->plyer->s.x = new_x;
		cube->plyer->s.y = new_y;
	}
}

static void	turnright(t_cube *cube)
{
	cube->plyer->derection += ROTATION_SPEED;
	if (cube->plyer->derection > 2 * M_PI)
		cube->plyer->derection -= 2 * M_PI;
}

static void	turnleft(t_cube *cube)
{
	cube->plyer->derection -= ROTATION_SPEED;
	if (cube->plyer->derection < 2 * M_PI)
		cube->plyer->derection += 2 * M_PI;
}
void	movement(t_cube *cube, double move_x, double move_y)
{
	printf("angle = %f\n", cube->plyer->derection);
	if (cube->plyer->turn == TURN_RIGHT)
		turnright(cube);
	if (cube->plyer->turn == TURN_LEFT)
		turnleft(cube);
	if (cube->plyer->walk == RIGHT)
	{
		move_x = -sin(cube->plyer->derection) * MOVE_SPEED;
		move_y = -cos(cube->plyer->derection) * MOVE_SPEED;
	}
	if (cube->plyer->walk == LEFT)
	{
		move_x = -sin(cube->plyer->derection) * MOVE_SPEED;
		move_y = -cos(cube->plyer->derection) * MOVE_SPEED;
	}
	if (cube->plyer->walk == UP)
	{
		move_x = -cos(cube->plyer->derection) * MOVE_SPEED;
		move_y = -sin(cube->plyer->derection) * MOVE_SPEED;
	}
	if (cube->plyer->walk == DOWN)
	{
		move_x = -cos(cube->plyer->derection) * MOVE_SPEED;
		move_y = -sin(cube->plyer->derection) * MOVE_SPEED;
	}
	walk_player(cube, move_x, move_y, cube->plyer->walk);
}
