/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_player_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 09:10:37 by aait-bab          #+#    #+#             */
/*   Updated: 2024/09/17 09:13:11 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/cub3d.h"

static void draw_circle(t_cube *cube, int center_x, int center_y, int radius, uint32_t color)
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