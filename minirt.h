/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:25:10 by nahyulee          #+#    #+#             */
/*   Updated: 2023/11/25 21:36:29 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

// # include "minilibx_opengl_20191021/mlx.h"
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>

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
}	t_cam;

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
}	t_pl;

typedef struct s_sphere
{
	t_vtr3			center;
	float			radius;
	unsigned int	color;
}	t_sp;

typedef struct s_cylinder
{
	t_vtr3			position;
	t_vtr3			orientation;
	float			diameter;
	float			height;
	unsigned int	color;
}	t_cy;

typedef struct s_data
{
	t_a		ambient;
	t_cam	camera;
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

/* ***********************file_read****************************************** */
void			read_data(t_rt *d, char **av);
unsigned int	rgb_hex(int red, int green, int blue);
/* ***********************vector********************************************* */
float			dot_product(t_vtr3 a, t_vtr3 b);
t_vtr3			cross_product(t_vtr3 a, t_vtr3 b);
t_vtr3			add_vector(t_vtr3 a, t_vtr3 b);
t_vtr3			subtract_vector(t_vtr3 a, t_vtr3 b);
t_vtr3			multiply_vector(t_vtr3 v, float scalar);
t_vtr3			divide_vector(t_vtr3 v, float scalar);
/* ***********************util********************************************** */
int				press_key(int key_val, t_rt *rt);
int				print_error(int key_val, t_rt *rt);
/* ***********************camera********************************************* */
void			move_camera(t_cam camera, int x, int y, int z);
/* ***********************draw*********************************************** */
t_vtr2			project3dto2d(t_rt *rt, t_vtr3 point3d);
void			drawsphere(t_rt *rt, t_sp sphere);
/* ************************************************************************** */
/* ************************************************************************** */

#endif