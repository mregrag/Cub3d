/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_sprites_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:25:08 by aait-bab          #+#    #+#             */
/*   Updated: 2024/09/20 10:16:04 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

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
	char	*paths[5];
	int		i;

	i = 0;
	paths[0] = "assets/sprites/sp1.png";
	paths[1] = "assets/sprites/sp2.png";
	paths[2] = "assets/sprites/sp3.png";
	paths[3] = "assets/sprites/sp4.png";
	paths[4] = "assets/sprites/sp5.png";
	while (i < 5)
	{
		sprites[i] = mlx_load_png(paths[i]);
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
