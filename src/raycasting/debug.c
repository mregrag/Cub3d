/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:23:08 by mregrag           #+#    #+#             */
/*   Updated: 2024/08/25 22:23:01 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_grid(mlx_image_t *img, uint32_t color, int tile_size)
{
	int	width;
	int	height;
	int	x;
	int	y;

	width = img->width;
	height = img->height;
	y = 0;
	x = 0;
	for (int x = 0; x < width; x += tile_size)
		for (int y = 0; y < height; y++)
			mlx_put_pixel(img, x, y, color);

	for (int y = 0; y < height; y += tile_size)
		for (int x = 0; x < width; x++)
			mlx_put_pixel(img, x, y, color);
}

void draw_player(t_mlx *mlx)
{
	int i;
	int j;
	int center_x;
	int center_y;
	int radius;

	center_x = mlx->plyer->plyr_x;
	center_y = mlx->plyer->plyr_y;
	radius = TILE_SIZE / 6;

	for (i = center_y - radius; i <= center_y + radius; i++)
	{
		for (j = center_x - radius; j <= center_x + radius; j++)
			if (pow(j - center_x, 2) + pow(i - center_y, 2) <= pow(radius, 2))
				mlx_put_pixel(mlx->img, j, i, ft_get_color(197, 25, 0, 255));
	}
}

void draw_ray(t_mlx *mlx, double ray_angle)
{
    double ray_x = mlx->plyer->plyr_x;
    double ray_y = mlx->plyer->plyr_y;
    double x_step = cos(ray_angle);
    double y_step = sin(ray_angle);

    while (1)
    {
        int map_x = (int)(ray_x / TILE_SIZE);
        int map_y = (int)(ray_y / TILE_SIZE);

        if (map_x < 0 || map_x >= 26 || map_y < 0 || map_y >= 14
            || mlx->map->map2d[map_y][map_x] == '1')
	{
            break;
        }
        mlx_put_pixel(mlx->img, (int)ray_x, (int)ray_y, ft_get_color(16, 166, 0, 255));
        ray_x += x_step;
        ray_y += y_step;
    }
}

void	draw_rays(t_mlx *mlx)
{
	for (int i = 0; i < WIDTH; i++)
	{
		draw_ray(mlx, mlx->rays->ray_angl);
		mlx->rays->ray_angl += mlx->plyer->fov / WIDTH;
	}
}

void	draw_mini_map(mlx_image_t *img, int x, int y, int color)
{
	int	i;
	int	j;
	int	start_x;
	int	start_y;

	start_x = x * TILE_SIZE;
	start_y = y * TILE_SIZE;
	i = start_y;
	while (i < start_y + TILE_SIZE)
	{
		j = start_x;
		while (j < start_x + TILE_SIZE)
		{
			mlx_put_pixel(img, j, i, color);
			j++;
		}
		i++;
	}
}

void	render(t_mlx *mlx)
{
	int	i;
	int	j;

	for (i = 0; i < mlx->map->rows; i++)
	{
		for (j = 0; j < mlx->map->cols; j++)
		{
			if (mlx->map->map2d[i][j] == '1')
				draw_mini_map(mlx->img, j, i, ft_get_color(0, 0, 0, 255));
			else if (mlx->map->map2d[i][j] == '0' || mlx->map->map2d[i][j] == 'N' || mlx->map->map2d[i][j] == 'S' || mlx->map->map2d[i][j] == 'E' || mlx->map->map2d[i][j] == 'W')
				draw_mini_map(mlx->img, j, i, ft_get_color(255, 255, 255, 255));
		}
	}

}
