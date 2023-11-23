/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:25:10 by nahyulee          #+#    #+#             */
/*   Updated: 2023/11/22 20:10:24 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "minilibx_opengl_20191021/mlx.h"
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

typedef struct s_t_vtr3d
{
	float	x;
	float	y;
	float	z;
}	t_vtr3;

typedef struct s_2d
{
	int	x;
	int	y;
}	t_2d;

typedef struct s_ray
{
	t_vtr3	origin;
	t_vtr3	direction;
} t_ray;

typedef struct s_ambentlight
{
	float	ratio;
	int		color;
}	t_a;

typedef struct s_camera
{
	t_vtr3	cam;
	t_vtr3	dir;
	t_2d	pos;
	int		fov;
}	t_cam;

typedef struct s_light
{
	t_vtr3	position;
	float	brightness;
	int		color;
}	t_l;

typedef struct s_sphere
{
	t_vtr3	center;
	float	radius;
	int		color;
}	t_sp;

typedef struct s_plane
{
	t_vtr3	position;
	t_vtr3	orientation;
	int		color;
}	t_p;

typedef struct s_square
{
	t_vtr3	center;
	t_vtr3	orientation;
	float	side;
	int		color;
}	t_sq;

typedef struct s_cylinder
{
	t_vtr3	position;
	t_vtr3	orientation;
	float	diameter;
	float	height;
	int		color;
}	t_cy;

typedef struct s_triangle
{
	t_vtr3	vertex1;
	t_vtr3	vertex2;
	t_vtr3	vertex3;
	int		color;
}	t_tr;

typedef struct s_data
{
	t_a		ambient;
	t_cam	camera;
	t_l		light;
	t_sp	sphere;
	t_p		plane;
	t_sq	square;
	t_cy	cylinder;
	t_tr	triangle;
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
t_rt	*make_array(void);
void	read_data(t_rt *d, char **av);
unsigned int	rgb_hex(int red, int green, int blue);
/* ***********************vector********************************************* */
t_2d	project3dto2d(t_rt *rt, t_vtr3 point3d, t_2d point2d);
t_vtr3	add_vector(t_vtr3 a, t_vtr3 b);
t_vtr3	subtract_vector(t_vtr3 a, t_vtr3 b);
t_vtr3	multiply_vector(t_vtr3 v, float scalar);
t_vtr3	divide_vector(t_vtr3 v, float scalar);
/* ***********************math********************************************** */

/* ***********************camera********************************************* */
void	move_camera(t_cam camera, int x, int y, int z);
/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

#endif