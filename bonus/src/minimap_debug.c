/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_debug.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:54:59 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/18 15:18:35 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_line_dg(t_cube *cube, int x0, int y0, int x1, int y1, uint32_t color)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;

	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	sx = 1;
	sy = 1;
	if (x0 > x1)
		sx = -1;
	if (y0 > y1)
		sy = -1;
	err = dx - dy;
	while (1)
	{
		my_mlx_pixel_put(cube, x0, y0, color);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

void	draw_player_direction_dg(t_cube *cube)
{
	t_ipoint start;
	t_ipoint end;
	int	color;

	start.x = cube->plyer->s.x * MINIMAP_SCALE;
	start.y = cube->plyer->s.y * MINIMAP_SCALE;
	end.x = start.x + cos(cube->plyer->derection) * (TILE_SIZE * MINIMAP_SCALE);
	end.y = start.y + sin(cube->plyer->derection) * (TILE_SIZE * MINIMAP_SCALE);
	color = ft_get_color(0, 0, 255, 255);
	draw_line_dg(cube, start.x, start.y, end.x, end.y, color);
}

void	draw_rays_dg(t_cube *cube)
{
	t_ipoint start;
	t_ipoint end;
	t_ray	*ray;
	int	color;

	color = ft_get_color(0, 204, 102, 255);
	start.x = cube->plyer->s.x * MINIMAP_SCALE;
	start.y = cube->plyer->s.y * MINIMAP_SCALE;
	for (int i = 0; i < cube->window->width; i++)
	{
		ray = &cube->ray[i];
		end.x = ray->hit.x * MINIMAP_SCALE;
		end.y = ray->hit.y * MINIMAP_SCALE;
		draw_line_dg(cube, start.x, start.y, end.x, end.y, color);
	}

}
void	draw_rectangle_dg(t_cube *cube, int x, int y, int size, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			my_mlx_pixel_put(cube, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void draw_grid_dg(t_cube *cube)
{
	int color;
	int x, y;
	int minimap_width = cube->map->height * TILE_SIZE * MINIMAP_SCALE;
	int minimap_height = cube->map->width * TILE_SIZE * MINIMAP_SCALE;

	color = ft_get_color(100, 100, 100, 255);

	for (x = 0; x <= minimap_width; x += TILE_SIZE * MINIMAP_SCALE)
		draw_line_dg(cube, x, 0, x, minimap_height, color);

	for (y = 0; y <= minimap_height; y += TILE_SIZE * MINIMAP_SCALE)
		draw_line_dg(cube, 0, y, minimap_width, y, color);
}

void draw_circle_dg(t_cube *cube, int center_x, int center_y, int radius, uint32_t color)
{
	for (int y = -radius; y <= radius; y++)
	{
		for (int x = -radius; x <= radius; x++)
		{
			if (x*x + y*y <= radius*radius)
				my_mlx_pixel_put(cube, center_x + x, center_y + y, color);
		}
	}
}

void draw_player_dg(t_cube *cube)
{
	int	x;
	int	y;
	int	radius;
	int	color;

	color = ft_get_color(255, 0, 0, 255);

	x = cube->plyer->s.x * MINIMAP_SCALE;
	y = cube->plyer->s.y * MINIMAP_SCALE;
	radius = TILE_SIZE / 8;
	draw_circle_dg(cube, x, y, radius, color);

}

void	minimap_debug(t_cube *cube)
{
	int	x;
	int	y;
	int	map_x;
	int	map_y;
	int	color;


	y = 0;
	while (y < cube->map->width)
	{
		x = 0;
		while (x < cube->map->height)
		{
			map_x = x * TILE_SIZE * MINIMAP_SCALE;
			map_y = y * TILE_SIZE * MINIMAP_SCALE;

			if (cube->map->map2d[y][x] == '1')
				color = ft_get_color(0, 0, 0, 255);
			else if (cube->map->map2d[y][x] == 32)
				color = ft_get_color(0, 255, 0, 255);
			else
				color = ft_get_color(255, 255, 255, 255);

			draw_rectangle_dg(cube, map_x, map_y, TILE_SIZE * MINIMAP_SCALE, color);
			x++;
		}
		y++;
	}
	draw_player_direction_dg(cube);
}

