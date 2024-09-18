/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 21:33:16 by aait-bab          #+#    #+#             */
/*   Updated: 2024/09/18 15:57:02 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_line(t_cube *cube, t_dpoint start, t_dpoint end, uint32_t color)
{
	t_fpoint	inc;
	t_fpoint	d;
	float		steps;
	int			i;

	i = 0;
	d.x = end.x - start.x;
	d.y = end.y - start.y;
	if (fabs(d.x) > fabs(d.y))
		steps = fabs(d.x);
	else
		steps = fabs(d.y);
	inc.x = d.x / steps;
	inc.y = d.y / steps;
	while (i <= steps)
	{
		mlx_put_pixel(cube->img2, roundf(start.x), roundf(start.y), color);
		start.x += inc.x;
		start.y += inc.y;
		i++;
	}
}

static void	draw_player_direction(t_cube *cube)
{
	t_dpoint	start;
	t_dpoint	end;
	int			color;

	start.x = 60;
	start.y = 60;
	end.x = start.x + cos(cube->plyer->derection) * 10;
	end.y = start.y + sin(cube->plyer->derection) * 10;
	color = ft_get_color(0, 0, 255, 255);
	draw_line(cube, start, end, color);
}

void	draw_minimap(t_cube *cube)
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
