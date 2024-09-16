/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_txrts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:05:22 by aait-bab          #+#    #+#             */
/*   Updated: 2024/09/16 13:32:35 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	delete_txtrs(t_textur *textur, int num)
{
	if (num == 1)
	{
		mlx_delete_texture(textur->no);
		ft_error("Error\nfailed to load NO texture");
	}
	if (num == 2)
	{
		mlx_delete_texture(textur->no);
		mlx_delete_texture(textur->so);
		ft_error("Error\nfailed to load SO texture");
	}
	if (num == 3)
	{
		mlx_delete_texture(textur->no);
		mlx_delete_texture(textur->so);
		mlx_delete_texture(textur->we);
		ft_error("Error\nfailed to load WE texture");
	}
	if (num == 4)
	{
		mlx_delete_texture(textur->no);
		mlx_delete_texture(textur->so);
		mlx_delete_texture(textur->we);
		mlx_delete_texture(textur->ea);
		ft_error("Error\nfailed to load EA texture");
	}
}

void	ft_load_txtrs(t_cube *cube)
{
	int	i;

	i = 0;
	while (cube->txtrs[i] != NULL)
	{
		if (!ft_strncmp(cube->txtrs[i]->key, "NO", 2))
		{
			cube->textur->no = mlx_load_png(cube->txtrs[i]->path);
			if (!cube->textur->no)
				delete_txtrs(cube->textur, 1);
		}
		else if (!ft_strncmp(cube->txtrs[i]->key, "SO", 2))
		{
			cube->textur->so = mlx_load_png(cube->txtrs[i]->path);
			if (!cube->textur->so)
				delete_txtrs(cube->textur, 2);
		}
		else if (!ft_strncmp(cube->txtrs[i]->key, "WE", 2))
		{
			cube->textur->we = mlx_load_png(cube->txtrs[i]->path);
			if (!cube->textur->we)
				delete_txtrs(cube->textur, 3);
		}
		else if (!ft_strncmp(cube->txtrs[i]->key, "EA", 2))
		{
			cube->textur->ea = mlx_load_png(cube->txtrs[i]->path);
			if (!cube->textur->ea)
				delete_txtrs(cube->textur, 4);
		}
		i++;
	}
}
