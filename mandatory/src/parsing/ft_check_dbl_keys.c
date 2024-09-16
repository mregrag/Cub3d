/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dbl_keys.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:52:25 by aait-bab          #+#    #+#             */
/*   Updated: 2024/09/14 12:32:52 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
			if (!strcmp(colors[i]->key, colors[j]->key))
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
			if (!strcmp(txtrs[i]->key, txtrs[j]->key))
				ft_error("Error\nduplicate texture key");
			j++;
		}
		i++;
	}
}

void	ft_check_dbl_keys(t_cube *cube)
{
	check_txtrs(cube->txtrs);
	check_colors(cube->colors);
}
