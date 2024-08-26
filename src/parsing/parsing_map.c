/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 01:22:01 by mregrag           #+#    #+#             */
/*   Updated: 2024/08/25 20:59:06 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	get_rows_cols_num(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map2d[i])
	{
		j = 0;
		while (map->map2d[i][j])
			j++;
		if (j > map->cols)
			map->cols = j;
		i++;
	}
	map->rows = i;
}

void	get_position_player(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map2d[i])
	{
		j = 0;
		while (map->map2d[i][j])
		{
			if (map->map2d[i][j] == 'N' || map->map2d[i][j] == 'S' || map->map2d[i][j] == 'W' || map->map2d[i][j] == 'E')
			{
				map->p_x = j;
				map->p_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	parsing_map(char *path, t_map *map)
{
	map->map = ft_strdup("");
	map->fd = open(path, O_RDONLY);
	map->line = get_next_line(map->fd);
	while (map->line && map->line[0] != '1' && map->line[0] != 32)
	{
		free(map->line);
		map->line = get_next_line(map->fd);
	}
	while (map->line)
	{
		map->map = ft_strjoin(map->map, map->line);
		free(map->line);
		map->line = get_next_line(map->fd);
	}
	map->map2d = ft_split(map->map, '\n');
	get_position_player(map);
	get_rows_cols_num(map);
	return (1);
}
