/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_use.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:19:03 by lboiteux          #+#    #+#             */
/*   Updated: 2024/03/25 17:59:07 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_translate(int keysym, t_fdf *fdf)
{
	if (keysym == ARROW_DOWN)
		fdf->camera.offset_y += 5;
	if (keysym == ARROW_LEFT)
		fdf->camera.offset_x -= 5;
	if (keysym == ARROW_UP)
		fdf->camera.offset_y -= 5;
	if (keysym == ARROW_RIGHT)
		fdf->camera.offset_x += 5;
	return (0);
}

int	ft_height(int keysym, t_fdf *fdf)
{
	if (keysym == KEYPAD_7)
		fdf->camera.height -= 1;
	if (keysym == KEYPAD_9)
		fdf->camera.height += 1;
	ft_menu(0, fdf);
	return (0);
}

int	ft_projection(t_fdf *fdf)
{
	fdf->camera.gamma = 0.00001;
	fdf->camera.beta = 0.00001;
	fdf->camera.alpha = 0.00001;
	if (fdf->camera.projection == 3)
		fdf->camera.projection = 1;
	else
		fdf->camera.projection += 1;
	return (0);
}

int	ft_reset(t_fdf *fdf)
{
	camera_init(fdf);
	if (fdf->color_palette != 0)
	{
		fdf->color_palette = 0;
		ft_free_int_tab(fdf->color_matrix, fdf->width);
		fdf->color_matrix = fdf->color_matrix_stock;
	}
	fdf->menu.button_1_offset_x = (5 * (fdf->camera.height + 47));
	fdf->menu.button_2_offset_x = (5 * (fdf->camera.zoom + 13));
	return (0);
}

int	ft_rotate(int keysym, t_fdf *fdf)
{
	if (keysym == KEYPAD_3)
		fdf->camera.gamma -= 0.01;
	if (keysym == KEYPAD_4)
		fdf->camera.beta += 0.01;
	if (keysym == KEYPAD_1)
		fdf->camera.gamma += 0.01;
	if (keysym == KEYPAD_5)
		fdf->camera.alpha -= 0.01;
	if (keysym == KEYPAD_6)
		fdf->camera.beta -= 0.01;
	if (keysym == KEYPAD_2)
		fdf->camera.alpha += 0.01;
	return (0);
}
