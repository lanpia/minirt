/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:00:18 by nahyulee          #+#    #+#             */
/*   Updated: 2023/12/07 19:31:27 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	draw(t_rt *rt)
{
	drawsphere(rt, rt->data.sphere);
	drawplane(rt, rt->data.plane);
	drawcylinder(rt, rt ->data.cylinder);
}

void	drawsphere(t_rt *rt, t_sp sphere)
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
			ray.dir = normalize_vector((t_vtr3){u, v, -1});
			ray.origin = rt->data.camera.cam;
			rt->data.camera.ray = ray;
			intersect_sphere(rt);
			rt->data.camera.color = ray_color(rt);
			my_mlx_pixel_put(rt, j, i, rt->data.camera.color);
		}
	}
}

void	drawplane(t_rt *rt, t_pl plane)
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
			ray.dir = normalize_vector((t_vtr3){u, v, -1});
			ray.origin = rt->data.camera.cam;
			rt->data.camera.ray = ray;
			intersect_plane(rt);
			rt->data.camera.color = ray_color(rt);
			my_mlx_pixel_put(rt, j, i, rt->data.camera.color);
		}
	}
}

void	drawcylinder(t_rt *rt, t_cy cylinder)
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
			ray.dir = normalize_vector((t_vtr3){u, v, -1});
			ray.origin = rt->data.camera.cam;
			rt->data.camera.ray = ray;
			intersect_cylinder(rt);
			rt->data.camera.color = ray_color(rt);
			my_mlx_pixel_put(rt, j, i, rt->data.camera.color);
		}
	}
}
