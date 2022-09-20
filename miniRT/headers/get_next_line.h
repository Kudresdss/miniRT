/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 08:22:56 by ymirna            #+#    #+#             */
/*   Updated: 2022/09/20 22:34:19 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_gnl
{
	int		line;
	int		fd;
	char	*str;
	size_t	chr;
	size_t	i;
}	t_gnl;
int		get_next_line(char	*ret, int	fd);
size_t	ft_strlen_g(const char	*s);
char	*ft_sub(char *s, unsigned int start, size_t	len, int	x);
char	*ft_join(char *s1, char *s2, int	x);

#endif