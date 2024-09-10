/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:52:07 by aait-bab          #+#    #+#             */
/*   Updated: 2024/08/31 16:55:08 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	empty_line(char *line)
{
	// while (*line)
	// {
	// 	if (*line != ' ' && (*line < 9 || *line > 13))
	// 		return (0);
	// 	line++;
	// }
	if (line[0] == '\n')
		return (1);
	return (0);
}

int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	// if ((str[i] == '-' || str[i] == '+') && str[i + 1])
	// 	i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	isnumbers(char **colors)
{
	int	i;

	i = 0;
	while (colors[i])
	{
		if (!ft_isnumber(colors[i]))
			return (0);
		i++;
	}
	return (1);
}

int	strslen(char **strs)
{
	int	i;

	i = 0;
	if (!strs)
		return (0);
	while (strs[i])
		i++;
	return (i);
}

int	isranged(char **colors, int min, int max)
{
	int	i;
	int	n;

	i = 0;
	while (colors[i])
	{
		n = ft_atoi(colors[i]);
		if (n < min || n > max)
			return (0);
		i++;
	}
	return (1);
}

int	in_txtrs_set(char *txtr)
{
	return (!ft_strncmp(txtr, "NO", 2) || !ft_strncmp(txtr, "SO", 2)
		|| !ft_strncmp(txtr, "WE", 2) || !ft_strncmp(txtr, "EA", 2)
		|| !ft_strncmp(txtr, "S", 1));
}
