/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_walk_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:15:24 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/29 07:06:41 by mregrag          ###   ########.fr       */
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

static void	toggle_door(double x, double y, t_cube *cube)
{
	t_ipoint	m;

	m.x = floor(x / TILE_SIZE);
	m.y = floor(y / TILE_SIZE);
	if (m.y < 0 || m.y >= cube->map->width
		|| m.x < 0 || m.x >= cube->map->height)
		return ;
	if (cube->map->map2d[m.y][m.x] == 'D')
	{
		cube->door->pos.x = m.x;
		cube->door->pos.y = m.y;
		cube->door->is_door_closed = 0;
		cube->map->map2d[m.y][m.x] = '0';
	}
}

static void	close_door(t_cube *cube)
{
	t_ipoint	p_m;

	p_m.x = floor(cube->plyer->s.x / TILE_SIZE);
	p_m.y = floor(cube->plyer->s.y / TILE_SIZE);
	if (abs(p_m.x - cube->door->pos.x) > 1
		|| abs(p_m.y - cube->door->pos.y) > 1)
	{
		cube->map->map2d[cube->door->pos.y][cube->door->pos.x] = 'D';
		cube->door->is_door_closed = 1;
	}
}

void	walk_player(t_cube *cube, double move_x, double move_y)
{
	int		new_x;
	int		new_y;
	double	front_x;
	double	front_y;
	double	angle;

	angle = cube->plyer->derection;
	new_x = round(cube->plyer->s.x + move_x);
	new_y = round(cube->plyer->s.y + move_y);
	if (cube->door->is_door_open)
	{
		front_x = cube->plyer->s.x + cos(angle) * TILE_SIZE / 2;
		front_y = cube->plyer->s.y + sin(angle) * TILE_SIZE / 2;
		toggle_door(front_x, front_y, cube);
		cube->door->is_door_open = 0;
	}
	if (!check_collision(cube, new_x, cube->plyer->s.y))
		cube->plyer->s.x = new_x;
	if (!check_collision(cube, cube->plyer->s.x, new_y))
		cube->plyer->s.y = new_y;
	if (!cube->door->is_door_closed)
		close_door(cube);
}
