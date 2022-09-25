/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:39:03 by ymirna            #+#    #+#             */
/*   Updated: 2022/09/25 20:49:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/mini_rt.h"

int	main(int ac, char	**av)
{
	ray_t	info;
	int		ret;

	if (ac != 2)
	{
		printf("Invalid number of arguments\n");
		return (1);
	}
	ret = check_scene(&info, av[1]);
	if (ret)
	{
		if (ret = 4)
			printf("Invalid info\n");
		if (ret = 5)
			printf("Malloc system call error\n");
		return (ret);
	}
	//main_loop(info);
	return (0);
}
