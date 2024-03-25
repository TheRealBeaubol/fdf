/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plotline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:48:14 by lboiteux          #+#    #+#             */
/*   Updated: 2024/03/25 17:59:07 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_pixel_low(t_fdf *fdf, t_colors *color, t_point point1, \
	t_point point2)
{
	if (fdf->isinverted == 1)
		mlx_set_image_pixel(fdf->mlx_ptr, fdf->img, fdf->bresenham.x, \
			fdf->bresenham.y, get_gradient(color, fabs(fdf->bresenham.y - \
			point1.y) / (fabs(point2.y - point1.y) + 0.0000001)));
	else
		mlx_set_image_pixel(fdf->mlx_ptr, fdf->img, fdf->bresenham.x, \
			fdf->bresenham.y, get_gradient(color, 1 - fabs(fdf->bresenham.y - \
			point1.y) / (fabs(point2.y - point1.y) + 0.0000001)));
}

void	print_pixel_high(t_fdf *fdf, t_colors *color, t_point point1, \
	t_point point2)
{
	if (fdf->isinverted == 1)
		mlx_set_image_pixel(fdf->mlx_ptr, fdf->img, fdf->bresenham.x, \
			fdf->bresenham.y, get_gradient(color, \
			fabs(fdf->bresenham.x - point1.x) / \
			(fabs(point2.x - point1.x) + 0.0000001)));
	else
		mlx_set_image_pixel(fdf->mlx_ptr, fdf->img, fdf->bresenham.x, \
			fdf->bresenham.y, get_gradient(color, 1 - fabs(fdf->bresenham.x - \
			point1.x) / (fabs(point2.x - point1.x) + 0.0000001)));
}

void	plotline_low(t_fdf *fdf, t_point point1, t_point point2, \
	t_colors *color)
{
	t_bresenham	bresenham;

	bresenham.yi = 1;
	bresenham.dx = point2.x - point1.x;
	bresenham.dy = point2.y - point1.y;
	if (bresenham.dy < 0)
	{
		bresenham.yi = -1;
		bresenham.dy *= -1;
	}
	bresenham.d = (2 * bresenham.dy) - bresenham.dx;
	bresenham.y = point1.y;
	bresenham.x = point1.x;
	while (bresenham.x <= point2.x)
	{
		fdf->bresenham = bresenham;
		print_pixel_low(fdf, color, point1, point2);
		if (bresenham.d > 0)
		{
			bresenham.y += bresenham.yi;
			bresenham.d += -2 * bresenham.dx;
		}
		bresenham.d += 2 * bresenham.dy;
		bresenham.x++;
	}
}

void	plotline_high(t_fdf *fdf, t_point point1, t_point point2, \
	t_colors *color)
{
	t_bresenham	bresenham;

	bresenham.dx = point2.x - point1.x;
	bresenham.dy = point2.y - point1.y;
	bresenham.xi = 1;
	if (bresenham.dx < 0)
	{
		bresenham.xi = -1;
		bresenham.dx *= -1;
	}
	bresenham.d = (2 * bresenham.dx) - bresenham.dy;
	bresenham.x = point1.x;
	bresenham.y = point1.y;
	while (bresenham.y <= point2.y)
	{
		fdf->bresenham = bresenham;
		print_pixel_high(fdf, color, point1, point2);
		if (bresenham.d > 0)
		{
			bresenham.x += bresenham.xi;
			bresenham.d += -2 * bresenham.dy;
		}
		bresenham.d += 2 * bresenham.dx;
		bresenham.y++;
	}
}

void	plotline(t_fdf *fdf, t_point point2, t_point point1, t_colors *color)
{
	fdf->isinverted = 0;
	if (abs((int)point2.y - (int)point1.y) < abs((int)point2.x - (int)point1.x))
	{
		if ((point2.x - point1.x) > 0)
			plotline_low(fdf, point1, point2, color);
		else
		{
			fdf->isinverted = 1;
			plotline_low(fdf, point2, point1, color);
		}
	}
	else
	{
		if ((point2.y - point1.y) > 0)
			plotline_high(fdf, point1, point2, color);
		else
		{
			fdf->isinverted = 1;
			plotline_high(fdf, point2, point1, color);
		}
	}
}
