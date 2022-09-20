/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:59:58 by ymirna            #+#    #+#             */
/*   Updated: 2022/09/20 21:23:03 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/mini_rt.h"

int	ft_strlen(char	*s)
{
	int	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

int	ft_strncmp(char	*s1, char	*s2, int start, int n)
{
	int				i;
	int				y;
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
