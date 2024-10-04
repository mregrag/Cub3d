/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_map2d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:48:45 by aait-bab          #+#    #+#             */
/*   Updated: 2024/10/03 21:06:17 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static char	*rm_nl(char *line)
{
	int	i;

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

static char	*add_spaces(char *line, int max_rows)
{
	int		len;
	char	*new_line;

	len = ft_strlen(line);
	if (len < max_rows)
	{
		new_line = ft_calloc(max_rows + 1, sizeof(char));
		ft_memcpy(new_line, line, len);
		ft_memset(new_line + len, ' ', max_rows - len);
		return (new_line);
	}
	return (line);
}

static int	walls_check(char *line)
{
	int	i;

	i = 0;
	if (line[i] == '\0')
		return (0);
	if (line[i] != '1')
		return (1);
	while (line[i])
		i++;
	if (line[i - 1] != '1')
		return (1);
	return (0);
}

void	ft_fill_map2d(char ***map2d, t_list *head, int max_rows)
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
		if (walls_check(rm_nl(ft_trim(head->content))))
			ft_error("Error\nmap not surrounded by walls");
		(*map2d)[i] = add_spaces(rm_nl(head->content), max_rows);
		head = head->next;
		i++;
	}
	(*map2d)[i] = NULL;
}
