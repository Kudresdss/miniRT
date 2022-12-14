/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:13:54 by cbridget          #+#    #+#             */
/*   Updated: 2022/10/24 13:38:24 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	err;

	err = 0;
	if (s)
	{
		while (*s)
		{
			err = write(fd, s, 1);
			s++;
		}
	}
	if (err == -1)
		(void)err;
}
