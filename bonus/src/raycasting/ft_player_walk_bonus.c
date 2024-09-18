/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_walk_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:15:24 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/18 12:30:25 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	check_horizontal_move(t_cube *cube, int new_x, int move_x)
{
	int	map_x;
	int	map_y_up;
	int	map_y_down;

	if (move_x > 0)
		map_x = (new_x + COLLISION) / TILE_SIZE;
	else
		map_x = (new_x - COLLISION) / TILE_SIZE;
	map_y_up = roundf(cube->plyer->s.y - COLLISION) / TILE_SIZE;
	map_y_down = roundf(cube->plyer->s.y + COLLISION) / TILE_SIZE;
	if (cube->map->map2d[map_y_up][map_x] != '1'
			|| cube->map->map2d[map_y_down][map_x] != '1')
		cube->plyer->s.x = new_x;
}

static void	check_vertical_move(t_cube *cube, int new_y, int move_y)
{
	int	map_y;
	int	map_x_left;
	int	map_x_right;

	if (move_y > 0)
		map_y = (new_y + COLLISION) / TILE_SIZE;
	else
		map_y = (new_y - COLLISION) / TILE_SIZE;
	map_x_left = roundf(cube->plyer->s.x - COLLISION) / TILE_SIZE;
	map_x_right = roundf(cube->plyer->s.x + COLLISION) / TILE_SIZE;
	if (cube->map->map2d[map_y][map_x_left] != '1'
			|| cube->map->map2d[map_y][map_x_right] != '1')
		cube->plyer->s.y = new_y;
}

void	walk_player(t_cube *cube, double move_x, double move_y)
{
	int	new_x;
	int	new_y;

	new_x = roundf(cube->plyer->s.x + move_x);
	new_y = roundf(cube->plyer->s.y + move_y);
	if (cube->map->map2d[new_y / TILE_SIZE][new_x / TILE_SIZE] != '1')
	{
		check_horizontal_move(cube, new_x, move_x);
		check_vertical_move(cube, new_y, move_y);
	}
}
