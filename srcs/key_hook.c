/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 06:05:48 by lboiteux          #+#    #+#             */
/*   Updated: 2024/03/25 17:59:07 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	keypressed(int keysym, void *fdf_void)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)fdf_void;
	if (keysym == ESCAPE)
		free_and_destroy_exit(0, fdf);
	if (keysym == KEY_V || keysym == KEY_N || keysym == KEY_B || \
		keysym == KEY_G)
		ft_rotate_mode(keysym, fdf);
	if (keysym == ARROW_DOWN || keysym == ARROW_LEFT || keysym == ARROW_UP || \
	keysym == ARROW_RIGHT)
		ft_translate(keysym, fdf);
	if (keysym == KEYPAD_7 || keysym == KEYPAD_9)
		ft_height(keysym, fdf);
	if (keysym == KEYPAD_1 || keysym == KEYPAD_2 || keysym == KEYPAD_3 || \
	keysym == KEYPAD_4 || keysym == KEYPAD_5 || keysym == KEYPAD_6)
		ft_rotate(keysym, fdf);
	if (keysym == KEYPAD_DIV || keysym == KEYPAD_MINUS \
	|| keysym == KEYPAD_PLUS || keysym == KEYPAD_MULT)
		ft_zoom(keysym, fdf);
	if (keysym == KEY_M)
		ft_menu(keysym, fdf);
	keypressed_next(keysym, fdf);
	print_matrix(fdf);
	return (0);
}

void	keypressed_next(int keysym, t_fdf *fdf)
{
	if (keysym == KEY_C)
		ft_color(fdf);
	if (keysym == KEYPAD_8)
		ft_line(fdf);
	if (keysym == SPACE)
		ft_is_rotate(fdf);
	if (keysym == KEY_P)
		ft_projection(fdf);
	if (keysym == KEY_R)
		ft_reset(fdf);
}
