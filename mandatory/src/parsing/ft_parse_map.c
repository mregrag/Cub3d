/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:05:26 by aait-bab          #+#    #+#             */
/*   Updated: 2024/10/04 15:28:35 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	check_valid(char **map2d, int i, size_t j)
{
	if (!map2d[i - 1][j] || !map2d[i + 1][j] \
		|| !map2d[i][j - 1] || !map2d[i][j + 1])
		return (1);
	if (map2d[i - 1][j] == ' ' || map2d[i + 1][j] == ' ' \
		|| map2d[i][j - 1] == ' ' || map2d[i][j + 1] == ' ')
		return (1);
	return (0);
}

static void	valid_map(char **map2d)
{
	size_t	j;
	int		i;

	i = 0;
	while (map2d[i])
	{
		j = 0;
		while (map2d[i][j])
		{
			if (map2d[i][j] == '0' || map2d[i][j] == 'S' \
				|| map2d[i][j] == 'N' || map2d[i][j] == 'E' \
				|| map2d[i][j] == 'W')
			{
				if (check_valid(map2d, i, j))
					ft_error("Error\nplayer or 0 is not surrounded by walls");
			}
			j++;
		}
		i++;
	}
}

static int	get_max_rows(t_list *head)
{
	int	max;
	int	len;

	max = 0;
	while (head)
	{
		len = ft_strlen(head->content);
		if (len > max)
			max = len;
		head = head->next;
	}
	return (max - 1);
}

static void	get_position_player(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map2d[i])
	{
		j = 0;
		while (map->map2d[i][j])
		{
			if (map->map2d[i][j] == 'N' || map->map2d[i][j] == 'S' \
			|| map->map2d[i][j] == 'W' || map->map2d[i][j] == 'E')
			{
				map->p.x = j;
				map->p.y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	ft_parse_map(t_list *head, t_cube *cube)
{
	char	**map2d;

	map2d = ft_malloc(sizeof(char *) * (ft_lstsize(head) + 1), 1);
	ft_fill_map2d(&map2d, head, get_max_rows(head));
	ft_valid_caras_walls(map2d);
	valid_map(map2d);
	cube->map->map2d = map2d;
	get_position_player(cube->map);
	cube->map->width = strslen(map2d);
	cube->map->height = ft_strlen(map2d[0]);
	return (1);
}
