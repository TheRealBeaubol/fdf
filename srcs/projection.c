/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:22:56 by lboiteux          #+#    #+#             */
/*   Updated: 2024/03/25 17:59:07 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	isometric(t_point *point)
{
	long double	stock_x;
	long double	stock_y;

	stock_x = (*point).x;
	stock_y = (*point).y;
	(*point).x = (stock_x - stock_y) * -cos((45 * PI) / 180);
	(*point).y = (stock_x + stock_y - (*point).z) * sin((25 * PI) / 180);
}

void	rotate_x(double *y, int *z, double alpha)
{
	long double	stock_y;

	stock_y = *y;
	*y = stock_y * cos(alpha) + *z * sin(alpha);
	*z = -stock_y * sin(alpha) + *z * cos(alpha);
}

void	rotate_y(double *x, int *z, double beta)
{
	long double	stock_x;

	stock_x = *x;
	*x = stock_x * cos(beta) + *z * sin(beta);
	*z = -stock_x * sin(beta) + *z * cos(beta);
}

void	rotate_z(double *x, double *y, double gamma)
{
	long double	stock_x;
	long double	stock_y;

	stock_x = *x;
	stock_y = *y;
	*x = stock_x * cos(gamma) - stock_y * sin(gamma);
	*y = stock_x * sin(gamma) + stock_y * cos(gamma);
}

t_point	do_projection(long double x, long double y, t_fdf *fdf)
{
	t_point	point;

	point.z = ((fdf->height_matrix[(int)x][(int)y] - fdf->ground) * \
		fdf->camera.height) * fdf->camera.zoom / 2;
	point.x = x * fdf->camera.zoom - (fdf->width * fdf->camera.zoom) / 2;
	point.y = y * fdf->camera.zoom - (fdf->height * fdf->camera.zoom) / 2;
	rotate_x(&point.y, &point.z, fdf->camera.alpha);
	rotate_y(&point.x, &point.z, fdf->camera.beta);
	rotate_z(&point.x, &point.y, fdf->camera.gamma);
	if (fdf->camera.projection == 1)
		isometric(&point);
	if (fdf->camera.projection == 2)
	{
		point.x = point.x;
		point.y = -point.y;
	}
	if (fdf->camera.projection == 3)
	{
		point.x = -point.x;
		point.y = -point.z;
	}
	point.x += fdf->camera.offset_x;
	point.y += fdf->camera.offset_y;
	return (point);
}
