/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 06:11:47 by lboiteux          #+#    #+#             */
/*   Updated: 2024/03/25 17:59:07 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	is_camera_rotate(t_fdf *fdf)
{
	if (fdf->camera.rotate == 1)
	{
		if (fdf->camera.rotate_type == 1)
			fdf->camera.gamma += 0.01;
		if (fdf->camera.rotate_type == 2)
			fdf->camera.beta += 0.01;
		if (fdf->camera.rotate_type == 3)
			fdf->camera.alpha += 0.01;
		if (fdf->camera.rotate_type == 4)
		{
			fdf->camera.gamma += 0.01;
			fdf->camera.alpha += 0.01;
			fdf->camera.beta += 0.01;
		}
	}
}
