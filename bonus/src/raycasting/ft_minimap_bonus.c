/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 21:33:16 by aait-bab          #+#    #+#             */
/*   Updated: 2024/10/02 17:22:18 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	draw_player_direction(t_cube *cube)
{
	t_ipoint	center;
	int			i;
	int			x;
	int			y;

	center.x = MINI_W / 2;
	center.y = MINI_H / 2;
	i = 0;
	while (i < 10)
	{
		x = center.x + i * cos(cube->plyer->derection);
		y = center.y + i * sin(cube->plyer->derection);
		my_pixel_put(cube->img, x, y, BLUE);
		i++;
	}
}

void	draw_player(t_cube *cube)
{
	t_ipoint	center;
	int			x;
	int			y;

	center.x = MINI_W / 2;
	center.y = MINI_H / 2;
	y = center.y - PLAYER_SIZE;
	while (y < center.y + PLAYER_SIZE)
	{
		x = center.x - PLAYER_SIZE;
		while (x < center.x + PLAYER_SIZE)
		{
			if (pow(x - center.x, 2) + pow(y - center.y, 2) < 8)
				my_pixel_put(cube->img, x, y, RED);
			x++;
		}
		y++;
	}
}

void	render_minimap(t_cube *cube, t_ipoint *map, int x, int y)
{
	if (map->y >= 0 && map->x >= 0
		&& map->x < cube->map->height
		&& map->y < cube->map->width)
	{
		if (cube->map->map2d[map->y][map->x] == '1')
			my_pixel_put(cube->img, x, y, BLACK);
		else if (cube->map->map2d[map->y][map->x] == 'D')
			my_pixel_put(cube->img, x, y, RED);
		else
			my_pixel_put(cube->img, x, y, WHITE);
	}
	else
		my_pixel_put(cube->img, x, y, BLACK);
}

void	draw_minimap(t_cube *cube)
{
	t_ipoint	player;
	t_ipoint	map;
	int			y;
	int			x;

	player.x = (cube->plyer->s.x / TILE_SIZE) * MINI_S - MINI_W / 2;
	player.y = (cube->plyer->s.y / TILE_SIZE) * MINI_S - MINI_H / 2;
	y = 0;
	while (y < MINI_H)
	{
		x = 0;
		while (x < MINI_W)
		{
			map.x = (x + player.x) / MINI_S;
			map.y = (y + player.y) / MINI_S;
			if (pow(x - RADIUS, 2)
				+ pow(y - RADIUS, 2) <= pow(RADIUS, 2))
				render_minimap(cube, &map, x, y);
			x++;
		}
		y++;
	}
	draw_player(cube);
	draw_player_direction(cube);
}
