/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 21:33:16 by aait-bab          #+#    #+#             */
/*   Updated: 2024/09/21 12:23:53 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	draw_line(t_cube *cube, t_dpoint start, t_dpoint end, uint32_t color)
{
	t_dpoint	inc;
	t_dpoint	d;
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
		my_pixel_put(cube->img2, roundf(start.x), roundf(start.y), color);
		start.x += inc.x;
		start.y += inc.y;
		i++;
	}
}

static void	draw_player_direction(t_cube *cube)
{
	t_dpoint	start;
	t_dpoint	end;

	start.x = 60;
	start.y = 60;
	end.x = start.x + cos(cube->plyer->derection) * 10;
	end.y = start.y + sin(cube->plyer->derection) * 10;
	draw_line(cube, start, end, ft_get_color(0, 0, 255, 255));
}

static void	minimap_put_pixel(t_cube *cube, t_ipoint s, t_ipoint r)
{
	if ((0 < s.x && s.x < (cube->map->height * TILE_SIZE)) && \
		(0 < s.y && s.y < (cube->map->width * TILE_SIZE)))
	{
		if (cube->map->map2d[(s.y / TILE_SIZE)][s.x / TILE_SIZE] == '1')
			my_pixel_put(cube->img2, s.x - r.x, s.y - r.y, \
				ft_get_color(0, 0, 0, 255));
		else
			my_pixel_put(cube->img2, s.x - r.x, s.y - r.y, \
				ft_get_color(255, 255, 255, 255));
	}
}

void	draw_minimap(t_cube *cube)
{
	t_ipoint	ref;
	t_ipoint	start;

	ft_clear_img(cube->img2);
	start.y = cube->plyer->s.y - 60;
	ref.y = start.y;
	ref.x = cube->plyer->s.x - 60;
	while (start.y < cube->plyer->s.y + 60)
	{
		start.x = cube->plyer->s.x - 60;
		while (start.x < cube->plyer->s.x + 60)
		{
			minimap_put_pixel(cube, start, ref);
			start.x++;
		}
		start.y++;
	}
	draw_player_direction(cube);
	draw_player(cube);
}
