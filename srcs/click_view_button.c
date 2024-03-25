/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   click_view_button.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 05:57:04 by lboiteux          #+#    #+#             */
/*   Updated: 2024/03/25 17:59:07 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	click_top_button(int keysym, t_fdf *fdf)
{
	if (keysym == 1 && fdf->camera.projection != 2)
	{
		fdf->camera.gamma = 0.00001;
		fdf->camera.beta = 0.00001;
		fdf->camera.alpha = 0.00001;
		fdf->menu.top_button_status = 2;
		fdf->camera.projection = 2;
	}
	else if (keysym == 1 && fdf->camera.projection == 2)
	{
		fdf->camera.gamma = 0.00001;
		fdf->camera.beta = 0.00001;
		fdf->camera.alpha = 0.00001;
		fdf->camera.projection = 2;
	}
	system("paplay ./sounds/click.ogg &");
}

void	click_iso_button(int keysym, t_fdf *fdf)
{
	if (keysym == 1 && fdf->camera.projection != 1)
	{
		fdf->camera.gamma = 0.00001;
		fdf->camera.beta = 0.00001;
		fdf->camera.alpha = 0.00001;
		fdf->menu.iso_button_status = 2;
		fdf->camera.projection = 1;
	}
	else if (keysym == 1 && fdf->camera.projection == 1)
	{
		fdf->camera.gamma = 0.00001;
		fdf->camera.beta = 0.00001;
		fdf->camera.alpha = 0.00001;
		fdf->camera.projection = 1;
	}
	system("paplay ./sounds/click.ogg &");
}

void	click_side_button(int keysym, t_fdf *fdf)
{
	if (keysym == 1 && fdf->camera.projection != 3)
	{
		fdf->camera.gamma = 0.00001;
		fdf->camera.beta = 0.00001;
		fdf->camera.alpha = 0.00001;
		fdf->menu.side_button_status = 2;
		fdf->camera.projection = 3;
	}
	else if (keysym == 1 && fdf->camera.projection == 3)
	{
		fdf->camera.gamma = 0.00001;
		fdf->camera.beta = 0.00001;
		fdf->camera.alpha = 0.00001;
		fdf->camera.projection = 3;
	}
	system("paplay ./sounds/click.ogg &");
}
