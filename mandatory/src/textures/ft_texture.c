/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:57:46 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/19 20:24:47 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

mlx_texture_t	*get_texture(t_cube *cube)
{
	cube->ray->angl = normalize_angle(cube->ray->angl);
	if (cube->ray->was_hit_vertical)
	{
		if (cube->ray->angl > M_PI / 2 && cube->ray->angl < 3 * (M_PI / 2))
			return (cube->textur->ea);
		else
			return (cube->textur->we);
	}
	else
	{
		if (cube->ray->angl > 0 && cube->ray->angl < M_PI)
			return (cube->textur->so);
		else
			return (cube->textur->no);
	}
}

double	calculate_texture_x(mlx_texture_t *texture, t_cube *cube)
{
	double	x;

	if (cube->ray->was_hit_vertical)
		x = fmod(cube->ray->vwall.y, TILE_SIZE);
	else
		x = fmod(cube->ray->hwall.x, TILE_SIZE);
	x = (x * texture->width) / TILE_SIZE;
	return (x);
}
