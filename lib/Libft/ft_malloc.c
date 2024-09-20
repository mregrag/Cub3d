/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:59:11 by aait-bab          #+#    #+#             */
/*   Updated: 2024/09/19 19:23:22 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	handel_error(void *ptr, t_list *head)
{
	ft_putendl_fd("Error\nMemory allocation failed\n", 1);
	free(ptr);
	ft_lstclear(&head, free);
	exit(1);
}

void	*ft_malloc(size_t size, int mod)
{
	static t_list	*head;
	void			*ptr;
	t_list			*node;

	ptr = NULL;
	if (mod == 1)
	{
		ptr = malloc(size);
		if (!ptr)
			handel_error(ptr, head);
		node = malloc(sizeof(t_list));
		if (!node)
			handel_error(ptr, head);
		node->content = ptr;
		node->next = NULL;
		ft_lstadd_back(&head, node);
	}
	else
		ft_lstclear(&head, free);
	return (ptr);
}
