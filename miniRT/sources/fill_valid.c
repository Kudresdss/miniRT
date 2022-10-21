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

#include "minirt.h"

float	ft_atof(char	*str)
{
	float	val;
	float	power;
	int		sign;
	int		i;

	sign = 1;
	i = 0;
	if (str[i] == '-')
		sign = -1;
	val = 0.0;
	while (ft_isdigit(str[i]))
	{
		val = 10.0 * val + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	power = 1.0;
	while (ft_isdigit(str[i]))
	{
		val = 10.0 * val + (str[i] - '0');
		power = 10 * power;
	}
	return (sign * val / power);
}

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
