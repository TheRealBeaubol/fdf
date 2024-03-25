/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_palette.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 06:03:08 by lboiteux          #+#    #+#             */
/*   Updated: 2024/03/25 18:07:58 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	palette_6(int z, t_fdf *fdf)
{
	if (fdf->camera.height < 0)
		z = -z;
	if (z < fdf->ground + 5)
		return (ft_atoi_base("0F0F0F", "0123456789ABCDEF"));
	else if (z < fdf->ground + 15)
		return (ft_atoi_base("FFE8FA", "0123456789ABCDEF"));
	else if (z < fdf->ground + 45)
		return (ft_atoi_base("FF91BF", "0123456789ABCDEF"));
	else
		return (ft_atoi_base("F7638F", "0123456789ABCDEF"));
}

int	get_color(int z, t_fdf *fdf)
{
	if (fdf->color_palette == 1)
		return (palette_1(z, fdf));
	else if (fdf->color_palette == 2)
		return (palette_2(z, fdf));
	else if (fdf->color_palette == 3)
		return (palette_3(z, fdf));
	else if (fdf->color_palette == 4)
		return (palette_4(z, fdf));
	else if (fdf->color_palette == 5)
		return (palette_5(z, fdf));
	else if (fdf->color_palette == 6)
		return (palette_6(z, fdf));
	return (0);
}

void	set_new_color(t_fdf *fdf)
{
	int	i;
	int	x;
	int	y;

	fdf->color_matrix = ft_calloc(fdf->width + 1, sizeof(int *));
	if (!fdf->color_matrix)
		free_and_destroy_exit(0, fdf);
	i = -1;
	while (++i != fdf->width)
	{
		fdf->color_matrix[i] = ft_calloc(fdf->height + 1, sizeof(int));
		if (!fdf->color_matrix[i])
		{
			ft_free_int_tab(fdf->color_matrix, i);
			fdf->color_matrix = NULL;
			free_and_destroy_exit(0, fdf);
		}
	}
	x = -1;
	while (++x != fdf->width)
	{
		y = -1;
		while (++y != fdf->height)
			fdf->color_matrix[x][y] = get_color(fdf->height_matrix[x][y], fdf);
	}
}

int	ft_color(t_fdf *fdf)
{
	if (fdf->color_palette == 6)
	{
		fdf->color_palette = 0;
		ft_free_int_tab(fdf->color_matrix, fdf->width);
		fdf->color_matrix = ft_dup_int_tab(fdf->color_matrix_stock, \
		fdf->width + 1, fdf->height + 1);
	}
	else if (fdf->color_palette != 6)
	{
		fdf->color_palette += 1;
		ft_free_int_tab(fdf->color_matrix, fdf->width);
		set_new_color(fdf);
	}
	return (0);
}
