/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_caras_walls.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:07:15 by aait-bab          #+#    #+#             */
/*   Updated: 2024/10/03 10:03:10 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	serrounded_by_walls(int i, int j, char **map2d)
{
	if (i == 0 || i == strslen(map2d) - 1)
	{
		if (map2d[i][j] != '1' && map2d[i][j] != ' ')
			return (0);
	}
	return (1);
}

static void	player_check(int p_x)
{
	if (p_x > 1)
		ft_error("Error\nmulti players in the map");
	if (p_x == 0)
		ft_error("Error\nno player in the map");
}

void	ft_valid_caras_walls(char **map2d)
{
	int		p_x;
	int		i;
	int		j;

	i = 0;
	p_x = 0;
	while (map2d[i])
	{
		j = 0;
		while (map2d[i][j])
		{
			if (!ft_strchr(" 01NSEW", map2d[i][j]))
				ft_error("Error\ninvalid character in the map");
			if (!serrounded_by_walls(i, j, map2d))
				ft_error("Error\nmap is not surrounded by walls");
			if (ft_strchr("NSEW", map2d[i][j]))
				p_x++;
			j++;
		}
		i++;
	}
	player_check(p_x);
}
