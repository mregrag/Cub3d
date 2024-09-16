/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:30:22 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/12 11:03:00 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		i;

	i = 0;
	dup = ft_malloc(sizeof(char) * (ft_strlen(s1) + 1), 1);
	if (!dup)
		return (NULL);
	while (*s1)
		dup[i++] = *s1++;
	dup[i] = '\0';
	return (dup);
}
