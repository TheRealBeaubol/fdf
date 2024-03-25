/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:54:18 by lboiteux          #+#    #+#             */
/*   Updated: 2024/03/25 17:59:07 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	get_height_size(char *file_name, t_fdf *fdf)
{
	char	*line;
	int		cpt;
	int		fd;

	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd, 0);
	if (!line)
		parsing_error_exit(fdf, fd, line, "Map Error\n");
	cpt = ft_count_words(line, ' ');
	while (line != NULL)
	{
		if (ft_count_words(line, ' ') != cpt)
			parsing_error_exit(fdf, fd, line, "Map Error\n");
		else
		{
			free(line);
			line = get_next_line(fd, 0);
		}
	}
	free(line);
	close(fd);
	return (cpt);
}

int	get_width_size(char *file_name, t_fdf *fdf)
{
	char	*line;
	int		cpt;
	int		fd;

	fd = open(file_name, O_RDONLY);
	cpt = 0;
	line = get_next_line(fd, 0);
	if (!line || (9 <= line[0] && line[0] <= 13) || (line[0] == 32 && \
		(line[1] == '\0' || line[1] == '\n')))
		parsing_error_exit(fdf, fd, line, "Empty map file or no file found\n");
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd, 0);
		cpt += 1;
	}
	close(fd);
	return (cpt);
}

int	*find_most_frequent(t_fdf *fdf)
{
	int	*height;
	int	x;
	int	y;

	x = -1;
	height = malloc(4000 * sizeof(int *));
	if (!height)
		return (NULL);
	while (++x != 4000)
		height[x] = 0;
	x = -1;
	while (++x != fdf->width)
	{
		y = -1;
		while (++y != fdf->height)
			height[fdf->height_matrix[x][y] + 2000] += 1;
	}
	return (height);
}

int	zoom_definer(t_fdf *fdf)
{
	if (fdf->height <= 30 && fdf->width <= 30)
		return (35);
	else if (fdf->height <= 60 && fdf->width <= 60)
		return (15);
	else if (fdf->height <= 100 && fdf->width <= 100)
		return (10);
	else if (fdf->height <= 150 && fdf->width <= 150)
		return (5);
	else if (fdf->height <= 500 && fdf->width <= 500)
		return (2);
	else
		return (1);
}

int	ft_ground(t_fdf *fdf)
{
	int	ground;
	int	*height;
	int	x;
	int	return_val;

	height = find_most_frequent(fdf);
	ground = height[fdf->height_matrix[0][0] + 2000];
	return_val = fdf->height_matrix[0][0] + 2000;
	x = -1;
	while (++x != 4000)
	{
		if (height[x] > ground)
		{
			ground = height[x];
			return_val = x;
		}
	}
	free(height);
	return (return_val - 2000);
}
