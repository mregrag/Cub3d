/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 21:33:16 by aait-bab          #+#    #+#             */
/*   Updated: 2024/09/18 14:02:22 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_line(mlx_image_t *img, t_dpoint start, t_dpoint end, uint32_t color)
{
	float	dx;
	float	dy;
	float	steps;
	float	x_inc;
	float	y_inc;
	int	i;

	i = 0;
	dx = end.x - start.x;
	dy = end.y - start.y;
	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	x_inc = dx / steps;
	y_inc = dy / steps;
	while (i <= steps)
	{
		mlx_put_pixel(img, roundf(start.x), roundf(start.y), color);
		start.x += x_inc;
		start.y += y_inc;
		i++;
	}
}

static void	draw_player_direction(t_cube *cube)
{
	t_dpoint	start;
	t_dpoint	end;
	int	color;

	start.x = 60;
	start.y = 60;
	end.x = start.x + cos(cube->plyer->derection) * 10;
	end.y = start.y + sin(cube->plyer->derection) * 10;
	color = ft_get_color(0, 0, 255, 255);
	draw_line(cube->img2, start, end, color);
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
			if ((0 < start_x && start_x  < (cube->map->height * TILE_SIZE)) && \
					(0 < start_y && start_y < (cube->map->width * TILE_SIZE)))
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
