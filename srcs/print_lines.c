/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 06:53:26 by lboiteux          #+#    #+#             */
/*   Updated: 2024/03/25 17:59:07 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_diagonale(t_fdf *fdf, t_colors color)
{
	int	x;
	int	y;

	if (fdf->camera.map_status == 1 || fdf->camera.map_status == 3)
	{
		x = -1;
		while (++x + 1 != fdf->width)
		{
			y = -1;
			while (++y + 1 != fdf->height)
			{
				ft_set_color(color.first_color, fdf->color_matrix[x][y]);
				ft_set_color(color.scnd_color, fdf->color_matrix[x + 1][y + 1]);
				plotline(fdf, do_projection(x, y, fdf), do_projection \
					(x + 1, y + 1, fdf), &color);
			}
		}
	}
}

void	print_diagonale_bis(t_fdf *fdf, t_colors color)
{
	int	x;
	int	y;

	if (fdf->camera.map_status == 2 || fdf->camera.map_status == 3)
	{
		x = 0;
		while (++x != fdf->width)
		{
			y = -1;
			while (++y + 1 != fdf->height)
			{
				ft_set_color(color.first_color, fdf->color_matrix[x][y]);
				ft_set_color(color.scnd_color, fdf->color_matrix[x - 1][y + 1]);
				plotline(fdf, do_projection(x, y, fdf), do_projection \
					(x - 1, y + 1, fdf), &color);
			}
		}
	}
}

void	print_straight_line(t_fdf *fdf, t_colors color)
{
	int	x;
	int	y;

	y = -1;
	while (++y != fdf->height)
	{
		x = -1;
		while (++x + 1 != fdf->width)
		{
			ft_set_color(color.first_color, fdf->color_matrix[x][y]);
			ft_set_color(color.scnd_color, fdf->color_matrix[x + 1][y]);
			plotline(fdf, do_projection(x, y, fdf), do_projection \
				(x + 1, y, fdf), &color);
		}
	}
}

void	print_straight_line_bis(t_fdf *fdf, t_colors color)
{
	int	x;
	int	y;

	x = -1;
	while (++x != fdf->width)
	{
		y = -1;
		while (++y + 1 != fdf->height)
		{
			ft_set_color(color.first_color, fdf->color_matrix[x][y]);
			ft_set_color(color.scnd_color, fdf->color_matrix[x][y + 1]);
			plotline(fdf, do_projection(x, y, fdf), do_projection \
				(x, y + 1, fdf), &color);
		}
	}
}
