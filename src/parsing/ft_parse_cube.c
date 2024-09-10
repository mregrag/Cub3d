/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cube.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:45:03 by aait-bab          #+#    #+#             */
/*   Updated: 2024/09/03 10:07:01 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

// static int	empty_line(char *line)
// {
// 	while (*line)
// 	{
// 		if (*line != ' ' && (*line < 9 || *line > 13))
// 			return (0);
// 		line++;
// 	}
// 	return (1);
// }

static void	create_lst_lines(int fd, t_list **head)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		ft_lstadd_back(head, ft_lstnew(line));
		line = get_next_line(fd);
	}
}



void	ft_parse_cube(char *file, t_cube *cube)
{
	t_list	*head;
	t_list	*head2;
	int		fd;

	(void)cube;
	head = NULL;
	if (ft_strncmp(file + ft_strlen(file) - 4, ".cub", 4))
		ft_error("Error\ninvalid file extension");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Error\nfile not found");
	create_lst_lines(fd, &head);
	head2 = ft_parse_clrs_textrs(head, cube);
	ft_parse_map(head2, cube);
	close(fd);
}
