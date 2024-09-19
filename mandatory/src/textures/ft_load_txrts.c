/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_txrts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:05:22 by aait-bab          #+#    #+#             */
/*   Updated: 2024/09/18 16:44:09 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_load_txtrs(t_cube *cube)
{
	int	i;

	i = 0;
	cube->textur = ft_malloc(sizeof(t_textur), 1);
	while (cube->txtrs[i] != NULL)
	{
		if (!ft_strncmp(cube->txtrs[i]->key, "NO", 2))
			cube->textur->no = mlx_load_png(cube->txtrs[i]->path);
		else if (!ft_strncmp(cube->txtrs[i]->key, "SO", 2))
			cube->textur->so = mlx_load_png(cube->txtrs[i]->path);
		else if (!ft_strncmp(cube->txtrs[i]->key, "WE", 2))
			cube->textur->we = mlx_load_png(cube->txtrs[i]->path);
		else if (!ft_strncmp(cube->txtrs[i]->key, "EA", 2))
			cube->textur->ea = mlx_load_png(cube->txtrs[i]->path);
		i++;
	}
	if (!cube->textur->no || !cube->textur->so \
		|| !cube->textur->we || !cube->textur->ea)
		ft_error("Error\nfailed to load textures");
}
