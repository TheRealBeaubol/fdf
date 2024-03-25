/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 23:30:42 by lboiteux          #+#    #+#             */
/*   Updated: 2024/03/25 17:59:07 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_menu(int keysym, t_fdf *fdf)
{
	fdf->menu.button_1_offset_x = (5 * (fdf->camera.height + 47));
	if (fdf->menu.button_1_offset_x >= 420)
		fdf->menu.button_1_offset_x = 420;
	if (fdf->menu.button_1_offset_x <= 75)
		fdf->menu.button_1_offset_x = 75;
	fdf->menu.button_2_offset_x = (5 * (fdf->camera.zoom + 13));
	if (fdf->menu.button_2_offset_x >= 420)
		fdf->menu.button_2_offset_x = 420;
	if (fdf->menu.button_2_offset_x <= 75)
		fdf->menu.button_2_offset_x = 75;
	if (fdf->camera.menu == 0 && keysym == KEY_M)
		fdf->camera.menu = 1;
	else if (fdf->camera.menu == 1 && keysym == KEY_M)
		fdf->camera.menu = 0;
	return (0);
}

void	put_image_next(t_fdf *fdf)
{
	if (fdf->menu.top_button_status == 0)
		mlx_put_image_to_window(fdf->mlx_ptr, fdf->window_ptr, \
		fdf->menu.top_button, 75, 350);
	if (fdf->menu.top_button_status == 1)
		mlx_put_image_to_window(fdf->mlx_ptr, fdf->window_ptr, \
		fdf->menu.top_button_hover, 75, 350);
	if (fdf->menu.iso_button_status == 0)
		mlx_put_image_to_window(fdf->mlx_ptr, fdf->window_ptr,
			fdf->menu.iso_button, 300, 350);
	if (fdf->menu.iso_button_status == 1)
		mlx_put_image_to_window(fdf->mlx_ptr, fdf->window_ptr, \
		fdf->menu.iso_button_hover, 300, 350);
	if (fdf->menu.side_button_status == 0)
		mlx_put_image_to_window(fdf->mlx_ptr, fdf->window_ptr, \
		fdf->menu.side_button, 185, 300);
	if (fdf->menu.side_button_status == 1)
		mlx_put_image_to_window(fdf->mlx_ptr, fdf->window_ptr, \
		fdf->menu.side_button_hover, 185, 300);
}

void	put_image(t_fdf *fdf)
{
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->window_ptr, \
	fdf->menu.menu, 0, 0);
	if (fdf->menu.button_1_status == 1)
		mlx_put_image_to_window(fdf->mlx_ptr, fdf->window_ptr, \
		fdf->menu.button_slider_on, fdf->menu.button_1_offset_x, \
		196);
	if (fdf->menu.button_1_status == 0)
		mlx_put_image_to_window(fdf->mlx_ptr, fdf->window_ptr, \
		fdf->menu.button_slider_off, fdf->menu.button_1_offset_x, \
		196);
	if (fdf->menu.button_2_status == 1)
		mlx_put_image_to_window(fdf->mlx_ptr, fdf->window_ptr, \
		fdf->menu.button_slider_on, fdf->menu.button_2_offset_x, \
		280);
	if (fdf->menu.button_2_status == 0)
		mlx_put_image_to_window(fdf->mlx_ptr, fdf->window_ptr, \
		fdf->menu.button_slider_off, fdf->menu.button_2_offset_x, \
		280);
	put_image_next(fdf);
}
