/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cube_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:45:03 by aait-bab          #+#    #+#             */
/*   Updated: 2024/09/19 19:32:45 by mregrag          ###   ########.fr       */
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

void	ft_parse_cube(char *file, t_cube *cube)
{
	t_list	*head;
	t_list	*head2;
	int		fd;
	int		f_len;

	head = NULL;
	f_len = ft_strlen(file);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Error\nfile not found");
	if (f_len < 5 || file[f_len - 5] == '\0' || file[f_len - 5] == '/')
		ft_error("Error\ninvalid file name");
	if (ft_strncmp(file + f_len - 4, ".cub", 4))
		ft_error("Error\ninvalid file extension");
	create_lst_lines(fd, &head);
	head2 = ft_parse_clrs_textrs(head, cube);
	ft_parse_map(head2, cube);
	close(fd);
}
