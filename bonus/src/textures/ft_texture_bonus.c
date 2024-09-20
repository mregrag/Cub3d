/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:57:46 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/20 10:55:31 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

mlx_texture_t	*get_texture(t_cube *cube)
{
	if (cube->ray->was_hit_vertical)
	{
		if (cube->ray->angl > M_PI / 2 && cube->ray->angl < 3 * (M_PI / 2))
			return (cube->textur->we);
		else
			return (cube->textur->ea);
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
