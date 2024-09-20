/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:21:35 by aait-bab          #+#    #+#             */
/*   Updated: 2024/09/20 10:24:29 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*ft_trim(char *str)
{
	char	*trimmed;
	int		i;
	int		j;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && (str[i] == ' ' || str[i] == '\n'))
		i++;
	j = ft_strlen(str) - 1;
	while (j >= 0 && (str[j] == ' ' || str[j] == '\n'))
		j--;
	if (j < i)
		return (ft_strdup(""));
	trimmed = ft_substr(str, i, j - i + 1);
	return (trimmed);
}
