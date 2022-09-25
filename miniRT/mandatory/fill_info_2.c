/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_info_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 23:29:22 by ymirna            #+#    #+#             */
/*   Updated: 2022/09/26 01:31:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/mini_rt.h"

int	fill_coord(char	*str, float	*x, float	*y, float	*z)
{
	char	**str_arr;

	if (coord_valid(str))
		return (1);
	str_arr = ft_split(str, ',');
	if (!str_arr)
		malloc_error();
	return (0);
}

void	fill_cylinder(ray_t	*info, char	*str)
{
	cylinder_t	cyl;
	char		**str_arr;
	int			i;

	if (info->cylinders == NULL)
		info->cylinders = &cyl;
	else
		info->cylinders->next = &cyl;
	if (if_char(info, str[2], ' ')
		return ;
	str_arr = ft_split(str + 2, ' ');
	if (if_str_arr(info, str_arr))
		return ;
	if (!fill_coord(str_arr[0], &cyl.x, &cyl.y, &cyl.z))
	{
		if (!fill_vector(str_arr[1], &cyl.v_x, &cyl.v_y, &cyl.v_z))
		{
			cyl.diameter = ft_atof(info, str_arr[2]);
			cyl.height = ft_atof(info, str_arr[3]);
			cyl.rgb = fill_rgb(info, str_arr[4]);
			return ;
		}
	}
	info->info_error = 4;
}
