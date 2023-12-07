/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:25:10 by nahyulee          #+#    #+#             */
/*   Updated: 2023/12/07 19:31:01 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

// # include "mlx/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>

# include "example/minilibx-linux/mlx.h"
# include <stdio.h>

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_EXIT		17
# define KEY_ESC				53

# define KEY_W					13
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2
# define KEY_UP					126

# define KEY_LEFT				123
# define KEY_DOWN				125
# define KEY_RIGHT				124

# ifndef M_PI
#  define M_PI	3.14159265358979323846
# endif

typedef struct s_vector3d
{
	float	x;
	float	y;
	float	z;
}	t_vtr3;

typedef struct s_vector2d
{
	int	x;
	int	y;
}	t_vtr2;

typedef struct s_uvw
{
	t_vtr3	u;
	t_vtr3	v;
	t_vtr3	w;
}	t_uvw;

typedef struct s_ray
{
	t_vtr3	origin;
	t_vtr3	dir;
}	t_ray;

typedef struct s_viewplane
{
	double	half_width;
	double	half_height;
}	t_vwpl;

typedef struct s_ambentlight
{
	float			ratio;
	unsigned int	color;
}	t_a;

typedef struct s_camera
{
	t_vtr3	cam;
	t_vtr3	dir;
	int		fov;
	t_uvw	uvw;
	int		color;
	t_ray	ray;
	t_vwpl	viewplane;
	double	t;
}	t_c;

typedef struct s_light
{
	t_vtr3			position;
	float			brightness;
	unsigned int	color;
}	t_l;

typedef struct s_plane
{
	t_vtr3			position;
	t_vtr3			orientation;
	unsigned int	color;
	double			t;
	int				normal;
	t_vtr3			hit_point;
}	t_pl;

typedef struct s_sphere
{
	t_vtr3			center;
	float			radius;
	unsigned int	color;
	double			t;
	int				normal;
	t_vtr3			hit_point;
}	t_sp;

typedef struct s_cylinder
{
	t_vtr3			position;
	t_vtr3			orientation;
	float			diameter;
	float			height;
	unsigned int	color;
	double			t;
	int				normal;
	t_vtr3			hit_point;
}	t_cy;

typedef struct s_data
{
	t_a		ambient;
	t_c		camera;
	t_l		light;
	t_pl	plane;
	t_sp	sphere;
	t_cy	cylinder;
}	t_d;

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	int		width;
	int		height;
	t_d		data;
}	t_rt;


/* ***********************draw*********************************************** */
void			draw(t_rt *rt);
void			drawsphere(t_rt *rt, t_sp sphere);
void			drawplane(t_rt *rt, t_pl plane);
void			drawcylinder(t_rt *rt, t_cy cylinder);
/* ***********************check_data_condition******************************* */
void			check_data_condition(t_rt *rt, char *tmp);
void			put_r(t_rt *rt, char *tmp);
void			put_a(t_rt *rt, char *tmp);
/* ***********************extension***************************************** */
void			part_of_parse_extens(char **av, int **i);
void			parse_extens(char **av, int *i);
/* ***********************open_scene_file************************************ */
unsigned int	rgb_hex(int red, int green, int blue);
void			sphere(t_rt *rt);
void			open_scene_file(t_rt *rt, char **av, int *i);
/* ***********************camera******************************************** */
void			cam_lookat(t_rt *rt);
void			viewplane(t_rt *rt);
void			raycast(t_rt *rt);
// void			find_normal(t_rt *rt);
void			my_mlx_pixel_put(t_rt *rt, int x, int y, int color);
/* ***********************intersect***************************************** */
void			intersect(t_rt *rt);
void			intersect_sphere(t_rt *rt);
void			intersect_plane(t_rt *rt);
void			intersect_cylinder(t_rt *rt);
void			find_min_hit_intersection(t_rt *rt);
/* ***********************util********************************************** */
void			move_camera(t_c camera, int x, int y, int z);
int				press_key(int key_val, t_rt *rt);
int				print_error(int key_val, t_rt *rt);
/* ***********************vector********************************************* */
float			dot_product(t_vtr3 a, t_vtr3 b);
t_vtr3			cross_product(t_vtr3 a, t_vtr3 b);
t_vtr3			add_vector(t_vtr3 a, t_vtr3 b);
t_vtr3			subtract_vector(t_vtr3 a, t_vtr3 b);
t_vtr3			vtr3_length(t_vtr3 v);
/* ***********************vector_scalar************************************* */
t_vtr3			normalize_vector(t_vtr3 v);
t_vtr3			add_val_vtr3(t_vtr3 v, float x, float y, float z);
t_vtr3			multiply_vector(t_vtr3 v, float x, float y, float z);
t_vtr3			divide_vector(t_vtr3 v, float x, float y, float z);
/* ************************************************************************** */
#endif