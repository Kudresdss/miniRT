/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_info_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 23:29:22 by ymirna            #+#    #+#             */
/*   Updated: 2022/10/10 20:36:24 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	fill_coord(char	*str, t_coordinates	*coord)
{
	char	**str_arr;

	if (coord_valid(str))
		return (1);
	str_arr = ft_split(str, ',');
	if (!str_arr)
		malloc_error();
	return (0);
}

void	fill_cylinder(t_minirt	*info, char	*str)
{
	cylinder_t	cyl;
	char		**str_arr;
	int			i;

	if (info->cylinders == NULL)
		info->cylinders = &cyl;
	else
		info->cylinders->next = &cyl;
	if (if_char(info, str[2], ' '))
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
