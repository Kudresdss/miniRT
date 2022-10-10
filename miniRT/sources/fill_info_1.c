/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_info_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 23:29:19 by ymirna            #+#    #+#             */
/*   Updated: 2022/10/10 22:34:17 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

//ВО ВСЕХ ФУНКЦИЯХ ЗАПОЛНЕНИЯ ЧЕКАТЬ КОРРЕКТНОСТЬ СТРОКИ, ПОДАВАТЬ ВСЮДУ
//INFO_ERROR ДЛЯ ПРОВЕРКИ В РОДИТЕЛЬСКОЙ ФУНКЦИИ

//ВО ВСЕХ ФУНКЦИЯХ ПРОВЕРЯТЬ НАЛИЧИЕ КОРРЕКТНЫХ ДАННЫХ, В ТОМ ЧИСЛЕ В ФУНКЦИЯХ НЕ ПО ИФУ

void	fill_ambient(t_minirt	*info, char	*str)
{
	char		**str_arr;
	int 		i;

	if (if_char(info, str[1], ' '))
		return ;
	str_arr = ft_split(str + 1, ' ');
	if (if_str_arr(info, str_arr))
		return ;
	info->light_a.intensity = ft_atof(info, str_arr[0]);
	info->light_a.color = fill_rgb(info, str_arr[1]);
}

void	fill_camera(t_minirt	*info, char	*str)
{
	char		**str_arr;
	int			i;

	if (if_char(info, str[1], ' '))
		return ;
	str_arr = ft_split(str + 1, ' ');
	if (if_str_arr(info, str_arr))
		return ;
	if (!fill_coord(str_arr[0], info->camera.coord))
	{
		if (!fill_vector(str_arr[1], info->camera.normal))
		{
			if (!fill_fov(str_arr[2], info->camera.fov))
				return ;
		}
	}
	info->info_error = 4;
}

void	fill_light(t_minirt	*info, char	*str)
{
	char		**str_arr;
	int			i;

	//РЕАЛИЗОВАТЬ ЗАПОЛНЕНИЕ СПИСКА - в бонусе
	if (if_char(info, str[1], ' '))
		return ;
	str_arr = ft_split(str + 1, ' ');
	if (if_str_arr(info, str_arr))
		return ;
	if (!fill_coord(str_arr[0], info->light_p.coord))
	{
		info->light_p.intensity = ft_atof(info, str_arr[1]);
		return ;
	}
	info->info_error = 4;
}

void	fill_sphere(t_minirt	*info, char	*str)
{
	sphere_t	sph;
	char		**str_arr;
	int			i;

	//РЕАЛИЗОВАТЬ ЗАПОЛНЕНИЕ СПИСКА
	if (info->spheres == NULL)
		info->spheres = &sph;
	else
		info->spheres->next = &sph;
	if (if_char(info, str[2], ' '))
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

void	fill_plane(t_minirt	*info, char	*str)
{
	plane_t		pln;
	char		**str_arr;
	int			i;

	//РЕАЛИЗОВАТЬ ЗАПОЛНЕНИЕ СПИСКА
	if (info->planes == NULL)
		info->planes = &pln;
	else
		info->planes->next = &pln;
	if (if_char(info, str[2], ' '))
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
