/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer_basic_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:03:56 by ymirna            #+#    #+#             */
/*   Updated: 2022/10/10 19:33:05 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	if_char(t_minirt	*info, char	a, char b)
{
	if (a != b)
	{
		info->info_error = 4;
		return (1);
	}
	return (0);
}

int	if_str_arr(t_minirt	*info, char	**arr)
{
	if (!arr)
	{
		info->info_error = 5;
		return (1);
	}
	info->str_arr = arr;
	return (0);
}

int	ft_strn_ncmp(char	*s1, char	*s2, size_t start, size_t n)
{
	size_t			i;
	size_t			y;
	unsigned char	*ss1;
	unsigned char	*ss2;

	i = start;
	y = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (i < n && (ss1[i] || ss2[y]))
	{
		if (ss1[i] == s2[y])
		{
			i++;
			y++;
		}
		else
			return (ss1[i] - ss2[y]);
	}
	return (0);
}
