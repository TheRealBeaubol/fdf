/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:24:29 by lboiteux          #+#    #+#             */
/*   Updated: 2024/03/25 17:59:07 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	camera_init(t_fdf *fdf)
{
	fdf->camera.offset_x = ((WIDTH) / 2) + 250;
	fdf->camera.offset_y = (HEIGHT / 2);
	fdf->camera.height = 1;
	fdf->camera.projection = 1;
	fdf->camera.gamma = 0;
	fdf->camera.beta = 0;
	fdf->camera.alpha = 0;
	fdf->camera.zoom = zoom_definer(fdf);
	fdf->camera.menu = 1;
	fdf->camera.map_status = 0;
	fdf->camera.rotate = 0;
	fdf->camera.rotate_type = 1;
	fdf->mouse.x = 0;
	fdf->mouse.y = 0;
	fdf->mouse.click = 0;
}

void	map_init(t_fdf *fdf)
{
	int	i;

	fdf->height_matrix = ft_calloc(fdf->width + 1, sizeof(int *));
	if (!fdf->height_matrix)
		exit_map_init(fdf, 0, 0);
	fdf->color_matrix = ft_calloc(fdf->width + 1, sizeof(int *));
	if (!fdf->color_matrix)
		exit_map_init(fdf, 1, 0);
	i = -1;
	while (++i != fdf->width)
	{
		fdf->height_matrix[i] = ft_calloc(fdf->height + 1, sizeof(int));
		if (!fdf->height_matrix[i])
			exit_map_init(fdf, 2, i);
	}
	i = -1;
	while (++i != fdf->width)
	{
		fdf->color_matrix[i] = ft_calloc(fdf->height + 1, sizeof(int));
		if (!fdf->color_matrix[i])
			exit_map_init(fdf, 3, i);
	}
	camera_init(fdf);
}

void	menu_images_init(t_fdf *fdf)
{
	int	slider_size;
	int	button_height;
	int	button_width;

	slider_size = 30;
	button_height = 75;
	button_width = 150;
	fdf->menu.button_slider_on = mlx_png_file_to_image(fdf->mlx_ptr, \
	"images/button_slider_on.png", &slider_size, &slider_size);
	fdf->menu.button_slider_off = mlx_png_file_to_image(fdf->mlx_ptr, \
	"images/button_slider_off.png", &slider_size, &slider_size);
	fdf->menu.iso_button = mlx_png_file_to_image(fdf->mlx_ptr, \
	"images/iso_button.png", &button_width, &button_height);
	fdf->menu.iso_button_hover = mlx_png_file_to_image(fdf->mlx_ptr, \
	"images/iso_button_hover.png", &button_width, &button_height);
	fdf->menu.top_button = mlx_png_file_to_image(fdf->mlx_ptr, \
	"images/top_button.png", &button_width, &button_height);
	fdf->menu.top_button_hover = mlx_png_file_to_image(fdf->mlx_ptr, \
	"images/top_button_hover.png", &button_width, &button_height);
	fdf->menu.side_button = mlx_png_file_to_image(fdf->mlx_ptr, \
	"images/side_button.png", &button_width, &button_height);
	fdf->menu.side_button_hover = mlx_png_file_to_image(fdf->mlx_ptr, \
	"images/side_button_hover.png", &button_width, &button_height);
}

void	menu_init(t_fdf *fdf)
{
	fdf->menu.button_1_offset_x = (5 * (fdf->camera.height + 47));
	fdf->menu.button_2_offset_x = (5 * (fdf->camera.zoom + 13));
	fdf->menu.click_1 = 0;
	fdf->menu.click_2 = 0;
	fdf->menu.menu_width = 600;
	fdf->menu.menu_height = 1080;
	fdf->menu.top_button_status = 0;
	fdf->menu.iso_button_status = 0;
	fdf->menu.side_button_status = 0;
	fdf->menu.button_1_status = 0;
	fdf->menu.button_2_status = 0;
	fdf->menu.menu = mlx_png_file_to_image(fdf->mlx_ptr, "images/menu.png", \
	&fdf->menu.menu_width, &fdf->menu.menu_height);
	menu_images_init(fdf);
}

void	init(char *file_name, t_fdf *fdf)
{
	fdf->file_name = file_name;
	if (ft_strlen(file_name) < 5)
		putstr_and_exit("Wronge file type :\n Required file type -> '.fdf'\n");
	if (ft_strncmp(&file_name[ft_strlen(file_name) - 4], ".fdf", 4))
		putstr_and_exit("Wronge file type :\n Required file type -> '.fdf'\n");
	fdf->width = get_width_size(fdf->file_name, fdf);
	fdf->height = get_height_size(fdf->file_name, fdf);
	map_init(fdf);
	fdf->height = 0;
	fdf->width = 0;
	ft_parse(file_name, fdf);
	fdf->color_matrix_stock = ft_dup_int_tab(fdf->color_matrix, \
	fdf->width + 1, fdf->height + 1);
	if (fdf->color_matrix_stock == NULL)
		free_mat(fdf);
	fdf->mlx_ptr = mlx_init();
	if (fdf->mlx_ptr == NULL)
		exit (1);
	fdf->img = mlx_new_image(fdf->mlx_ptr, WIDTH, HEIGHT);
	fdf->window_ptr = mlx_new_window(fdf->mlx_ptr, WIDTH, HEIGHT, "A");
	if (fdf->window_ptr == NULL)
		free_and_destroy(fdf);
	menu_init(fdf);
	fdf->color_palette = 0;
	fdf->ground = ft_ground(fdf);
}
