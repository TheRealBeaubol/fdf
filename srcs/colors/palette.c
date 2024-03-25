/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:30:41 by lboiteux          #+#    #+#             */
/*   Updated: 2024/03/25 18:07:55 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	palette_1(int z, t_fdf *fdf)
{
	if (fdf->camera.height < 0)
		z = -z;
	if (z < fdf->ground - 50)
		return (ft_atoi_base("003366", "0123456789ABCDEF"));
	else if (z < fdf->ground - 15)
		return (ft_atoi_base("1962E1", "0123456789ABCDEF"));
	else if (z < fdf->ground)
		return (ft_atoi_base("99CCFF", "0123456789ABCDEF"));
	else if (z < fdf->ground + 5)
		return (ft_atoi_base("009A00", "0123456789ABCDEF"));
	else if (z < fdf->ground + 20)
		return (ft_atoi_base("FFB266", "0123456789ABCDEF"));
	else if (z < fdf->ground + 40)
		return (ft_atoi_base("C16100", "0123456789ABCDEF"));
	else if (z < fdf->ground + 60)
		return (ft_atoi_base("945700", "0123456789ABCDEF"));
	else if (z < fdf->ground + 90)
		return (ft_atoi_base("693502", "0123456789ABCDEF"));
	else
		return (ft_atoi_base("FFFFFF", "0123456789ABCDEF"));
}

int	palette_2(int z, t_fdf *fdf)
{
	if (fdf->camera.height < 0)
		z = -z;
	if (z < fdf->ground - 20)
		return (ft_atoi_base("9A1F6A", "0123456789ABCDEF"));
	else if (z < fdf->ground)
		return (ft_atoi_base("C2294E", "0123456789ABCDEF"));
	else if (z < fdf->ground + 15)
		return (ft_atoi_base("EC4B27", "0123456789ABCDEF"));
	else if (z < fdf->ground + 45)
		return (ft_atoi_base("EF8633", "0123456789ABCDEF"));
	else
		return (ft_atoi_base("F3AF3D", "0123456789ABCDEF"));
}

int	palette_3(int z, t_fdf *fdf)
{
	if (fdf->camera.height < 0)
		z = -z;
	if (z < fdf->ground - 50)
		return (ft_atoi_base("277DA1", "0123456789ABCDEF"));
	else if (z < fdf->ground - 15)
		return (ft_atoi_base("577590", "0123456789ABCDEF"));
	else if (z < fdf->ground)
		return (ft_atoi_base("4D908E", "0123456789ABCDEF"));
	else if (z < fdf->ground + 5)
		return (ft_atoi_base("43AA8B", "0123456789ABCDEF"));
	else if (z < fdf->ground + 20)
		return (ft_atoi_base("90BE6D", "0123456789ABCDEF"));
	else if (z < fdf->ground + 40)
		return (ft_atoi_base("F9C74F", "0123456789ABCDEF"));
	else if (z < fdf->ground + 60)
		return (ft_atoi_base("F9844A", "0123456789ABCDEF"));
	else if (z < fdf->ground + 90)
		return (ft_atoi_base("F8961E", "0123456789ABCDEF"));
	else if (z < fdf->ground + 100)
		return (ft_atoi_base("F3722C", "0123456789ABCDEF"));
	else
		return (ft_atoi_base("F94144", "0123456789ABCDEF"));
}

int	palette_4(int z, t_fdf *fdf)
{
	if (fdf->camera.height < 0)
		z = -z;
	if (z < fdf->ground - 25)
		return (ft_atoi_base("5F0F40", "0123456789ABCDEF"));
	else if (z < fdf->ground)
		return (ft_atoi_base("9A031E", "0123456789ABCDEF"));
	else if (z < fdf->ground + 15)
		return (ft_atoi_base("FB8B24", "0123456789ABCDEF"));
	else if (z < fdf->ground + 45)
		return (ft_atoi_base("E36414", "0123456789ABCDEF"));
	else
		return (ft_atoi_base("0F4C5C", "0123456789ABCDEF"));
}

int	palette_5(int z, t_fdf *fdf)
{
	if (fdf->camera.height < 0)
		z = -z;
	if (z < fdf->ground - 50)
		return (ft_atoi_base("4D1A7F", "0123456789ABCDEF"));
	else if (z < fdf->ground - 25)
		return (ft_atoi_base("CC99FF", "0123456789ABCDEF"));
	else if (z < fdf->ground)
		return (ft_atoi_base("EDBDFF", "0123456789ABCDEF"));
	else if (z < fdf->ground + 15)
		return (ft_atoi_base("FFE8FA", "0123456789ABCDEF"));
	else if (z < fdf->ground + 45)
		return (ft_atoi_base("FF91BF", "0123456789ABCDEF"));
	else
		return (ft_atoi_base("F7638F", "0123456789ABCDEF"));
}
