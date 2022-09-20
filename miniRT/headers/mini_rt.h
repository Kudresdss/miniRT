/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:44:19 by ymirna            #+#    #+#             */
/*   Updated: 2022/09/20 23:45:50 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct	ray_s
{
	int	info_error;
}	ray_t;


int		check_scene(ray_t	*info, char	*scene);
void	fill_ambient(ray_t	*info, char	*str);
void	fill_camera(ray_t	*info, char	*str);
void	fill_light(ray_t	*info, char	*str);
void	fill_sphere(ray_t	*info, char	*str);
void	fill_plane(ray_t	*info, char	*str);
void	fill_cylinder(ray_t	*info, char	*str);
void	free_info(ray_t	*info);
int		ft_strlen(char	*s);
int		ft_strncmp(char	*s1, char	*s2, int start, int n);

#endif