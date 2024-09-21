/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_player_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 09:10:37 by aait-bab          #+#    #+#             */
/*   Updated: 2024/09/21 12:03:53 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

static void	draw_circle(t_cube *cube, t_ipoint p, int radius, uint32_t color)
{
	int	dx;
	int	dy;
	int	distance;

	dy = -radius;
	while (dy <= radius)
	{
		dx = -radius;
		while (dx <= radius)
		{
			distance = dx * dx + dy * dy;
			if (distance <= radius * radius)
				my_pixel_put(cube->img2, p.x + dx, p.y + dy, color);
			dx++;
		}
		dy++;
	}
}

void	draw_player(t_cube *cube)
{
	t_ipoint	p;
	int			radius;
	int			color;

	p.x = 60;
	p.y = 60;
	color = ft_get_color(255, 0, 0, 255);
	radius = TILE_SIZE / 10;
	draw_circle(cube, p, radius, color);
}
