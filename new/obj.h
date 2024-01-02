/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:25:10 by nahyulee          #+#    #+#             */
/*   Updated: 2024/01/02 22:31:14 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_H
# define OBJ_H

# include "vector.h"

typedef struct s_ambentlight
{
	float			ratio;
	unsigned int	color;
}	t_a;

typedef struct s_camera
{
	t_vtr3			position;
	t_vtr3			dir;
	int				fov;
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
	t_vtr3			normal;
	t_vtr3			center;
	t_vtr3			hit_point;
}	t_pl;

typedef struct s_sphere
{
	t_vtr3			center;
	float			radius;
	unsigned int	color;
}	t_sp;

typedef struct s_cylinder
{
	t_vtr3			center;
	t_vtr3			orientation;
	float			diameter;
	float			height;
	unsigned int	color;
}	t_cy;

typedef struct s_ray
{
	t_vtr3	origin;
	t_vtr3	dir;
}	t_ray;

typedef struct s_viewplane
{
	double	half_width;
	double	half_height;
	double	aspect_ratio;
	double	theta;
	double	distance;
	t_vtr3	center;
	t_vtr3	left_top;
}	t_vwpl;

typedef struct s_data
{
	bool	*obj;
	t_a		ambient;
	t_c		camera;
	t_l		light;
	t_pl	plane;
	t_sp	sphere;
	t_cy	cylinder;
	t_vwpl	viewplane;
	t_ray	ray;
}	t_d;

enum e_obj{plane, sphere, cylinder};

#endif