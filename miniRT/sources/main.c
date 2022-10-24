/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:29:40 by cbridget          #+#    #+#             */
/*   Updated: 2022/10/24 05:00:20 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	pseudoParser(t_minirt *data);
int		main_loop(t_minirt	*data);

int	main(int ac, char	**av)
{
	t_minirt	info;
	int			ret;

	if (ac != 2)
	{
		printf("Invalid number of arguments\n");
		return (1);
	}
	ret = check_scene(&info, av[1]);
	if (!ret)
		ret = main_loop(&info);
	if (ret)
	{
		// free_info(&info);
		if (ret == 4 || ret == 5)
			printf("Incorrect info\n");
		else if (ret == 6)
			printf("Malloc system call error\n");
		return (ret);
	}
	// free_info(&info);
	return (0);
}

int	main_loop(t_minirt	*data)
{
	init_rt(data);
	
	// pseudoParser(&data);
	
	config_cam(data, 1);
	ray_tracing(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->mlx.img, 0, 0);
	mlx_key_hook(data->mlx.mlx_win, select_keycode, &data);
	mlx_hook(data->mlx.mlx_win, 17, 0L, ft_close, &data);
	mlx_loop(data->mlx.mlx);
	return (0);
}

// void pseudoParser(t_minirt *data)
// {
	
// 	data->light_a.intensity = 0.2f;
// 	data->light_a.color = create_trgb(255, 255, 255);

// 	t_light_point *light_p = malloc(sizeof(t_light_point) * 1);
// 	light_p->coord.x = 0;
// 	light_p->coord.y = 0.1;
// 	light_p->coord.z = 1;
// 	light_p->intensity = 0.8f;
// light_p->color = create_trgb(255, 0, 255);
// 	data->light_p = ft_lstnew(light_p);
// 	light_p = malloc(sizeof(t_light_point) * 1);
// 	light_p->coord.x = -3;
// 	light_p->coord.y = 7;
// 	light_p->coord.z = 0;
// 	light_p->intensity = 0.7f;
// 	light_p->color = create_trgb(0, 0, 255);
// 	ft_lstadd_back(&data->light_p, ft_lstnew(light_p));

// 	t_sphere *sphere1 = malloc(sizeof(t_sphere) * 1);
// 	sphere1->center.x = 0;
// 	sphere1->center.y = 5;
// 	sphere1->center.z = 7;
// 	sphere1->radius = 2.5;
// 	sphere1->reflect = 0.5;
// 	sphere1->color = create_trgb(255, 0, 0);
// 	data->scene.spheres = ft_lstnew(sphere1);
// 	sphere1 = malloc(sizeof(t_sphere) * 1);
// 	sphere1->center.x = 1.5;
// 	sphere1->center.y = 1;
// 	sphere1->center.z = 3;
// 	sphere1->radius = 1;
// 	sphere1->reflect = 0.3;
// 	sphere1->color = create_trgb(255, 0, 255);
// 	ft_lstadd_back(&(data->scene.spheres), ft_lstnew(sphere1));
// 	sphere1 = malloc(sizeof(t_sphere) * 1);
// 	sphere1->center.x = -2;
// 	sphere1->center.y = 0;
// 	sphere1->center.z = 4;
// 	sphere1->radius = 1;
// 	sphere1->reflect = 1.0;
// 	sphere1->color = create_trgb(255, 255, 255);
// 	ft_lstadd_back(&(data->scene.spheres), ft_lstnew(sphere1));
// 	sphere1 = malloc(sizeof(t_sphere) * 1);
// 	sphere1->center.x = -6;
// 	sphere1->center.y = 6;
// 	sphere1->center.z = 5;
// 	sphere1->radius = 3;
// 	sphere1->reflect = 0.1;
// 	sphere1->color = create_trgb(255, 255, 0);
// 	ft_lstadd_back(&(data->scene.spheres), ft_lstnew(sphere1));
// /*	sphere1 = malloc(sizeof(t_sphere) * 1);
// 	sphere1->center.x = 0;
// 	sphere1->center.y = -2501;
// 	sphere1->center.z = 0;
// 	sphere1->radius = 5000;
// 	sphere1->reflect = 0;
// 	sphere1->color = create_trgb(255, 255, 0);
// 	ft_lstadd_back(&(data->scene.spheres), ft_lstnew(sphere1));*/

