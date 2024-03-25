/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   click_slider_button.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 23:52:24 by lboiteux          #+#    #+#             */
/*   Updated: 2024/03/25 17:59:07 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	click_move_fdf(int keysym, t_fdf *fdf, int x, int y)
{
	if (keysym == 1)
	{
		fdf->mouse.x = x;
		fdf->mouse.y = y;
		if (fdf->mouse.click == 0)
			fdf->mouse.click = 1;
	}
}

void	click_slider_one(int keysym, t_fdf *fdf, int x, int y)
{
	if (keysym == 1)
	{
		fdf->mouse.x = x;
		fdf->mouse.y = y;
		if (fdf->menu.click_1 == 0)
		{
			fdf->menu.click_1 = 1;
			fdf->menu.button_1_status = 1;
		}
	}
	system("paplay ./sounds/click.ogg &");
}

void	click_slider_two(int keysym, t_fdf *fdf, int x, int y)
{
	if (keysym == 1)
	{
		fdf->mouse.x = x;
		fdf->mouse.y = y;
		if (fdf->menu.click_2 == 0)
		{
			fdf->menu.click_2 = 1;
			fdf->menu.button_2_status = 1;
		}
	}
	system("paplay ./sounds/click.ogg &");
}
