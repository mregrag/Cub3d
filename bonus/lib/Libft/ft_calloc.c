/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 23:37:24 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/13 11:35:29 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;
	size_t	total;

	total = count * size;
	if (count != 0 && total / count != size)
		return (NULL);
	tmp = ft_malloc(total, 1);
	if (!tmp)
		return (NULL);
	ft_bzero(tmp, total);
	return (tmp);
}
