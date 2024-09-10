/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_clrs_txtrs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:29:09 by aait-bab          #+#    #+#             */
/*   Updated: 2024/09/10 21:12:29 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

static void	contain2comma(char *str)
{
	int		i;
	int		comma;

	i = 0;
	comma = 0;
	while (str[i])
	{
		if (str[i] == ',')
			comma++;
		i++;
	}
	if (comma != 2)
		ft_error("Error\ninvalid color");
}

static void	parse_color(char *t_line, t_cube *cube)
{
	char	**colors;

	(void)cube;
	if (t_line[1] != ' ')
		ft_error("Error\ninvalid color");
	while (*(t_line + 1) == ' ')
		t_line++;
	contain2comma(t_line);
	colors = ft_split(t_line + 1, ',');
	if (!colors || strslen(colors) != 3)
		ft_error("Error\ninvalid color");
	if (!isnumbers(colors))
		ft_error("Error\ncolors not numbers");
	if (!isranged(colors, 0, 255))
		ft_error("Error\ninvalid colors range");
	// TODO: store the colors in the cube struct
}

static void	parse_texture(char *t_line, t_cube *cube)
{
	char	*key;
	char	*path;

	(void)cube;
	if (ft_strlen(t_line) < 2 || t_line[2] != ' ')
		ft_error("Error\ninvalid texture");
	key = ft_substr(t_line, 0, 2);
	path = ft_strtrim(t_line + 2, " ");
	if (!key || !ft_strlen(path))
		ft_error("Error\ninvalid texture");
	if (!in_txtrs_set(key))
		ft_error("Error\ninvalid texture or color identifier");
	// TODO: store the texture in the cube struct
}

t_list	*ft_parse_clrs_textrs(t_list *head, t_cube *cube)
{
	char	*t_line;
	int		i;
	char	*key[6];

	(void)cube;
	i = 0;
	while (head && i < 6)
	{
		if (!empty_line(head->content))
		{
			t_line = ft_trim(head->content);
			if (t_line[0] == 'F' || t_line[0] == 'C')
				parse_color(t_line, cube);
			else if (t_line[0] == 'N' || t_line[0] == 'S' || t_line[0] == 'W' \
				|| t_line[0] == 'E')
				parse_texture(t_line, cube);
			else
				ft_error("Error\ninvalid line");
			free(t_line);
			i++;
		}
		head = head->next;
	}
	if (i < 6)
		ft_error("Error\nmissing colors or textures");
	return (head->next);
}
