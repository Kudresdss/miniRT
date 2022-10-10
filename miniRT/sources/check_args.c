/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:53:56 by ymirna            #+#    #+#             */
/*   Updated: 2022/10/10 20:12:41 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	check_info(t_minirt	*info, char	*str)
{
	if (ft_strlen(str) == 1 && str[0] == '\n')
		return (0);
	if (str[0] == "A")
		fill_ambient(info, str);
	else if (str[0] == "C" && !info->info_error)
		fill_camera(info, str);
	else if (str[0] == "L" && !info->info_error)
		fill_light(info, str);
	else if (str[0] == "s" && str[1] == "p" && !info->info_error)
		fill_sphere(info, str);
	else if (str[0] == "p" && str[1] == "l" && !info->info_error)
		fill_plane(info, str);
	else if (str[0] == "c" && str[1] == "y" && !info->info_error)
		fill_cylinder(info, str);
	else
		return (4);
	return (info->info_error);
}

static int	read_info(t_minirt	*info, int fd)
{
	char	*str;
	int		ret;

	str = NULL;
	while (1)
	{
		ret = get_next_line(str, fd);
		if (ret)
			return (ret);
		if (!str)
			break ;
		ret = check_info(info, str);
		free(str);
		if (info->str_arr)
			free_str_arr(info->str_arr);
		if (ret)
		{
			free_info(info);
			return (ret);
		}
		info->info_error = 0;
	}
	return (0);
}



// static void	null_init(ray_t	*info)
// {
// 	info->ambient = NULL;
// 	info->camera = NULL;
// 	info->light = NULL;
// 	info->spheres = NULL;
// 	info->planes = NULL;
// 	info->cylinders = NULL;
// }

int	check_scene(t_minirt	*info, char	*scene)
{
	int ret;
	int	fd;

	if (ft_strn_ncmp(scene, ".rt", ft_strlen(scene) - 3, ft_strlen(scene)))
	{
		printf("Invalid argument:\nwrong filename extension\n");
		return (2);
	}
	fd = open(scene, O_RDONLY);
	if (fd < 0)
	{
		printf("Failed to open file\n");
		return (3);
	}
	// null_init(info);
	ret = read_info(info, fd);
	// ЗАГНАТЬ ПРОВЕРКУ НАЛИЧИЯ МИНИМУМА НЕОБХОДИМЫХ ЭЛЕМЕНТОВ
	return (ret);
}