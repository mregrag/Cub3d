/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cube_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:45:03 by aait-bab          #+#    #+#             */
/*   Updated: 2024/10/03 17:24:02 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

static void	create_lst_lines(int fd, t_list **head)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		ft_lstadd_back(head, ft_lstnew(ft_strdup(line)));
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}

int	is_door_valid(char **map2d, int x, int y)
{
	int	h_walls;
	int	v_walls;

	h_walls = (map2d[x][y - 1] == '1' && map2d[x][y + 1] == '1');
	v_walls = (map2d[x - 1][y] == '1' && map2d[x + 1][y] == '1');
	return (h_walls || v_walls);
}

void	ft_parse_cube(char *file, t_cube *cube)
{
	t_list	*head;
	t_list	*head2;
	int		f_len;

	head = NULL;
	cube->map = ft_malloc(sizeof(t_map), 1);
	cube->map->fd = -1;
	f_len = ft_strlen(file);
	cube->map->fd = open(file, O_RDONLY);
	if (cube->map->fd < 0)
		ft_error("Error\nfile not found");
	if (f_len < 5 || file[f_len - 5] == '\0' || file[f_len - 5] == '/')
		ft_error("Error\ninvalid file name");
	if (ft_strncmp(file + f_len - 4, ".cub", 4))
		ft_error("Error\ninvalid file extension");
	create_lst_lines(cube->map->fd, &head);
	head2 = ft_parse_clrs_textrs(head, cube);
	ft_parse_map(head2, cube);
	close(cube->map->fd);
}
