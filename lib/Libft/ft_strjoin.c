/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:48:28 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/12 11:29:07 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	result = ft_malloc(sizeof(char) *(ft_strlen(s1) + ft_strlen(s2) + 1), 1);
	if (!result)
		return (NULL);
	while (*s1)
		*(result + i++) = *s1++;
	while (*s2)
		*(result + i++) = *s2++;
	*(result + i) = '\0';
	return (result);
}
