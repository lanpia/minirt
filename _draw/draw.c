/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:00:18 by nahyulee          #+#    #+#             */
/*   Updated: 2023/12/07 16:21:02 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

/**/
// void	sphere(t_rt *rt)
// {
// 	// 구체를 고정값으로 처리한 상태. 즉, 파싱해서 이 고정된 값에 다가 값을 넣어야 함
// 	// sphere: 구체
// 	rt->data.sphere.center = (t_vtr3){0, 0, 20};
// 	rt->data.sphere.radius = 20;
// 	rt->data.sphere.color = rgb_hex(255, 0, 0);
	
// 	rt->data.camera.cam = (t_vtr3){-50, 0, 20};
// 	rt->data.camera.dir = (t_vtr3){0, 0, 0};
// 	rt->data.camera.fov = 70;
// }


// void	drawsphere(t_rt *rt, t_sp sphere)
// {
// 	t_vtr3	point3d;
// 	t_vtr2	coord;
// 	float	u;
// 	float	angle;
// 	float	v;

// 	angle = 0.0f;
// 	while (angle < 360.0f)
// 	{
// 		v = -sphere.radius;
// 		while (v < sphere.radius)
// 		{
// 			u = sqrt(sphere.radius * sphere.radius - v * v);
// 			point3d = (t_vtr3){sphere.center.x + u * cos(angle * M_PI / 180), \
// 							sphere.center.y + v, \
// 							sphere.center.z + u * sin(angle * M_PI / 180)};
// 			coord = project3dto2d(rt, point3d);
// 			mlx_pixel_put(rt->mlx, rt->window, coord.x, coord.y, sphere.color);
// 			v += 0.1f;
// 		}
// 		angle += 0.1f;
// 	}
// }

void	draw(t_rt *rt)
{
	drawsphere(rt, rt->data.sphere);
	drawplane(rt, rt->data.plane);
	draw_cylinder(rt, rt ->data.cylinder);
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