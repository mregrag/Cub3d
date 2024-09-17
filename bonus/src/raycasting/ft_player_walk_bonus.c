/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_walk_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:33:54 by aait-bab          #+#    #+#             */
/*   Updated: 2024/09/17 13:04:11 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void    check_horizontal_move(t_cube *cube, double new_x, double move_x)
{
	int    map_x;
	int    map_y_up;
	int    map_y_down;

	if (move_x > 0)
		map_x = (int)((new_x + COLLISION) / TILE_SIZE);
	else
		map_x = (int)((new_x - COLLISION) / TILE_SIZE);
	map_y_up = (int)((cube->plyer->s.y - COLLISION) / TILE_SIZE);
	map_y_down = (int)((cube->plyer->s.y + COLLISION) / TILE_SIZE);
	if (cube->map->map2d[map_y_up][map_x] != '1'
		|| cube->map->map2d[map_y_down][map_x] != '1')
		cube->plyer->s.x = new_x;
}

static void    check_vertical_move(t_cube *cube, double new_y, double move_y)
{
	int    map_y;
	int    map_x_left;
	int    map_x_right;

	if (move_y > 0)
		map_y = (int)((new_y + COLLISION) / TILE_SIZE);
	else
		map_y = (int)((new_y - COLLISION) / TILE_SIZE);
	map_x_left = (int)((cube->plyer->s.x - COLLISION) / TILE_SIZE);
	map_x_right = (int)((cube->plyer->s.x + COLLISION) / TILE_SIZE);
	if (cube->map->map2d[map_y][map_x_left] != '1'
		|| cube->map->map2d[map_y][map_x_right] != '1')
		cube->plyer->s.y = new_y;
}

void    walk_player(t_cube *cube, double move_x, double move_y)
{
	int    new_x;
	int    new_y;

	new_x = floor(cube->plyer->s.x + move_x);
	new_y = cube->plyer->s.y + move_y;
	check_horizontal_move(cube, new_x, move_x);
	check_vertical_move(cube, new_y, move_y);
}
