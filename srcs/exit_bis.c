/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 23:47:51 by lboiteux          #+#    #+#             */
/*   Updated: 2024/03/25 17:59:07 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	exit_map_init(t_fdf *fdf, int exit_type, int i)
{
	if (exit_type == 0)
		exit (EXIT_FAILURE);
	if (exit_type == 1)
	{
		free(fdf->height_matrix);
		exit (EXIT_FAILURE);
	}
	if (exit_type == 2)
	{
		free(fdf->color_matrix);
		ft_free_int_tab(fdf->height_matrix, i);
		exit (EXIT_FAILURE);
	}
	if (exit_type == 3)
	{
		ft_free_int_tab(fdf->height_matrix, fdf->width);
		ft_free_int_tab(fdf->color_matrix, i);
		exit (EXIT_FAILURE);
	}
}
