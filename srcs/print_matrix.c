/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:42:42 by lboiteux          #+#    #+#             */
/*   Updated: 2024/03/25 18:07:37 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	clear_window(t_fdf *fdf)
{
	int	x;
	int	y;

	y = -1;
	while (++y != HEIGHT)
	{
		x = -1;
		while (++x != WIDTH)
			mlx_set_image_pixel(fdf->mlx_ptr, fdf->img, x, y, 0xff0f0f0f);
	}
}

void	print_matrix(t_fdf *fdf)
{
	static t_colors	color;
	char			*file_name;

	file_name = ft_strjoin("File : ", fdf->file_name, NULL, 0b000);
	clear_window(fdf);
	if (!color.first_color)
		color.first_color = ft_init_color(0);
	if (!color.scnd_color)
		color.scnd_color = ft_init_color(0);
	fdf->color = color;
	print_diagonale(fdf, fdf->color);
	print_diagonale_bis(fdf, fdf->color);
	print_straight_line(fdf, fdf->color);
	print_straight_line_bis(fdf, fdf->color);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->window_ptr, fdf->img, 0, 0);
	if (fdf->camera.menu == 1)
	{
		put_image(fdf);
		mlx_string_put(fdf->mlx_ptr, fdf->window_ptr, 170, \
			135, 0xffffffff, file_name);
	}
	free(file_name);
}
