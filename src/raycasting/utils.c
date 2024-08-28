/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 03:49:51 by mregrag           #+#    #+#             */
/*   Updated: 2024/08/28 06:00:04 by mregrag          ###   ########.fr       */
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


double	calcul_distance(double x_inter, double y_inter, double p_x, double p_y)
{
    return sqrt(pow(x_inter - p_x, 2) + pow(y_inter - p_y, 2));
}

double	deg2rad(double degrees)
{
	return (degrees * (M_PI / 180.0));
}

double	rad2deg(double radians)
{
	return (radians * (180.0 / M_PI));
}


int	ft_get_color(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a << 0);
}

void	turnright(double *dererction)
{
	*dererction += ROTATION_SPEED;
	if (*dererction > 2 * M_PI)
		*dererction -= 2 * M_PI;
}

void	turnleft(double *dererction)
{
	*dererction -= ROTATION_SPEED;
	if (*dererction < 0)
		*dererction += 2 * M_PI;
}

void	my_mlx_pixel_put(t_cube *cube, int x, int y, int color)
{
	if (x < 0)
		return ;
	else if (x >= WIDTH)
		return ;
	if (y < 0)
		return ;
	else if (y >= HEIGHT)
		return ;
	mlx_put_pixel(cube->img, x, y, color);
}
