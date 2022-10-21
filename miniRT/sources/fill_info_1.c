/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_info_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 23:29:19 by ymirna            #+#    #+#             */
/*   Updated: 2022/10/21 07:05:24 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	fill_ambient(t_minirt	*info, char	*str)
{
	char		**str_arr;

	info->check.l_a++;
	if (if_char(info, str[1], ' '))
		return ;
	str_arr = ft_split(str + 1, ' ');
	info->info_error = if_str_arr(info, str_arr, 0);
	if (info->info_error)
		return ;
	info->light_a.intensity = fill_float(info, str_arr[0], 1);
	info->light_a.color = fill_rgb(info, str_arr[1]);
}

void	fill_camera(t_minirt	*info, char	*str)
{
	char		**str_arr;

	info->check.cam++;
	if (if_char(info, str[1], ' '))
		return ;
	str_arr = ft_split(str + 1, ' ');
	info->info_error = if_str_arr(info, str_arr, 1);
	if (info->info_error)
		return ;
	fill_coord(info, &info->camera.orig, str_arr[0], 0);
	fill_coord(info, &info->camera.normal, str_arr[1], 1);
	info->camera.fov = fill_float(info, str_arr[2], 2);
}

void	fill_light(t_minirt	*info, char	*str)
{
	t_light_point	*l_ptr;
	t_list			*l_p;
	char			**str_arr;

	info->check.l_p++;
	if (if_char(info, str[1], ' '))
		return ;
	str_arr = ft_split(str + 1, ' ');
	info->info_error = if_str_arr(info, str_arr, 2);
	if (info->info_error)
		return ;
	if (init_point(info, &l_p))
		return ;
	while (l_p->next != NULL)
		l_p = l_p->next;
	l_ptr = (t_light_point *)l_p->content;
	fill_coord(info, &l_ptr->coord, str_arr[0], 0);
	l_ptr->intensity = fill_float(info, str_arr[1], 1);
}

void	fill_sphere(t_minirt	*info, char	*str)
{
	t_sphere	*sph_ptr;
	t_list		*sph;
	char		**str_arr;

	info->check.sph++;
	if (if_char(info, str[2], ' '))
		return ;
	str_arr = ft_split(str + 2, ' ');
	info->info_error = if_str_arr(info, str_arr, 3);
	if (info->info_error)
		return ;
	if (init_sphere(info, &sph))
		return ;
	while (sph->next != NULL)
		sph = sph->next;
	sph_ptr = (t_sphere *)sph->content;
	fill_coord(info, &sph_ptr->center, str_arr[0], 0);
	sph_ptr->radius = fill_float(info, str_arr[1], 3) / 2;
	sph_ptr->color = fill_rgb(info, str_arr[2]);
}

void	fill_plane(t_minirt	*info, char	*str)
{
	t_plane		*pln_ptr;
	t_list		*pln;
	char		**str_arr;

	info->check.pln++;
	if (if_char(info, str[2], ' '))
		return ;
	str_arr = ft_split(str + 2, ' ');
	info->info_error = if_str_arr(info, str_arr, 4);
	if (info->info_error)
		return ;
	if (init_plane(info, &pln))
		return ;
	while (pln->next != NULL)
		pln = pln->next;
	pln_ptr = (t_plane	*)pln->content;
	fill_coord(info, &pln_ptr->center, str_arr[0], 0);
	fill_coord(info, &pln_ptr->normal, str_arr[1], 1);
	pln_ptr->color = fill_rgb(info, str_arr[1]);
}
