/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_info_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 23:29:22 by ymirna            #+#    #+#             */
/*   Updated: 2022/10/21 07:10:32 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	fill_float(t_minirt	*info, char	*str, int type)
{
	float	val;

	if (char_value(str, '.', 1, 1) || correct_chars(str, 1))
	{
		info->info_error = 4;
		return (0.0);
	}
	val = ft_atof(str);
	if (type == 1 && (0.0 <= val && val <= 1.0))
		return (val);
	else if (type == 2 && (0.0 <= val && val <= 180.0))
		return (val);
	else if (type == 3 && (0.0 <= val))
		return (val);
	info->info_error = 4;
	return (0.0);
}

unsigned int	fill_rgb(t_minirt	*info, char	*str)
{
	unsigned char	color_arr[3];
	char			**str_arr;
	int				i;

	if (char_value(str, ',', 2, 0) || correct_chars(str, 2))
	{
		info->info_error = 4;
		return (0);
	}
	str_arr = ft_split(str, ',');
	if (!str_arr)
	{
		info->info_error = 5;
		return (0);
	}
	i = 0;
	while (str_arr[i])
		i++;
	if (i > 2)
	{
		free_str_arr(str_arr);
		info->info_error = 4;
		return (0);
	}
	color_arr[0] = (int)ft_atof(str_arr[0]);
	color_arr[1] = (int)ft_atof(str_arr[1]);
	color_arr[2] = (int)ft_atof(str_arr[2]);
	return (create_trgb(color_arr[0], color_arr[1], color_arr[2]));
}

void	fill_coord(t_minirt	*info, t_coords	*coord, char	*str, int norm)
{
	char	**str_arr;
	int		i;

	if (char_value(str, '.', 3, 1) || char_value(str, ',', 2, 0))
	{
		info->info_error = 4;
		return ;
	}
	str_arr = ft_split(str, ',');
	if (!str_arr)
	{
		info->info_error = 5;
		return ;
	}
	i = 0;
	while (str_arr[i])
	{
		if (char_value(str_arr[i], '.', 1, 1) || char_value(str_arr[i], '-', 1, 1))
		{
			free_str_arr(str_arr);
			info->info_error = 4;
			return ;
		}
		i++;
	}
	if (i > 2)
	{
		free_str_arr(str_arr);
		info->info_error = 4;
		return ;
	}
	coord->x = ft_atof(str_arr[0]);
	coord->y = ft_atof(str_arr[1]);
	coord->z = ft_atof(str_arr[2]);
	if (norm)
	{
		if ((coord->x <= -1.0 && 1.0 <= coord->x) || (coord->y <= -1.0 && 1.0 <= coord->y) || (coord->z <= -1.0 && 1.0 <= coord->z))
			info->info_error = 4;
	}
	free_str_arr(str_arr);
	// ЕСТЬ ЛИ ДОПУСТИМАЯ ОБЛАСТЬ ЗНАЧЕНИЙ ДЛЯ ОБЫЧНЫХ КООРДИНАТ?
}

void	fill_cylinder(t_minirt	*info, char	*str)
{
	t_cylinder	*cyl_ptr;
	t_list		*cyl;
	char		**str_arr;

	info->check.cyl++;
	if (if_char(info, str[2], ' '))
		return ;
	str_arr = ft_split(str + 2, ' ');
	info->info_error = if_str_arr(info, str_arr, 5);
	if (info->info_error)
		return ;
	if (init_point(info, &cyl))
		return ;
	while (cyl->next != NULL)
		cyl = cyl->next;
	cyl_ptr = (t_cylinder	*)cyl->content;
	fill_coord(info, &cyl_ptr->center, str_arr[0], 0);
	fill_coord(info, &cyl_ptr->normal, str_arr[1], 1);
	cyl_ptr->radius = fill_float(info, str_arr[2], 3) / 2;
	cyl_ptr->height = fill_float(info, str_arr[3], 3);
	cyl_ptr->color = fill_rgb(info, str_arr[4]);
}
