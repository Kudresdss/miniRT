/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_info_3_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 01:55:05 by ymirna            #+#    #+#             */
/*   Updated: 2022/10/24 19:14:42 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static char	**fill_coord_split(t_minirt	*info, char	*str, int i)
{
	char	**str_arr;

	str_arr = ft_split(str, ',');
	if (!str_arr)
	{
		info->info_error = 6;
		return (NULL);
	}
	while (str_arr[i])
	{
		if (char_value(str_arr[i], '.', 1, 1) || char_value(str_arr[i], '-', 1, 1))
		{
			free_str_arr(str_arr);
			info->info_error = 4;
			return (NULL);
		}
		i++;
	}
	if (i != 3)
	{
		free_str_arr(str_arr);
		info->info_error = 4;
		return (NULL);
	}
	return (str_arr);
}

void	fill_coord(t_minirt	*info, t_coords	*coord, char	*str, int norm)
{
	char	**str_arr;
	int		i;

	if (info->info_error)
		return ;
	if (char_value(str, '.', 3, 1) || char_value(str, ',', 2, 0))
	{
		info->info_error = 4;
		return ;
	}
	i = 0;
	str_arr = fill_coord_split(info, str, i);
	if (info->info_error)
		return ;
	coord->x = ft_atof(str_arr[0]);
	coord->y = ft_atof(str_arr[1]);
	coord->z = ft_atof(str_arr[2]);
	if (norm)
	{
		if ((-1.0 <= coord->x && coord->x <= 1.0) && (-1.0 <= coord->y && coord->y <= 1.0) && (-1.0 <= coord->z && coord->z <= 1.0))
			norm = 0;
	}
	if (norm)
		info->info_error = 4;
	free_str_arr(str_arr);
}
