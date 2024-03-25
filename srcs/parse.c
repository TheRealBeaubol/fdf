/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 22:44:15 by lboiteux          #+#    #+#             */
/*   Updated: 2024/03/25 17:59:07 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	fdf_atoi(char *value)
{
	int	i;
	int	stock;
	int	sign;

	sign = 1;
	i = 0;
	stock = 0;
	if (value[0] == '-')
	{
		sign *= -1;
		i++;
	}
	while (value[i] != '\0' && value[i] != '\n')
	{
		stock = (stock * 10) + (value[i] - 48);
		i++;
	}
	return (stock * sign);
}

int	check_line_error(char *str)
{
	int		i;
	int		cpt;

	cpt = 0;
	i = 0;
	if (str[0] == '-' && str[1] != '\0')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == ',')
	{
		i++;
		if (str[i] == '0' && str[i + 1] == 'x')
			i += 2;
		else
			return (1);
		while (str[i] != '\0')
			if (ft_ishexa(str[i++]) == 0 || cpt > 6)
				return (1);
	}
	if (str[i] != '\0')
		return (1);
	return (0);
}

void	fill_matrix(t_fdf *fdf, char **split_val, int j)
{
	int		nb;
	char	**split_tab;
	char	*color;

	split_tab = NULL;
	if (ft_strchr(split_val[j], ','))
	{
		split_tab = ft_char_split(split_val[j], ',');
		nb = fdf_atoi(split_tab[0]);
		color = ft_str_lower(ft_strcut(split_tab[1], "0x"));
		fdf->color_matrix[fdf->width][fdf->height] = \
		ft_atoi_base(color, "0123456789abcdef");
		fdf->height_matrix[fdf->width][fdf->height++] = nb;
		ft_free_tab(split_tab);
		free(color);
	}
	else
	{
		nb = fdf_atoi(split_val[j]);
		fdf->color_matrix[fdf->width][fdf->height] = 0xffffff;
		fdf->height_matrix[fdf->width][fdf->height] = nb;
		fdf->height += 1;
	}
}

void	fill_struct(char **split_val, t_fdf *fdf)
{
	int		j;

	j = 0;
	fdf->height = 0;
	while (split_val[j] != 0)
	{
		if (check_line_error(split_val[j]) == 0)
		{
			fill_matrix(fdf, split_val, j);
			j++;
		}
		else
		{
			ft_free_int_tab(fdf->height_matrix, \
				get_height_size(fdf->file_name, fdf));
			fdf->height_matrix = NULL;
			return ;
		}
	}
}

int	ft_parse(char *file_name, t_fdf *fdf)
{
	char	*line;
	char	**split_tab;
	int		fd;

	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd, 0);
	while (line != NULL)
	{
		split_tab = ft_str_split(line, " \n");
		fill_struct(split_tab, fdf);
		fdf->width += 1;
		free(line);
		ft_free_tab(split_tab);
		if (fdf->height_matrix == NULL)
		{
			write (2, "Map Error\n", 11);
			free_mat(fdf);
		}
		line = get_next_line(fd, 0);
	}
	close(fd);
	return (1);
}
