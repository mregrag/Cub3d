/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:22:15 by aait-bab          #+#    #+#             */
/*   Updated: 2024/09/13 09:56:26 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*result;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	result = malloc(sizeof(char) *(ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
		return (NULL);
	while (*s1)
		*(result + i++) = *s1++;
	while (*s2)
		*(result + i++) = *s2++;
	*(result + i) = '\0';
	return (result);
}

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup_gnl(const char *s1)
{
	char	*dup;
	int		i;

	i = 0;
	dup = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dup)
		return (NULL);
	while (*s1)
		dup[i++] = *s1++;
	dup[i] = '\0';
	return (dup);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_substr_gnl(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		start = ft_strlen(s);
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
