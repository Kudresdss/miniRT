/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:44:19 by ymirna            #+#    #+#             */
/*   Updated: 2022/09/26 01:19:14 by marvin           ###   ########.fr       */
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

typedef struct	ambient_s
{
	float	ratio;
	int		rgb[3];
}	ambient_t;

typedef struct	camera_s
{
	float	x;
	float	y;
	float	z;
	float	v_x;
	float	v_y;
	float	v_z;
	int		fov;
}	camera_t;

typedef struct	light_s
{
	float	x;
	float	y;
	float	z;
	float	ratio;
	// int		rgb[3];
}	light_t;

typedef struct sphere_s
{
	float			x;
	float			y;
	float			z;
	float			diameter;
	int				rgb[3];
	struct sphere_s	*next;
}	sphere_t;

typedef struct plane_s
{
	float			x;
	float			y;
	float			z;
	float			v_x;
	float			v_y;
	float			v_z;
	int				rgb[3];
	struct plane_s	*next;
}	plane_t;

typedef struct cylinder_s
{
	float				x;
	float				y;
	float				z;
	float				v_x;
	float				v_y;
	float				v_z;
	float				diameter;
	float				height;
	int					rgb[3];
	struct cylinder_s	*next;
}	cylinder_t;


typedef struct	ray_s
{
	char				**str_arr;
	int					info_error;
	struct ambient_s	*ambient;
	struct camera_s		*camera;
	struct light_s		*light;
	struct sphere_s		*spheres;
	struct plane_s		*planes;
	struct cylinder_s	*cylinders;
}	ray_t;


int		check_scene(ray_t	*info, char	*scene);
void	fill_ambient(ray_t	*info, char	*str);
void	fill_camera(ray_t	*info, char	*str);
void	fill_light(ray_t	*info, char	*str);
void	fill_sphere(ray_t	*info, char	*str);
void	fill_plane(ray_t	*info, char	*str);
void	fill_cylinder(ray_t	*info, char	*str);
int		coord_valid(char	*str);
void	free_info(ray_t	*info);
int		ft_strlen(char	*s);
int		if_char(ray_t	*info, char	a, char b);
int		if_str_arr(ray_t	*info, char	**arr);
int		ft_strncmp(char	*s1, char	*s2, int start, int n);

#endif