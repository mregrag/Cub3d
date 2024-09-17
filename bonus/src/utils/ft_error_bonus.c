/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:57:20 by aait-bab          #+#    #+#             */
/*   Updated: 2024/09/17 22:33:03 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_error(char *msg)
{
	t_cube	*cube;

	print_fd(msg, 2);
	cube = ft_get_cube(NULL);
	ft_malloc(0, 0);
	exit(1);
}