// 	t_plane *plane = malloc(sizeof(t_plane) * 1);
// 	plane->center.x = 0;
// 	plane->center.y = 0;
// 	plane->center.z = 10;
// 	plane->normal.x = 0;
// 	plane->normal.y = 0;
// 	plane->normal.z = 1;
// 	plane->reflect = 0;
// 	plane->color = create_trgb(255, 255, 255);
// 	data->scene.planes = ft_lstnew(plane);
// 	plane = malloc(sizeof(t_plane) * 1);
// 	plane->center.x = 0;
// 	plane->center.y = -1;
// 	plane->center.z = 0;
// 	plane->normal.x = 0;
// 	plane->normal.y = 1;
// 	plane->normal.z = 0;
// 	plane->reflect = 0;
// 	plane->color = create_trgb(255, 255, 255);
// 	ft_lstadd_back(&data->scene.planes, ft_lstnew(plane));
// /*	plane = malloc(sizeof(t_plane) * 1);
// 	plane->center.x = 0;
// 	plane->center.y = 0;
// 	plane->center.z = -5;
// 	plane->normal.x = 0;
// 	plane->normal.y = 0;
// 	plane->normal.z = -1;
// 	plane->reflect = 1;
// 	plane->color = create_trgb(255, 255, 255);
// 	ft_lstadd_back(&data->scene.planes, ft_lstnew(plane));
// 	plane = malloc(sizeof(t_plane) * 1);
// 	plane->center.x = 0;
// 	plane->center.y = 15;
// 	plane->center.z = 0;
// 	plane->normal.x = 0;
// 	plane->normal.y = 1;
// 	plane->normal.z = 0;
// 	plane->reflect = 1;
// 	plane->color = create_trgb(255, 255, 255);
// 	ft_lstadd_back(&data->scene.planes, ft_lstnew(plane));
// 	plane = malloc(sizeof(t_plane) * 1);
// 	plane->center.x = 10;
// 	plane->center.y = 0;
// 	plane->center.z = 0;
// 	plane->normal.x = 1;
// 	plane->normal.y = 0;
// 	plane->normal.z = 0;
// 	plane->reflect = 1;
// 	plane->color = create_trgb(255, 255, 255);
// 	ft_lstadd_back(&data->scene.planes, ft_lstnew(plane));
// 	plane = malloc(sizeof(t_plane) * 1);
// 	plane->center.x = -10;
// 	plane->center.y = 0;
// 	plane->center.z = 0;
// 	plane->normal.x = 1;
// 	plane->normal.y = 0;
// 	plane->normal.z = 0;
// 	plane->reflect = 1;
// 	plane->color = create_trgb(255, 255, 255);
// 	ft_lstadd_back(&data->scene.planes, ft_lstnew(plane));*/

// 	t_cylinder *cylinder = malloc(sizeof(t_cylinder) * 1);
// 	cylinder->center.x = -5;
// 	cylinder->center.y = 5;
// 	cylinder->center.z = 2;
// 	cylinder->normal.x = 0;
// 	cylinder->normal.y = -1;
// 	cylinder->normal.z = 0;
// 	cylinder->height = 4;
// 	cylinder->radius = 1;
// 	cylinder->reflect = 0.1;
// 	cylinder->color = create_trgb(255, 228, 196);
// 	data->scene.cylinders = ft_lstnew(cylinder);

// 	data->camera.orig.x = -1;
// 	data->camera.orig.y = 1.5;
// 	data->camera.orig.z = -5;
// 	data->camera.normal.x = 0;
// 	data->camera.normal.y = -0.1;
// 	data->camera.normal.z = 1;
// 	data->camera.fov = 120.0f;
// }
