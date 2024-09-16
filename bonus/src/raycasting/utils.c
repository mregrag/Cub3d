/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 03:49:51 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/15 20:56:43 by aait-bab         ###   ########.fr       */
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

// uint32_t reverse_bytes(uint32_t color)
// {
//     return ((color & 0xFF000000) >> 24) |
//            ((color & 0x00FF0000) >> 8)  |
//            ((color & 0x0000FF00) << 8)  |
//            ((color & 0x000000FF) << 24);
// }
//
double	calcul_distance(double x_inter, double y_inter, double p_x, double p_y)
{
    return sqrt(pow(x_inter - p_x, 2) + pow(y_inter - p_y, 2));
}

double	deg2rad(double degrees)
{
	return (degrees * (M_PI / 180.0));
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
void	my_mlx_pixel_put2(t_cube *cube, int x, int y, int color)
{
	if (x < 0)
		return ;
	else if (x >= 120)
		return ;
	if (y < 0)
		return ;
	else if (y >= 120)
		return ;
	mlx_put_pixel(cube->img2, x, y, color);
}