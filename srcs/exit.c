/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:01:56 by lboiteux          #+#    #+#             */
/*   Updated: 2024/03/25 17:59:07 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	putstr_and_exit(char *err_msg)
{
	ft_putstr_fd(err_msg, 2);
	exit (EXIT_FAILURE);
}

void	parsing_error_exit(t_fdf *fdf, int fd, char *line, char *msg)
{
	get_next_line(fd, 1);
	close(fd);
	free(line);
	(void)fdf;
	putstr_and_exit(msg);
}

void	free_mat(t_fdf *fdf)
{
	fdf->width = get_width_size(fdf->file_name, fdf);
	ft_free_int_tab(fdf->color_matrix, fdf->width);
	ft_free_int_tab(fdf->height_matrix, fdf->width);
	exit (EXIT_FAILURE);
}

int	free_and_destroy(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx_ptr, fdf->img);
	mlx_destroy_image(fdf->mlx_ptr, fdf->menu.menu);
	mlx_destroy_image(fdf->mlx_ptr, fdf->menu.button_slider_on);
	mlx_destroy_image(fdf->mlx_ptr, fdf->menu.button_slider_off);
	mlx_destroy_image(fdf->mlx_ptr, fdf->menu.iso_button);
	mlx_destroy_image(fdf->mlx_ptr, fdf->menu.iso_button_hover);
	mlx_destroy_image(fdf->mlx_ptr, fdf->menu.top_button);
	mlx_destroy_image(fdf->mlx_ptr, fdf->menu.top_button_hover);
	mlx_destroy_image(fdf->mlx_ptr, fdf->menu.side_button);
	mlx_destroy_image(fdf->mlx_ptr, fdf->menu.side_button_hover);
	mlx_destroy_window(fdf->mlx_ptr, fdf->window_ptr);
	mlx_destroy_display(fdf->mlx_ptr);
	free_mat(fdf);
	return (0);
}

int	free_and_destroy_exit(int i, void *fdf_void)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)fdf_void;
	if (i == 0)
	{
		system("paplay ./sounds/click.ogg &");
		system("killall paplay");
		free(fdf->color.first_color);
		free(fdf->color.scnd_color);
		free_and_destroy(fdf);
	}
	return (0);
}
