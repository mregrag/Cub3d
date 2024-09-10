/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:05:26 by aait-bab          #+#    #+#             */
/*   Updated: 2024/09/04 23:39:48 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

static char	*rm_nl(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			line[i] = '\0';
			break ;
		}
		i++;
	}
	return (line);
}

static void	fill_map2d(char ***map2d, t_list *head)
{
	int	i;

	i = 0;
	while (head && empty_line(head->content))
		head = head->next;
	if (!head)
		ft_error("Error\nno map");
	while (head)
	{
		if (empty_line(head->content))
			ft_error("Error\nempty line in the map");
		(*map2d)[i] = rm_nl(head->content);
		head = head->next;
		i++;
	}
	(*map2d)[i] = NULL;
}

static void valid_caras_walls(char **map2d)
{
	size_t 	j;
	char 	*set;
	char 	*set2;
	int 	i;
	int 	player_exists;

	i = 0;
	set = " 012NSEW";
	set2 = "NSEW";
	player_exists = 0;
	while (map2d[i])
	{
		j = 0;
		while (map2d[i][j])
		{
			if (!ft_strchr(set, map2d[i][j]))
				ft_error("Error\ninvalid character in the map");
			if (i == 0 || i == strslen(map2d) - 1 || j == 0 \
				|| j == ft_strlen(map2d[i]) - 1)
			{
				if (map2d[i][j] != '1' && map2d[i][j] != ' ')
					ft_error("Error\nmap is not surrounded by walls");
			}
			if (ft_strchr(set2, map2d[i][j]))
				player_exists = 1;
			j++;
		}
		i++;
	}
	if (!player_exists)
		ft_error("Error\nno player in the map");
}


static int check_valid(char **map2d, int i, size_t j)
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
	int i;
	size_t j;

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
					ft_error("Error\nplayer or 0 should not be surrounded by espaces");
			}
			j++;
		}
		i++;
	}
}

// to remove
static void print_map(char **map2d)
{
	int i;

	i = 0;
	while (map2d[i])
	{
		printf("%s\n", map2d[i]);
		i++;
	}
}

int	ft_parse_map(t_list *head, t_cube *cube)
{
	char	**map2d;

	(void)cube;
	map2d = malloc(sizeof(char *) * (ft_lstsize(head) + 1));
	fill_map2d(&map2d, head);
	valid_caras_walls(map2d);
	valid_map(map2d);
	print_map(map2d);
	return (1);
}
