/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_use_bis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 05:53:00 by lboiteux          #+#    #+#             */
/*   Updated: 2024/03/25 17:59:07 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_rotate_mode(int keysym, t_fdf *fdf)
{
	if (keysym == KEY_V)
		fdf->camera.rotate_type = 1;
	if (keysym == KEY_B)
		fdf->camera.rotate_type = 2;
	if (keysym == KEY_N)
		fdf->camera.rotate_type = 3;
	if (keysym == KEY_G)
		fdf->camera.rotate_type = 4;
	return (0);
}

int	ft_is_rotate(t_fdf *fdf)
{
	if (fdf->camera.rotate == 0)
		fdf->camera.rotate = 1;
	else if (fdf->camera.rotate == 1)
		fdf->camera.rotate = 0;
	return (0);
}

int	ft_zoom(int keysym, t_fdf *fdf)
{
	if (keysym == KEYPAD_DIV)
		fdf->camera.zoom /= 1.1;
	if (keysym == KEYPAD_MULT)
		fdf->camera.zoom *= 1.1;
	if (keysym == KEYPAD_PLUS)
		fdf->camera.zoom += 1;
	if (keysym == KEYPAD_MINUS)
		fdf->camera.zoom -= 1;
	if (fdf->camera.zoom < 1)
		fdf->camera.zoom = 1;
	ft_menu(0, fdf);
	return (0);
}

int	ft_line(t_fdf *fdf)
{
	if (fdf->camera.map_status == 0)
		fdf->camera.map_status = 1;
	else if (fdf->camera.map_status == 1)
		fdf->camera.map_status = 2;
	else if (fdf->camera.map_status == 2)
		fdf->camera.map_status = 3;
	else if (fdf->camera.map_status == 3)
		fdf->camera.map_status = 0;
	return (0);
}
