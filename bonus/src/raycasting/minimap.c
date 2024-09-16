/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 22:27:49 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/15 22:29:54 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_line(t_cube *cube, int x0, int y0, int x1, int y1, uint32_t color)
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
		my_mlx_pixel_put2(cube, x0, y0, color);
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

void	draw_player_direction(t_cube *cube)
{
	t_ipoint start;
	t_ipoint end;
	int	color;

	start.x = 60;
	start.y = 60;
	end.x = start.x + cos(cube->plyer->derection) * 10;
	end.y = start.y + sin(cube->plyer->derection) * 10;
	color = ft_get_color(0, 0, 255, 255);
	draw_line(cube, start.x, start.y, end.x, end.y, color);
}

void	draw_rays(t_cube *cube)
{
	t_ipoint start;
	t_ipoint end;
	t_ray	*ray;
	int	color;

	color = ft_get_color(0, 204, 102, 255);
	start.x = 60;
	start.y = 60;
	for (int i = 0; i < cube->window->width; i++)
	{
		ray = &cube->ray[i];
		end.x = ray->hit.x * MINIMAP_SCALE;
		end.y = ray->hit.y * MINIMAP_SCALE;
		draw_line(cube, start.x, start.y, end.x, end.y, color);
	}

}
void	draw_rectangle(t_cube *cube, int x, int y, int size, int color)
{
	int	i;
	int	j;


	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			my_mlx_pixel_put2(cube, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void draw_grid(t_cube *cube)
{
	int color;
	int x, y;
	int minimap_width = cube->map->cols * TILE_SIZE * MINIMAP_SCALE;
	int minimap_height = cube->map->rows * TILE_SIZE * MINIMAP_SCALE;

	color = ft_get_color(100, 100, 100, 255);

	for (x = 0; x <= minimap_width; x += TILE_SIZE * MINIMAP_SCALE)
		draw_line(cube, x, 0, x, minimap_height, color);

	for (y = 0; y <= minimap_height; y += TILE_SIZE * MINIMAP_SCALE)
		draw_line(cube, 0, y, minimap_width, y, color);
}

void draw_circle(t_cube *cube, int center_x, int center_y, int radius, uint32_t color)
{
	for (int y = -radius; y <= radius; y++)
	{
		for (int x = -radius; x <= radius; x++)
		{
			if (x*x + y*y <= radius*radius)
				my_mlx_pixel_put2(cube, center_x + x, center_y + y, color);
		}
	}
}

void draw_player(t_cube *cube)
{
	int	x;
	int	y;
	int	radius;
	int	color;

	color = ft_get_color(255, 0, 0, 255);

	x = cube->plyer->s.x * MINIMAP_SCALE;
	y = cube->plyer->s.y * MINIMAP_SCALE;
	radius = TILE_SIZE / 8;
	draw_circle(cube, 60, 60, radius, color);

}

// // void draw_minimap(t_cube *cube)
// // {
// // 	int	x;
// // 	int	y;
// // 	int	map_x;
// // 	int	map_y;
// // 	int	color;


// // 	y = 0;
// // 	while (y < cube->map->rows)
// // 	{
// // 		x = 0;
// // 		while (x < cube->map->cols)
// // 		{
// // 			map_x = x * TILE_SIZE * MINIMAP_SCALE;
// // 			map_y = y * TILE_SIZE * MINIMAP_SCALE;

// // 			if (cube->map->map2d[y][x] == '1')
// // 				color = ft_get_color(0, 0, 0, 255);
// // 			else if (cube->map->map2d[y][x] == 32)
// // 				color = ft_get_color(255, 255, 255, 255);
// // 			else
// // 				color = ft_get_color(155, 118, 83, 255);

// // 			draw_rectangle(cube, map_x, map_y, TILE_SIZE * MINIMAP_SCALE, color);
// // 			x++;
// // 		}
// // 		y++;
// // 	}
// // 	draw_player_direction(cube);
// // }



// void draw_minimap(t_cube *cube)
// {
// 	int	x;
// 	int	y;
// 	int	map_x;
// 	int	map_y;
// 	int	color;


// 	int width = cube->plyer->s.y * MINIMAP_SCALE + 60;
// 	int height = cube->plyer->s.x * MINIMAP_SCALE + 60;
	
// 	y = ((cube->plyer->s.y * MINIMAP_SCALE) - 60);
// 	while (y < width)
// 	{
// 		x = ((cube->plyer->s.x * MINIMAP_SCALE) - 60);
// 		while (x < height)
// 		{
// 			map_x =x / TILE_SIZE / MINIMAP_SCALE;
// 			map_y =y / TILE_SIZE / MINIMAP_SCALE;

// 			if (map_y < 0 || map_y >= cube->map->rows || map_x < 0 || map_x >= cube->map->cols)
// 			{
// 				x++;
// 				continue;
// 			}
// 			if (cube->map->map2d[map_y][map_x] == '1')
// 				color = ft_get_color(0, 0, 0, 255);
// 			else if (cube->map->map2d[map_y][map_x] == 32)
// 				color = ft_get_color(255, 255, 255, 255);
// 			else
// 				color = ft_get_color(155, 118, 83, 255);

// 			my_mlx_pixel_put2(cube, x, y, color);
// 			x++;
// 		}
// 		y++;
// 	}
// 	draw_player_direction(cube);
// }


void clear_image(mlx_image_t *img)
{
	u_int32_t		i;
	u_int32_t 		j;

	i = 0;
	while (i < img->height)
	{
		j = 0;
		while (j < img->width)
		{
			mlx_put_pixel(img, j, i, 0);
			j++;
		}
		i++;
	}
}


void draw_minimap(t_cube *cube)
{
	int		ref_x;
	int		ref_y;
	int		start_x;
	int		start_y;

	start_y = cube->plyer->s.y - 60;
	ref_y = start_y;
	ref_x = cube->plyer->s.x - 60;
	clear_image(cube->img2);
	while (start_y < cube->plyer->s.y + 60)
	{
		start_x = cube->plyer->s.x - 60;
		while (start_x < cube->plyer->s.x + 60)
		{
			if ((0 < start_x && start_x  < (cube->map->cols * TILE_SIZE)) && \
				(0 < start_y && start_y < (cube->map->rows * TILE_SIZE)))
			{
				if (cube->map->map2d[(start_y /  TILE_SIZE)][start_x / TILE_SIZE] == '1')
					mlx_put_pixel(cube->img2, start_x - ref_x, start_y - ref_y, ft_get_color(0, 0, 0, 255));
				else
					mlx_put_pixel(cube->img2, start_x - ref_x, start_y - ref_y, ft_get_color(255, 255, 255, 255));
			}
			start_x++;
		}
		start_y++;
	}
	draw_player_direction(cube);
	draw_player(cube);
}