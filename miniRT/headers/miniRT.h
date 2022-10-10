/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:27:12 by cbridget          #+#    #+#             */
/*   Updated: 2022/10/10 20:49:10 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define HIGHT 500
# define WIDTH 500
# define ESC 65307

# define SPHERE 101
# define PLANE 102
# define CYLINDER 103

# include "../libft/libft.h"
# include "../headers/get_next_line.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct	s_mlx
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_mlx;

typedef struct	s_coordinates
{
	float	x;
	float	y;
	float	z;
}				t_coordinates;


typedef struct	s_sphere
{
	t_coordinates	center;
	float			radius;
	unsigned int	color;
}				t_sphere;

typedef struct	s_plane
{
	t_coordinates	center;
	t_coordinates	normal;
	unsigned int	color;
}				t_plane;


typedef struct	s_scene
{
	float		viewport_hight;
	float		viewport_width;
	float		projection_plane_d;
	t_list		*spheres;
	t_list		*planes;
}				t_scene;

typedef struct	s_camera
{
	t_coordinates	coord;
	t_coordinates	normal;
	float			fov;
}				t_camera;

typedef struct	s_light_point
{
	t_coordinates	coord;
	float			intensity;
}				t_light_point;

typedef struct	s_light_ambient
{
	float			intensity;
	unsigned int	color;
}				t_light_ambient;

typedef struct	s_answer
{
	float		t1;
	float		t2;
	float		closest_t;
	t_list		*closest_shape;
	char		flag;
}				t_answer;

typedef struct	s_minirt
{
	t_mlx			mlx;
	t_scene			scene;
	t_camera		camera;
	t_light_point	light_p;
	// t_list			*light_p; - бонус
	t_light_ambient	light_a;
	t_answer		asw;//it contains the return value from the intersection functions.
	
	char			**str_arr;//результ сплита
	int				info_error;//проверка ошибок в файле сцены
}				t_minirt;

void			init_rt(t_minirt *data);

int				check_scene(t_minirt	*info, char	*scene);
int				ft_strn_ncmp(char	*s1, char	*s2, size_t start, size_t n);
int				if_char(t_minirt	*info, char	a, char b);
int				if_str_arr(t_minirt	*info, char	**arr);
void			fill_ambient(t_minirt	*info, char	*str);
void			fill_camera(t_minirt	*info, char	*str);
void			fill_light(t_minirt	*info, char	*str);
void			fill_sphere(t_minirt	*info, char	*str);
void			fill_plane(t_minirt	*info, char	*str);
void			fill_cylinder(t_minirt	*info, char	*str);

t_coordinates	vectorSubtraction(t_coordinates *a, t_coordinates *b);
t_coordinates	vectorAddition(t_coordinates *a, t_coordinates *b);
t_coordinates	multiplicationScalar(t_coordinates *x, float s);
float			dotVectors(t_coordinates *a, t_coordinates *b);
float			vectorLength(t_coordinates *x);
t_coordinates	vectorNarmolization(t_coordinates *x);


unsigned int	traceRay(t_minirt *data, t_coordinates *ray);
void			closestIntersection(t_minirt *data, t_coordinates *v1, t_coordinates *v2, float t_min);
void			rayTracing(t_minirt *data);
float			computeLighting(t_minirt *data, t_coordinates *pl, t_coordinates *norm);
void			canvasToViewport(t_minirt *data, t_coordinates *vp, float x, float y);
void			intersectRaySphere(t_coordinates *c, t_coordinates *ray, t_sphere *sphere, t_answer *asw);
void			closest_sphere(t_minirt *data, t_coordinates *v1, t_coordinates *v2, float t_min);
void			intersect_ray_plane(t_coordinates *c, t_coordinates *ray, t_plane *plane, t_answer *asw);
void			closest_plane(t_minirt *data, t_coordinates *v1, t_coordinates *v2, float t_min);
void			my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
unsigned int	create_trgb(unsigned char r, unsigned char g, unsigned char b);
unsigned int	multiplicationColorByConstant(unsigned int color, float c);
float			checkCanal(float canal);
int				select_keycode(int keycode, t_minirt *data);
int				ft_close(t_minirt *data);
void			del(void *d);

# endif
