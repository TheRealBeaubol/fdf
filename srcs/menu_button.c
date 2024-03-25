/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_button.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 23:22:53 by lboiteux          #+#    #+#             */
/*   Updated: 2024/03/25 17:59:07 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	button_slider_1(t_fdf *fdf, int x)
{
	fdf->menu.button_1_offset_x += x - fdf->mouse.x;
	if (fdf->menu.button_1_offset_x >= 420)
		fdf->menu.button_1_offset_x = 420;
	if (fdf->menu.button_1_offset_x <= 75)
		fdf->menu.button_1_offset_x = 75;
	fdf->camera.height = (1 + (fdf->menu.button_1_offset_x - 245) \
	* 0.1) * 2;
}

void	button_slider_2(t_fdf *fdf, int x)
{
	fdf->menu.button_2_offset_x += x - fdf->mouse.x;
	if (fdf->menu.button_2_offset_x >= 420)
		fdf->menu.button_2_offset_x = 420;
	if (fdf->menu.button_2_offset_x <= 75)
		fdf->menu.button_2_offset_x = 75;
	fdf->camera.zoom = (1 + (fdf->menu.button_2_offset_x - 75) * 0.1) * 2;
}

void	view_button(t_fdf *fdf, int x, int y)
{
	if (x >= 75 && x <= 223 && y >= 375 && y <= 402)
		fdf->menu.top_button_status = 1;
	else if (x >= 300 && x <= 450 && y >= 375 && y <= 403)
		fdf->menu.iso_button_status = 1;
	else if (x >= 187 && x <= 335 && y >= 325 && y <= 353)
		fdf->menu.side_button_status = 1;
	else
	{
		fdf->menu.top_button_status = 0;
		fdf->menu.iso_button_status = 0;
		fdf->menu.side_button_status = 0;
	}
}
