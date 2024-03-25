/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 22:42:13 by lboiteux          #+#    #+#             */
/*   Updated: 2024/03/25 18:07:53 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double	map(double start, double end, double val)
{
	return (start + (end - start) * val);
}

t_color	*ft_init_color(int n)
{
	t_color	*new;

	new = malloc(sizeof(t_color));
	if (!new)
		return (NULL);
	new->r = (n >> 16) & 0xFF;
	new->g = (n >> 8) & 0xFF;
	new->b = n & 0xFF;
	return (new);
}

void	ft_set_color(t_color *curr, int n)
{
	curr->r = (n >> 16) & 0xFF;
	curr->g = (n >> 8) & 0xFF;
	curr->b = n & 0xFF;
}

unsigned int	get_gradient(t_colors *colors, double pos)
{
	unsigned int	color;

	color = 0xFF000000;
	color += (int) map(colors->first_color->r, \
		colors->scnd_color->r, pos) << 16;
	color += (int) map(colors->first_color->g, \
		colors->scnd_color->g, pos) << 8;
	color += (int) map(colors->first_color->b, \
		colors->scnd_color->b, pos);
	return (color);
}
