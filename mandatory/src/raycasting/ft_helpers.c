/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 03:49:51 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/18 12:43:55 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

double	normalize_angle(float angle)
{
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

int	reverse_bytes(int c)
{
	unsigned int	b;

	b = 0;
	b |= (c & 0xFF) << 24;
	b |= (c & 0xFF00) << 8;
	b |= (c & 0xFF0000) >> 8;
	b |= (c & 0xFF000000) >> 24;
	return (b);
}

double	calcul_distance(t_dpoint start, t_ipoint end)
{
	return (sqrt(pow(start.x - end.x, 2) + pow(start.y - end.y, 2)));
}

int	ft_get_color(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a << 0);
}

void	my_mlx_pixel_put(t_cube *cube, int x, int y, int color)
{
	if (x < 0)
		return ;
	else if (x >= cube->window->width)
		return ;
	if (y < 0)
		return ;
	else if (y >= cube->window->height)
		return ;
	mlx_put_pixel(cube->img, x, y, color);
}
