/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 21:33:16 by aait-bab          #+#    #+#             */
/*   Updated: 2024/09/17 13:48:31 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	draw_line(t_cube *cube, int x0, int y0, int x1, int y1, uint32_t color)
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

static void	draw_player_direction(t_cube *cube)
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


void    draw_minimap(t_cube *cube)
{
	int		ref_x;
	int		ref_y;
	int		start_x;
	int		start_y;

	start_y = cube->plyer->s.y - 60;
	ref_y = start_y;
	ref_x = cube->plyer->s.x - 60;
	ft_clear_img(cube->img2);
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