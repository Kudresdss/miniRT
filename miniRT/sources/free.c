/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 21:24:27 by ymirna            #+#    #+#             */
/*   Updated: 2022/10/19 00:38:42 by ymirna           ###   ########.fr       */
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

// void	free_info(t_minirt	*info)
// {
// 	// free(info->light_p);
// 	// free(info->scene.planes);
// 	// free(info->scene.spheres);
// }
