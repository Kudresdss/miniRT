/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:39:03 by ymirna            #+#    #+#             */
/*   Updated: 2022/09/20 22:06:26 by ymirna           ###   ########.fr       */
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
		return (ret);
	return (0);
}
