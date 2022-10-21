/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 07:56:13 by ymirna            #+#    #+#             */
/*   Updated: 2022/10/21 06:53:18 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	correct_chars(char	*arr, int x)
{
	int i;

	i = 0;
	while (arr[i])
	{
		if (x == 0)
		{
			if (!ft_isdigit(arr[i]) && is_char(arr[i], '.') && is_char(arr[i], ',') && is_char(arr[i], '-'))
				return (1);
		}
		else if (x == 1)
		{
			if (!ft_isdigit(arr[i]) && is_char(arr[i], '.'))
				return (1);
		}
		else if (x == 2)
		{
			if (!ft_isdigit(arr[i]) && is_char(arr[i], ','))
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_info_x(char	**arr, int x)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	if ((i == 1 && (x == 0 || x == 2)) || (i == 2 && (x == 1 || x == 3 || x == 4)) || (i == 4 && x == 5))
	{
		i = 0;
		while (arr[i])
		{
			if (correct_chars(arr[i], 0))
				return (4);
			i++;
		}
		return (0);
	}
	return (4);
}
