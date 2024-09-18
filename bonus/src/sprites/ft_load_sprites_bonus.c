/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_sprites_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:25:08 by aait-bab          #+#    #+#             */
/*   Updated: 2024/09/18 15:39:36 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	allocate_sprites(t_cube *cube)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		cube->sprites[i] = ft_malloc(sizeof(t_sprite), 1);
		i++;
	}
	cube->sprites[i] = NULL;
}

static void	fill_sprts_txtrs(mlx_texture_t **sprites)
{
	int	i;

	i = 0;
	sprites[0] = mlx_load_png("assets/sprites/sp1.png");
	sprites[1] = mlx_load_png("assets/sprites/sp2.png");
	sprites[2] = mlx_load_png("assets/sprites/sp3.png");
	sprites[3] = mlx_load_png("assets/sprites/sp4.png");
	sprites[4] = mlx_load_png("assets/sprites/sp5.png");
	while (i < 5)
	{
		if (!sprites[i])
		{
			while (i > 0 && sprites[i - 1])
				mlx_delete_texture(sprites[--i]);
			ft_error("Error\nfailed to load image");
		}
		i++;
	}
}

void	ft_load_sprites(t_cube *cube)
{
	mlx_texture_t	*sprites[5];
	int				i;

	i = 0;
	cube->shoot = 0;
	allocate_sprites(cube);
	fill_sprts_txtrs(sprites);
	while (i < 5)
	{
		cube->sprites[i]->img = mlx_texture_to_image(cube->window, sprites[i]);
		if (!cube->sprites[i]->img)
			ft_error("Error\nfailed to load image");
		i++;
	}
	i = 0;
	while (i < 5)
	{
		mlx_delete_texture(sprites[i]);
		i++;
	}
}
