/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dbl_keys_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:52:25 by aait-bab          #+#    #+#             */
/*   Updated: 2024/09/19 19:31:54 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

static void	check_colors(t_colors **colors)
{
	int	i;
	int	j;

	i = 0;
	while (colors[i])
	{
		j = i + 1;
		while (colors[j])
		{
			if (!ft_strncmp(colors[i]->key, colors[j]->key, 1))
				ft_error("Error\nduplicate color key");
			j++;
		}
		i++;
	}
}

static void	check_txtrs(t_txtr **txtrs)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (txtrs[i])
	{
		j = i + 1;
		while (txtrs[j])
		{
			if (!ft_strncmp(txtrs[i]->key, txtrs[j]->key, 2))
				ft_error("Error\nduplicate texture key");
			j++;
		}
		i++;
	}
}

static void	check_load_txtrs(t_txtr **txtrs)
{
	mlx_texture_t	*tex[6];
	int				i;

	i = 0;
	while (txtrs[i])
	{
		tex[i] = mlx_load_png(txtrs[i]->path);
		if (!tex[i])
			ft_error("Error\nfailed to load textures");
		mlx_delete_texture(tex[i]);
		i++;
	}
}

void	ft_check_dbl_keys(t_cube *cube)
{
	check_load_txtrs(cube->txtrs);
	check_txtrs(cube->txtrs);
	check_colors(cube->colors);
}
