/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:29:40 by cbridget          #+#    #+#             */
/*   Updated: 2022/10/24 16:35:46 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
		if (ret == 4 || ret == 5)
			printf("Incorrect info\n");
		else if (ret == 6)
			printf("Malloc system call error\n");
		return (ret);
	}
	return (0);
}

int	main_loop(t_minirt	*data)
{
	init_rt(data);
	config_cam(data, 1);
	ray_tracing(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->mlx.img, 0, 0);
	mlx_key_hook(data->mlx.mlx_win, select_keycode, data);
	mlx_hook(data->mlx.mlx_win, 17, 0L, ft_close, data);
	mlx_loop(data->mlx.mlx);
	return (0);
}
