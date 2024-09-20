/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:52:07 by aait-bab          #+#    #+#             */
/*   Updated: 2024/09/19 19:32:23 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

int	empty_line(char *line)
{
	if (line[0] == '\n')
		return (1);
	return (0);
}

int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
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
