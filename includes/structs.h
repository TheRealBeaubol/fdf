/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:30:15 by lboiteux          #+#    #+#             */
/*   Updated: 2024/01/29 23:17:46 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
	double	pos;
}	t_color;

typedef struct s_colors
{
	t_color	*first_color;
	t_color	*scnd_color;
}	t_colors;

typedef struct s_mouse
{
	int		x;
	int		y;
	int		click;
}				t_mouse;

typedef struct s_point
{
	double	x;
	double	y;
	int		z;
	int		color;
}	t_point;

typedef struct s_bresenham
{
	int		dx;
	int		dy;
	int		yi;
	int		xi;
	int		d;
	double	y;
	double	x;
}	t_bresenham;

typedef struct s_camera
{
	long double	zoom;
	int			rotate;
	int			rotate_type;
	int			offset_x;
	int			offset_y;
	int			height;
	int			map_status;
	int			projection;
	double		alpha;
	double		beta;
	double		gamma;
	int			menu;
}	t_camera;

typedef struct s_menu
{
	void	*menu;
	void	*button_slider_on;
	void	*button_slider_off;
	void	*iso_button;
	void	*iso_button_hover;
	void	*top_button;
	void	*top_button_hover;
	void	*side_button;
	void	*side_button_hover;
	int		button_1_status;
	int		button_2_status;
	int		iso_button_status;
	int		top_button_status;
	int		side_button_status;
	int		menu_width;
	int		menu_height;
	int		button_size;
	int		click_1;
	int		click_2;
	int		button_1_offset_x;
	int		button_2_offset_x;
}	t_menu;

typedef struct s_fdf
{
	void		*mlx_ptr;
	void		*window_ptr;
	void		*img;
	char		*file_name;
	int			**color_matrix;
	int			**color_matrix_stock;
	int			color_palette;
	int			**height_matrix;
	int			height;
	int			width;
	int			ground;
	int			isinverted;
	t_menu		menu;
	t_point		point;
	t_camera	camera;
	t_bresenham	bresenham;
	t_mouse		mouse;
	t_colors	color;
}	t_fdf;

#endif