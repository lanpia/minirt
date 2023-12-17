/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohkang <soohkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:25:10 by nahyulee          #+#    #+#             */
/*   Updated: 2023/12/18 05:18:47 by soohkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

// # include "minilibx_opengl_20191021/mlx.h"
# include "mlx/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>

/**** **** **** DELETE after submitted ~!~!~!~!~!!!!!!!!!!!! **** **** ****/
#include <stdio.h>

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

// 3차원 벡터
typedef struct s_vector3d
{
	float	x;
	float	y;
	float	z;
}	t_vtr3;

// 2차원 벡터
typedef struct s_vector2d
{
	int	x;
	int	y;
}	t_vtr2;

// 환경광
typedef struct s_ambentlight
{
	float			ratio; // 0.0 완전한 어둠, 1.0 최대 밝기
	unsigned int	color; //rgb
}	t_a;

typedef struct s_ray
{
	t_vtr3	origin;		// 광선의 원점
	t_vtr3	direction;	// 광선의 방향
}	t_ray;

typedef struct s_color
{
	float	r; // 빨간색 채널
	float	g; // 녹색 채널
	float	b; // 파란색 채널
}	t_color;

// 카메라
typedef struct s_camera
{
	t_vtr3	cam;
	t_vtr3	dir;
	int		fov;
}	t_c;

// 조명
typedef struct s_light
{
	t_vtr3			position;
	float			brightness;
	unsigned int	color;
}	t_l;

// 평면
typedef struct s_plane
{
	t_vtr3			position;
	t_vtr3			orientation;
	unsigned int	color;
}	t_pl;

// 구
typedef struct s_sphere
{
	t_vtr3			center;
	float			radius;
	unsigned int	color;
}	t_sp;

// 원통
typedef struct s_cylinder
{
	t_vtr3			position;
	t_vtr3			orientation;
	float			diameter;
	float			height;
	unsigned int	color;
}	t_cy;

// 장면 데이터
typedef struct s_data
{
	t_a		ambient;
	t_c		camera;
	t_l		light;
	t_pl	plane;
	t_sp	sphere;
	t_cy	cylinder;
}	t_d;

// miniRT 메인 구조체
typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	int		width; // viewport width
	int		height; // viewport height
	t_d		data;
}	t_rt;


/* ***************		_parse		************************************ */
void			parse_extensions(char **av, int *i);
void			part_of_parse_extens(char **av, int **i);
void			open_scene_file(t_rt *d, char **av, int *i);
void			check_data_condition(t_rt *rt, char *tmp);
void			put_r(t_rt *rt, char *tmp);
void			put_a(t_rt *rt, char *tmp);
void			put_c(t_rt *rt, char *tmp);
void			put_l(t_rt *rt, char *tmp);
void			put_pl(t_rt *rt, char *tmp);
void			put_sp(t_rt *rt, char *tmp);
void			put_cy(t_rt *rt, char *tmp);
// unsigned int	rgb_hex(int red, int green, int blue);

/* ***************		_vector		************************************* */
float			dot_product(t_vtr3 a, t_vtr3 b);
t_vtr3			cross_product(t_vtr3 a, t_vtr3 b);
t_vtr3			add_vector(t_vtr3 a, t_vtr3 b);
t_vtr3			subtract_vector(t_vtr3 a, t_vtr3 b);
t_vtr3			multiply_vector(t_vtr3 v, float scalar);
t_vtr3			divide_vector(t_vtr3 v, float scalar);

/* ***************		_utils		************************************** */
int				press_key(int key_val, t_rt *rt);
int				print_error(int key_val, t_rt *rt);

/* ***************		_raytracing		********************************** */
void			initialize_camera(t_rt *rt);
// void			move_camera(t_c camera, int x, int y, int z);

/* ***************		_render		*************************************** */
void			render_scene(t_rt *rt);
void	trace_ray(t_ray *ray, t_rt *rt);


void			sphere(t_rt *rt, t_sp sphere);
void			render_cylinder(t_rt *rt, t_sp cylinder);
t_vtr2			project3dto2d(t_rt *rt, t_vtr3 point3d);

/* ***************		_math		*************************************** */
float			degree_to_radian(float degree);


#endif
