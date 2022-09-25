/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_info_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 23:29:19 by ymirna            #+#    #+#             */
/*   Updated: 2022/09/26 00:56:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/mini_rt.h"

//ВО ВСЕХ ФУНКЦИЯХ ЗАПОЛНЕНИЯ ЧЕКАТЬ КОРРЕКТНОСТЬ СТРОКИ, ПОДАВАТЬ ВСЮДУ
//INFO_ERROR ДЛЯ ПРОВЕРКИ В РОДИТЕЛЬСКОЙ ФУНКЦИИ

void	fill_ambient(ray_t	*info, char	*str)
{
	ambient_t	amb;
	char		**str_arr;
	int 		i;

	info->ambient = &amb;
	if (if_char(info, str[1], ' ')
		return ;
	str_arr = ft_split(str + 1, ' ');
	if (if_str_arr(info, str_arr))
		return ;
	amb.ratio = ft_atof(info, str_arr[0]);
	amb.rgb = fill_rgb(info, str.arr[1]);
}

void	fill_camera(ray_t	*info, char	*str)
{
	camera_t	cam;
	char		**str_arr;
	int			i;

	info->camera = &cam;
	if (if_char(info, str[1], ' ')
		return ;
	str_arr = ft_split(str + 1, ' ');
	if (if_str_arr(info, str_arr))
		return ;
	if (!fill_coord(str_arr[0], &cam.x, &cam.y, &cam.z))
	{
		if (!fill_vector(str_arr[1], &cam.v_x, &cam.v_y, &cam.v_z))
		{
			if (!fill_fov(str_arr[2], &cam.fov))
				return ;
		}
	}
	info->info_error = 4;
}

void	fill_light(ray_t	*info, char	*str)
{
	light_t		lig;
	char		**str_arr;
	int			i;

	info->light = &lig;
	if (if_char(info, str[1], ' ')
		return ;
	str_arr = ft_split(str + 1, ' ');
	if (if_str_arr(info, str_arr))
		return ;
	if (!fill_coord(str_arr[0], &lig.x, &lig.y, &lig.z))
	{
		lig.ratio = ft_atof(info, str_arr[1]);
		return ;
	}
	info->info_error = 4;
}

void	fill_sphere(ray_t	*info, char	*str)
{
	sphere_t	sph;
	char		**str_arr;
	int			i;

	if (info->spheres == NULL)
		info->spheres = &sph;
	else
		info->spheres->next = &sph;
	if (if_char(info, str[2], ' ')
		return ;
	str_arr = ft_split(str + 2, ' ');
	if (if_str_arr(info, str_arr))
		return ;
	if (!fill_coord(str_arr[0], &sph.x, &sph.y, &sph.z))
	{
		sph.diameter = ft_atof(info, str_arr[1]);
		sph.rgb = fill_rgb(info, str_arr[2]);
		return ;
	}
	info->info_error = 4;
}

void	fill_plane(ray_t	*info, char	*str)
{
	plane_t		pln;
	char		**str_arr;
	int			i;

	if (info->planes == NULL)
		info->planes = &pln;
	else
		info->planes->next = &pln;
	if (if_char(info, str[2], ' ')
		return ;
	str_arr = ft_split(str + 2, ' ');
	if (if_str_arr(info, str_arr))
		return ;
	if (!fill_coord(str_arr[0], &pln.x, &pln.y, &pln.z))
	{
		if (!fill_vector(str_arr[1], &pln.v_x, &pln.v_y, &pln.v_z))
		{
			pln.rgb = fill_rgb(info, str_arr[1]);
			return ;
		}
	}
	info->info_error = 4;
}
