/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_walk_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:15:24 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/18 21:27:50 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	is_wall(t_cube *cube, int x, int y)
{
	int	map_y;
	int	map_x;

	map_x = x / TILE_SIZE;
	map_y = y / TILE_SIZE;
	return (cube->map->map2d[map_y][map_x] == '1');
}

static int	check_collision(t_cube *cube, int x, int y)
{
	return (is_wall(cube, x - COLLISION, y - COLLISION)
		|| is_wall(cube, x + COLLISION, y - COLLISION)
		|| is_wall(cube, x - COLLISION, y + COLLISION)
		|| is_wall(cube, x + COLLISION, y + COLLISION));
}

void	walk_player(t_cube *cube, double move_x, double move_y)
{
	double	new_x;
	double	new_y;

	new_x = roundf(cube->plyer->s.x + move_x);
	new_y = roundf(cube->plyer->s.y + move_y);
	if (!check_collision(cube, new_x, cube->plyer->s.y))
		cube->plyer->s.x = new_x;
	if (!check_collision(cube, cube->plyer->s.x, new_y))
		cube->plyer->s.y = new_y;
}
