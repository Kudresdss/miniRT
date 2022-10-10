/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 08:21:54 by ymirna            #+#    #+#             */
/*   Updated: 2022/09/20 22:35:24 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/mini_rt.h"

int	coord_valid(char	*str)
{
	int i;
	int	y;

	i = 0;
	y = 0;
	while (str[i])
	{
		if (!(('0' <= str[i] && str[i] <= '9') || str[i] == '.' || str[i] == ','))
			return (1);
		if (str[i] == ',')
			y++;
		i++;
	}
	if (y != 3)
		return (1);
	return (0);
}
