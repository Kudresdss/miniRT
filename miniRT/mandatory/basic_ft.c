/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:59:58 by ymirna            #+#    #+#             */
/*   Updated: 2022/09/26 01:00:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/mini_rt.h"

int	if_char(ray_t	*info, char	a, char b)
{
	if (a != b)
	{
		info->info_error = 4;
		return (1);
	}
	return (0);
}

int	if_str_arr(ray_t	*info, char	**arr)
{
	if (!arr)
	{
		info->info_error = 5;
		return (1);
	}
	info->str_arr = arr;
	return (0);
}

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

char	*ft_substr(char const *s, unsigned int start, size_t	len)
{
	char	*str;
	size_t	i;
	size_t	lens;

	i = 0;
	if (!s)
		return (NULL);
	lens = ft_strlen_g(s);
	if (len > lens)
		len = lens;
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		if (start >= lens)
			break ;
		str[i++] = s[start++];
	}
	str[i] = '\0';
	return (str);
}
