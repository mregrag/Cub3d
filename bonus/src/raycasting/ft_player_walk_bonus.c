/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_walk_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:15:24 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/03 22:33:10 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

static int	check_collision(t_cube *cube, int x, int y)
{
	return (is_wall_or_door(x - COLLISION, y - COLLISION, cube)
		|| is_wall_or_door(x + COLLISION, y - COLLISION, cube)
		|| is_wall_or_door(x - COLLISION, y + COLLISION, cube)
		|| is_wall_or_door(x + COLLISION, y + COLLISION, cube));
}

static void	open_the_door(t_cube *cube)
{
	t_dpoint	front;
	t_ipoint	m;
	double		angle;

	angle = cube->plyer->derection;
	front.x = cube->plyer->s.x + cos(angle) * TILE_SIZE;
	front.y = cube->plyer->s.y + sin(angle) * TILE_SIZE;
	m.x = floor(front.x / TILE_SIZE);
	m.y = floor(front.y / TILE_SIZE);
	if (m.y < 0 || m.y >= cube->map->width
		|| m.x < 0 || m.x >= cube->map->height)
		return ;
	if (cube->map->map2d[m.y][m.x] == 'D' && cube->door->is_door_open)
	{
		if (cube->door->is_door_closed)
		{
			cube->door->pos.x = m.x;
			cube->door->pos.y = m.y;
			cube->door->is_door_closed = 0;
			cube->map->map2d[m.y][m.x] = '0';
		}
	}
}

static void	close_the_door(t_cube *cube)
{
	t_dpoint	player;
	t_dpoint	door;
	double		distance;

	player.x = cube->plyer->s.x;
	player.y = cube->plyer->s.y;
	door.x = (cube->door->pos.x + 0.5) * TILE_SIZE;
	door.y = (cube->door->pos.y + 0.5) * TILE_SIZE;
	distance = sqrt(pow(player.x - door.x, 2) + pow(player.y - door.y, 2));
	if (distance >= TILE_SIZE)
	{
		cube->map->map2d[cube->door->pos.y][cube->door->pos.x] = 'D';
		cube->door->is_door_closed = 1;
	}
}

void	walk_player(t_cube *cube, double move_x, double move_y)
{
	int	new_x;
	int	new_y;

	new_x = round(cube->plyer->s.x + move_x);
	new_y = round(cube->plyer->s.y + move_y);
	if (cube->door->is_door_open)
	{
		open_the_door(cube);
		cube->door->is_door_open = 0;
	}
	if (!check_collision(cube, new_x, cube->plyer->s.y))
		cube->plyer->s.x = new_x;
	if (!check_collision(cube, cube->plyer->s.x, new_y))
		cube->plyer->s.y = new_y;
	if (!cube->door->is_door_closed)
		close_the_door(cube);
}
