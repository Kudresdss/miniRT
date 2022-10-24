/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 21:24:27 by ymirna            #+#    #+#             */
/*   Updated: 2022/10/24 02:51:06 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_str_arr(char	**arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

// void	delete_content(void	*cont)
// {
// 	free(cont);
// }

// void	free_info(t_minirt	*info)
// {
// 	ft_lstclear(&info->light_p, free);
// 	ft_lstclear(&info->scene.spheres, free);
// 	ft_lstclear(&info->scene.planes, free);
// 	ft_lstclear(&info->scene.cylinders, free);
// }
