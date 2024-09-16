/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 01:22:01 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/13 04:39:39 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void get_rows_cols_num(t_map *map)
{
	int i;
	int j;
	int max_cols;

	i = 0;
	max_cols = 0;
	while (map->map2d[i] != NULL)
	{
		j = 0;
		while (map->map2d[i][j] != '\0')
		{
			j++;
		}
		if (j > max_cols)
			max_cols = j;
		i++;
	}
	map->rows = i;
	map->cols = max_cols;
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
				map->m.x = j;
				map->m.y = i;
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
	map->tex = ft_strdup("");
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
	map->textur2d = ft_split(map->tex, '\n');
	get_position_player(map);
	get_rows_cols_num(map);
	return (1);
}
