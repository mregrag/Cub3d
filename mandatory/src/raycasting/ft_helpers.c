/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 03:49:51 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/01 20:48:09 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

double	normalize_angle(double angle)
{
	angle = fmod(angle, 2 * M_PI);
	if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}

uint32_t	reverse_bytes(uint32_t c)
{
	uint32_t	b;

	b = 0;
	b |= (c & 0xFF) << 24;
	b |= (c & 0xFF00) << 8;
	b |= (c & 0xFF0000) >> 8;
	b |= (c & 0xFF000000) >> 24;
	return (b);
}

double	calcul_distance(t_dpoint start, t_dpoint end)
{
	return (sqrt(pow(start.x - end.x, 2) + pow(start.y - end.y, 2)));
}

uint32_t	ft_get_color(uint32_t r, uint32_t g, uint32_t b, uint32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a << 0);
}

void	my_pixel_put(mlx_image_t *img, uint32_t x, uint32_t y, uint32_t color)
{
	if (x < 0)
		return ;
	else if (x >= img->width)
		return ;
	if (y < 0)
		return ;
	else if (y >= img->height)
		return ;
	mlx_put_pixel(img, x, y, color);
}
