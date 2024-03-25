/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:20:34 by lboiteux          #+#    #+#             */
/*   Updated: 2024/03/25 17:59:07 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	mouse_wheel(int keysym, void *fdf_void)
{
	t_fdf	*fdf;
	int		x;
	int		y;

	fdf = (t_fdf *)fdf_void;
	mlx_mouse_get_pos(fdf->mlx_ptr, &x, &y);
	if (fdf->camera.menu == 0 || (fdf->camera.menu == 1 && \
	!(x >= 33 && x <= 495 && y >= 30 && y <= 910)))
	{
		if (keysym == 1)
		{
			fdf->camera.zoom *= 1.1;
			fdf->camera.offset_x = (x - ((x - fdf->camera.offset_x) * 1.1));
			fdf->camera.offset_y = (y - ((y - fdf->camera.offset_y) * 1.1));
		}
		if (keysym == 2 && fdf->camera.zoom >= 1)
		{
			fdf->camera.zoom /= 1.1;
			fdf->camera.offset_x = (x - ((x - fdf->camera.offset_x) / 1.1));
			fdf->camera.offset_y = (y - ((y - fdf->camera.offset_y) / 1.1));
		}
	}
	ft_menu(0, fdf);
	print_matrix(fdf);
	return (0);
}

int	mouse_release(int keysym, void *fdf_void)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)fdf_void;
	if (keysym == 1)
	{
		fdf->mouse.click = 0;
		fdf->menu.click_1 = 0;
		fdf->menu.click_2 = 0;
		fdf->menu.button_1_status = 0;
		fdf->menu.button_2_status = 0;
		fdf->menu.iso_button_status = 0;
		fdf->menu.top_button_status = 0;
		fdf->menu.side_button_status = 0;
	}
	print_matrix(fdf);
	return (0);
}

int	mouse_press(int keysym, void *fdf_void)
{
	t_fdf	*fdf;
	int		x;
	int		y;

	fdf = (t_fdf *)fdf_void;
	mlx_mouse_get_pos(fdf->mlx_ptr, &x, &y);
	if (fdf->camera.menu == 0 || (fdf->camera.menu == 1 && \
	!(x >= 33 && x <= 495 && y >= 30 && y <= 910)))
		click_move_fdf(keysym, fdf, x, y);
	if (fdf->camera.menu == 1 && (x >= fdf->menu.button_1_offset_x \
	&& x <= fdf->menu.button_1_offset_x + 30 && y >= 196 && y <= 226))
		click_slider_one(keysym, fdf, x, y);
	if (fdf->camera.menu == 1 && (x >= fdf->menu.button_2_offset_x && \
	x <= fdf->menu.button_2_offset_x + 30 && y >= 280 && y <= 310))
		click_slider_two(keysym, fdf, x, y);
	if (fdf->camera.menu == 1 && (x >= 75 && x <= 223 && y >= 375 && y <= 402))
		click_top_button(keysym, fdf);
	if (fdf->camera.menu == 1 && (x >= 300 && x <= 450 && y >= 375 && y <= 403))
		click_iso_button(keysym, fdf);
	if (fdf->camera.menu == 1 && (x >= 187 && x <= 335 && y >= 325 && y <= 353))
		click_side_button(keysym, fdf);
	print_matrix(fdf);
	return (0);
}

int	mouse_move(void *fdf_void)
{
	t_fdf	*fdf;
	int		x;
	int		y;

	fdf = (t_fdf *)fdf_void;
	mlx_mouse_get_pos(fdf->mlx_ptr, &x, &y);
	if (fdf->mouse.click == 1)
	{
		fdf->camera.offset_y -= fdf->mouse.y - y;
		fdf->camera.offset_x += x - fdf->mouse.x;
	}
	if (fdf->menu.click_1 == 1)
		button_slider_1(fdf, x);
	if (fdf->menu.click_2 == 1)
		button_slider_2(fdf, x);
	if (fdf->camera.menu == 1)
		view_button(fdf, x, y);
	fdf->mouse.y = y;
	fdf->mouse.x = x;
	is_camera_rotate(fdf);
	print_matrix(fdf);
	return (0);
}
