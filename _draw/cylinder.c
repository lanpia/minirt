/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohkang <soohkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:camera.c
/*   Created: 2023/12/07 15:21:50 by nahyulee          #+#    #+#             */
/*   Updated: 2023/12/07 15:28:39 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	cam_lookat(t_rt *rt)
{
	t_vtr3	lookat;
	t_vtr3	up;
	t_vtr3	w;
	t_vtr3	u;
	t_vtr3	v;

	lookat = subtract_vector(rt->data.camera.dir, rt->data.camera.cam);
	lookat = normalize_vector(lookat);
	up = (t_vtr3){0, 1, 0};
	w = normalize_vector(lookat);
	u = normalize_vector(cross_product(up, w));
	v = cross_product(w, u);
	rt->data.camera.uvw = (t_uvw){u, v, w};
}

void	viewplane(t_rt *rt)
{
	double	aspect_ratio;
	double	theta;
	double	half_height;
	double	half_width;

	aspect_ratio = (double)rt->width / (double)rt->height;
	theta = rt->data.camera.fov * M_PI / 180;
	half_height = tan(theta / 2);
	half_width = aspect_ratio * half_height;
	rt->data.camera.viewplane = (t_vwpl){half_width, half_height};
}

void	raycast(t_rt *rt)
{
	int		i;
	int		j;
	double	x;
	double	y;
	double	u;
	double	v;
	t_ray	ray;

	i = -1;
	while (++i < rt->height)
	{
		j = -1;
		while (++j < rt->width)
		{
			x = (2 * ((j + 0.5) / rt->width) - 1) * rt->data.camera.viewplane.half_width;
			y = (1 - 2 * ((i + 0.5) / rt->height)) * rt->data.camera.viewplane.half_height;
			u = x * rt->data.camera.uvw.u.x + y * rt->data.camera.uvw.v.x + rt->data.camera.uvw.w.x;
			v = x * rt->data.camera.uvw.u.y + y * rt->data.camera.uvw.v.y + rt->data.camera.uvw.w.y;
			ray.dir = vtr3_normalize((t_vtr3){u, v, -1});
			ray.origin = rt->data.camera.cam;
			rt->data.camera.ray = ray;
			intersect(rt);
			rt->data.camera.color = ray_color(rt);
			my_mlx_pixel_put(rt, j, i, rt->data.camera.color);
		}
	}
}

void	find_normal(t_rt *rt)
{
	if (rt->data.camera.t == rt->data.sphere.t)
		rt->data.camera.normal = rt->data.sphere.normal;
	else if (rt->data.camera.t == rt->data.plane.t)
		rt->data.camera.normal = rt->data.plane.normal;
	else if (rt->data.camera.t == rt->data.cylinder.t)
		rt->data.camera.normal = rt->data.cylinder.normal;
}
=======
/*   Created: 2023/12/04 17:44:57 by soohkang          #+#    #+#             */
/*   Updated: 2023/12/04 17:44:59 by soohkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
>>>>>>> main:_draw/cylinder.c
