/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_info_1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 23:29:19 by ymirna            #+#    #+#             */
/*   Updated: 2022/10/24 16:18:07 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	fill_ambient(t_minirt	*info, char	*str)
{
	char		**str_arr;

	if (if_char(info, str[1], ' '))
		return ;
	str_arr = ft_split(str + 1, ' ');
	info->info_error = if_str_arr(info, str_arr, 0);
	if (info->info_error)
		return ;
	info->light_a.intensity = fill_float(info, str_arr[0], 1);
	info->light_a.color = fill_rgb(info, str_arr[1]);
	info->check.l_a++;
	printf("\n//fill_ambient_bonus, intensity = %f, color = %u\n\n", info->light_a.intensity, info->light_a.color);
}

void	fill_camera(t_minirt	*info, char	*str)
{
	char		**str_arr;

	if (if_char(info, str[1], ' '))
		return ;
	str_arr = ft_split(str + 1, ' ');
	info->info_error = if_str_arr(info, str_arr, 1);
	if (info->info_error)
		return ;
	fill_coord(info, &info->camera.orig, str_arr[0], 0);
	fill_coord(info, &info->camera.normal, str_arr[1], 1);
	info->camera.fov = fill_float(info, str_arr[2], 2);
	info->check.cam++;
	printf("\n//fill_camera_bonus, coords = %f|%f|%f, vector = %f|%f|%f, fov = %f\n\n", info->camera.orig.x, info->camera.orig.y,
		info->camera.orig.z, info->camera.normal.x, info->camera.normal.y, info->camera.normal.z, info->camera.fov);
}

void	fill_light(t_minirt	*info, char	*str)
{
	t_light_point	*l_ptr;
	t_list			*l_p;
	char			**str_arr;

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
	l_ptr->color = fill_rgb(info, str_arr[2]);
	info->check.l_p++;
	printf("\n//fill_light_bonus, coords = %f|%f|%f, intensity = %f, color = %u\n\n", l_ptr->coord.x, l_ptr->coord.y, l_ptr->coord.z, l_ptr->intensity, l_ptr->color);
}

void	fill_sphere(t_minirt	*info, char	*str)
{
	t_sphere	*sph_ptr;
	t_list		*sph;
	char		**str_arr;

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
	sph_ptr->reflect = fill_float(info, str_arr[3], 1);
	info->check.sph++;
	printf("//fill_sphere_bonus, coord = %f|%f|%f, radius = %f, color = %u, reflect = %f\n", sph_ptr->center.x, sph_ptr->center.y, sph_ptr->center.z, sph_ptr->radius, sph_ptr->color, sph_ptr->reflect);
}

void	fill_plane(t_minirt	*info, char	*str)
{
	t_plane		*pln_ptr;
	t_list		*pln;
	char		**str_arr;

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
	pln_ptr->color = fill_rgb(info, str_arr[2]);
	pln_ptr->reflect = fill_float(info, str_arr[3], 1);
	info->check.pln++;
	printf("//fill_plane_bonus, coord = %f|%f|%f, vector = %f|%f|%f, color = %u, reflect = %f\n", pln_ptr->center.x, pln_ptr->center.y, pln_ptr->center.z, pln_ptr->normal.x, pln_ptr->normal.y, pln_ptr->normal.z, pln_ptr->color, pln_ptr->reflect);
}
