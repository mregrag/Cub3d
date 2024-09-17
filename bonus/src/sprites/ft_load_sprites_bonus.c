/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_sprites_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:25:08 by aait-bab          #+#    #+#             */
/*   Updated: 2024/09/17 13:28:56 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/cub3d.h"

void	ft_load_sprites(t_cube *cube)
{
	int i;

	i = 0;
	while (i < 5)
	{
		cube->sprites[i] = ft_malloc(sizeof(t_sprite), 1);
		i++;
	}
	cube->sprites[i] = NULL;
	cube->sprites[0]->img = mlx_texture_to_image(cube->window,mlx_load_png("assets/sprites/sp1.png"));
	cube->sprites[1]->img = mlx_texture_to_image(cube->window,mlx_load_png("assets/sprites/sp2.png"));
	cube->sprites[2]->img = mlx_texture_to_image(cube->window,mlx_load_png("assets/sprites/sp3.png"));
	cube->sprites[3]->img = mlx_texture_to_image(cube->window,mlx_load_png("assets/sprites/sp4.png"));
	cube->sprites[4]->img = mlx_texture_to_image(cube->window,mlx_load_png("assets/sprites/sp5.png"));
	i = 0;
	while (i < 5)
	{
		if (!cube->sprites[i]->img)
			ft_error("Error\nfailed to load sprite");
		i++;
	}
	cube->img3 = mlx_texture_to_image(cube->window,mlx_load_png("assets/sprites/point.png"));
}