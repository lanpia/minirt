/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:25:10 by nahyulee          #+#    #+#             */
/*   Updated: 2024/01/03 14:15:45 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_H
# define OBJ_H

# include "_vector/vector.h"

enum e_obj{plane, sphere, cylinder};
enum e_color{red, green, blue};

typedef struct s_ambentlight
{
	float	ratio;
	int		color[3];
}	t_a;

typedef struct s_camera
{
	t_vtr3	position;
	t_vtr3	dir;
	int		fov;
}	t_c;

typedef struct s_light
{
	t_vtr3	position;
	float	brightness;
	int		color[3];
}	t_l;

typedef struct s_plane
{
	t_vtr3	position;
	t_vtr3	orientation;
	int		color[3];
}	t_pl;

typedef struct s_sphere
{
	t_vtr3	center;
	float	radius;
	int		color[3];
}	t_sp;

typedef struct s_cylinder
{
	t_vtr3	center;
	t_vtr3	orientation;
	float	diameter;
	float	height;
	int		color[3];
}	t_cy;

typedef struct s_ray
{
	t_vtr3	origin;
	t_vtr3	direction;
}	t_ray;

typedef struct s_viewplane
{
	double	half_width;
	double	half_height;
	double	theta;
	double	t;
	t_vtr3	center;
	t_vtr3	left_top;
}	t_vwpl;

typedef struct s_intersec
{
	t_vtr3	hit;
	t_vtr3	normal;
	float	t;
	int		obj_type;
	int		color[3];
}	t_intr;

typedef struct s_data
{
	t_a		ambient;
	t_c		camera;
	t_l		light;
	t_pl	plane;
	t_sp	sphere;
	t_cy	cylinder;
	int		obj_cnt[3];
	t_vwpl	viewplane;
	t_ray	ray;
	t_intr	intersec;
}	t_d;

#endif