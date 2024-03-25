/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 07:35:12 by lboiteux          #+#    #+#             */
/*   Updated: 2024/02/02 10:23:17 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "define.h"
# include "structs.h"

/****************************************/
/*		  click_slider_button.c			*/
/****************************************/
void			click_move_fdf(int keysym, t_fdf *fdf, int x, int y);
void			click_slider_one(int keysym, t_fdf *fdf, int x, int y);
void			click_slider_two(int keysym, t_fdf *fdf, int x, int y);

/****************************************/
/*		   click_view_button.c			*/
/****************************************/
void			click_top_button(int keysym, t_fdf *fdf);
void			click_iso_button(int keysym, t_fdf *fdf);
void			click_side_button(int keysym, t_fdf *fdf);

/****************************************/
/*		     color_palette.c			*/
/****************************************/
int				get_z_color_bis(int z, t_fdf *fdf);
int				get_z_color(int z, t_fdf *fdf);
void			set_new_color(t_fdf *fdf);
int				ft_color(t_fdf *fdf);
/****************************************/
/*				exit.c					*/
/****************************************/
int				free_and_destroy_exit(int i, void *fdf_void);
int				free_and_destroy(t_fdf *fdf);

/****************************************/
/*				hook.c					*/
/****************************************/
int				keypressed(int keysym, void *fdf_void);
int				mouse_wheel(int keysym, void *fdf_void);
int				mouse_release(int keysym, void *fdf_void);
int				mouse_press(int keysym, void *fdf_void);
int				mouse_move(void *fdf_void);

/****************************************/
/*				init.c					*/
/****************************************/
void			camera_init(t_fdf *fdf);
void			map_init(t_fdf *fdf);
void			menu_images_init(t_fdf *fdf);
void			menu_init(t_fdf *fdf);
void			init(char *file_name, t_fdf *fdf);

/****************************************/
/*				keys_use.c				*/
/****************************************/
int				ft_translate(int keysym, t_fdf *fdf);
int				ft_height(int keysym, t_fdf *fdf);
int				ft_projection(t_fdf *fdf);
int				ft_rotate(int keysym, t_fdf *fdf);
int				ft_zoom(int keysym, t_fdf *fdf);

/****************************************/
/*			  menu_button.c 			*/
/****************************************/
void			view_button(t_fdf *fdf, int x, int y);
void			button_slider_1(t_fdf *fdf, int x);
void			button_slider_2(t_fdf *fdf, int x);

/****************************************/
/*		   		 menu.c 				*/
/****************************************/
int				ft_menu(int keysym, t_fdf *fdf);
void			put_image_next(t_fdf *fdf);
void			put_image(t_fdf *fdf);

/****************************************/
/*				parse.c					*/
/****************************************/
int				fdf_atoi(char *value);
int				check_line_error(char *str);
void			fill_matrix(t_fdf *fdf, char **split_val, int j);
void			fill_struct(char **split_val, t_fdf *fdf);
int				ft_parse(char *file_name, t_fdf *fdf);

/****************************************/
/*				plotline.c				*/
/****************************************/
void			plotline_low(t_fdf *fdf, t_point point1, t_point point2, \
	t_colors *color);
void			plotline_high(t_fdf *fdf, t_point point1, t_point point2, \
	t_colors *color);
void			plotline(t_fdf *fdf, t_point point1, t_point point2, \
	t_colors *color);

/****************************************/
/*			  print_matrix.c			*/
/****************************************/
void			print_matrix(t_fdf *fdf);
void			clear_window(t_fdf *fdf);

/****************************************/
/*				projection.c			*/
/****************************************/
void			isometric(t_point *point);
t_point			do_projection(long double x, long double y, t_fdf *fdf);
void			rotate_x(double *y, int *z, double alpha);
void			rotate_y(double *x, int *z, double beta);
void			rotate_z(double *x, double *y, double gamma);
/****************************************/
/*				utils.c					*/
/****************************************/
int				get_width_size(char *file_name, t_fdf *fdf);
int				get_height_size(char *file_name, t_fdf *fdf);

void			click_side_button(int keysym, t_fdf *fdf);
int				ft_reset(t_fdf *fdf);
int				ft_color(t_fdf *fdf);
int				ft_rotate_mode(int keysym, t_fdf *fdf);
int				ft_line(t_fdf *fdf);
unsigned int	get_gradient(t_colors *colors, double pos);
t_color			*ft_init_color(int n);
void			ft_set_color(t_color *curr, int n);
void			spherize(t_fdf *fdf, t_point *point);
int				ft_is_rotate(t_fdf *fdf);
void			keypressed_next(int keysym, t_fdf *fdf);
void			is_camera_rotate(t_fdf *fdf);
int				*find_most_frequent(t_fdf *fdf);
int				ft_ground(t_fdf *fdf);
int				zoom_definer(t_fdf *fdf);
void			print_straight_line_bis(t_fdf *fdf, t_colors color);
void			print_straight_line(t_fdf *fdf, t_colors color);
void			print_diagonale_bis(t_fdf *fdf, t_colors color);
void			print_diagonale(t_fdf *fdf, t_colors color);
void			parsing_error_exit(t_fdf *fdf, int fd, char *line, char *msg);
void			putstr_and_exit(char *err_msg);
void			free_mat(t_fdf *fdf);
int				palette_1(int z, t_fdf *fdf);
int				palette_2(int z, t_fdf *fdf);
int				palette_3(int z, t_fdf *fdf);
int				palette_4(int z, t_fdf *fdf);
int				palette_5(int z, t_fdf *fdf);
void			exit_map_init(t_fdf *fdf, int exit_type, int i);
#endif