/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_info_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 23:29:22 by ymirna            #+#    #+#             */
/*   Updated: 2022/10/24 01:57:24 by ymirna           ###   ########.fr       */
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

static char	**fill_rgb_split(t_minirt	*info, char	*str)
{
	char	**str_arr;
	int		i;
	
	if (char_value(str, ',', 2, 0) || correct_chars(str, 2))
	{
		info->info_error = 4;
		return (NULL);
	}
	str_arr = ft_split(str, ',');
	if (!str_arr)
	{
		info->info_error = 6;
		return (NULL);
	}
	i = 0;
	while (str_arr[i])
		i++;
	if (i != 3)
	{
		free_str_arr(str_arr);
		info->info_error = 4;
		return (NULL);
	}
	return (str_arr);
}

unsigned int	fill_rgb(t_minirt	*info, char	*str)
{
	unsigned char	color_arr[3];
	float			check_arr[3];
	char			**str_arr;
	int				i;

	str_arr = fill_rgb_split(info, str);
	if (info->info_error)
		return (0);
	i = 0;
	while (i < 3)
	{
		check_arr[i] = ft_atof(str_arr[i]);
		if (0 <= check_arr[i] && check_arr[i] <= 255)
			color_arr[i] = (int)check_arr[i];
		else
		{
			info->info_error = 4;
			return (0);
		}
		i++;
	}
	return (create_trgb(color_arr[0], color_arr[1], color_arr[2]));
}

void	fill_cylinder(t_minirt	*info, char	*str)
{
	t_cylinder	*cyl_ptr;
	t_list		*cyl;
	char		**str_arr;

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
	info->check.cyl++;
	printf("fill_cylinder, coord = %f|%f|%f, vector = %f|%f|%f, radius = %f, height = %f, color = %u\n", cyl_ptr->center.x, cyl_ptr->center.y, cyl_ptr->center.z, cyl_ptr->normal.x, cyl_ptr->normal.y, cyl_ptr->normal.z, cyl_ptr->radius, cyl_ptr->height, cyl_ptr->color);
}
