/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 22:31:18 by lboiteux          #+#    #+#             */
/*   Updated: 2024/03/25 17:59:07 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av)
{
	t_fdf	fdf;

	if (ac == 2)
	{
		if (HEIGHT < 1080 || WIDTH < 600)
			putstr_and_exit("Resize the window please : \nMinimum height -> 1080\
				\nMinimum width -> 600\n");
		init(av[1], &fdf);
		print_matrix(&fdf);
		mlx_on_event((&fdf)->mlx_ptr, (&fdf)->window_ptr, MLX_KEYDOWN, \
		&keypressed, &fdf);
		mlx_on_event((&fdf)->mlx_ptr, (&fdf)->window_ptr, MLX_WINDOW_EVENT, \
		&free_and_destroy_exit, &fdf);
		mlx_on_event((&fdf)->mlx_ptr, (&fdf)->window_ptr, MLX_MOUSEWHEEL, \
		&mouse_wheel, &fdf);
		mlx_on_event((&fdf)->mlx_ptr, (&fdf)->window_ptr, MLX_MOUSEDOWN, \
		&mouse_press, &fdf);
		mlx_on_event((&fdf)->mlx_ptr, (&fdf)->window_ptr, MLX_MOUSEUP, \
		&mouse_release, &fdf);
		mlx_loop_hook((&fdf)->mlx_ptr, &mouse_move, &fdf);
		system("paplay ./sounds/strad_music_minecraft.ogg &");
		mlx_loop(fdf.mlx_ptr);
	}
	return (0);
}
