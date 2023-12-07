/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 03:28:03 by nahyulee          #+#    #+#             */
/*   Updated: 2023/12/07 15:19:09 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int ac, char **av)
{
	t_rt	*rt;

	if (ac < 2 || ac > 3)
		ft_exit(1, "bad argument\n");
	rt = (t_rt *)ft_calloc(sizeof(t_rt), 1);
	read_data(rt, av);
	rt->mlx = mlx_init();
	rt->window = mlx_new_window(rt->mlx, rt->width, rt->height, "miniRT");
	
	cam_lookat(rt);
	viewplane(rt);
	raycast(rt);
	
	mlx_hook(rt->window, X_EVENT_KEY_PRESS, 0, press_key, rt);
	mlx_hook(rt->window, X_EVENT_KEY_EXIT, 0, print_error, rt);
	mlx_loop(rt->mlx);
	return (0);
}

	// drawplane(rt, rt->data.plane);
	// drawsphere(rt, rt->data.sphere);

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

void raycast(t_rt *rt)
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

/* 
	@breif		: 레이와 물체의 교차점을 구하는 함수
	intersect_sphere(rt);
	intersect_plane(rt);
	intersect_cylinder(rt);
	*/
void intersect(t_rt *rt)
{
	intersect_sphere(rt);
	intersect_plane(rt);
	intersect_cylinder(rt);
}

void intersect_sphere(t_rt *rt)
{
	t_vtr3	oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	t;
	t_vtr3	sphere_center;

	sphere_center = rt->data.sphere.center;
	oc = add_vector(rt->data.camera.ray.origin, sphere_center);
	a = dot_product(rt->data.camera.ray.dir, rt->data.camera.ray.dir);
	b = 2.0 * dot_product(oc, rt->data.camera.ray.dir);
	c = dot_product(oc, oc) - rt->data.sphere.radius * rt->data.sphere.radius;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return ;
	t = (-b - sqrt(discriminant)) / (2.0 * a);
	if (t < 0)
		t = (-b + sqrt(discriminant)) / (2.0 * a);
	if (t < 0)
		return ;
	rt->data.sphere.t = t;
	rt->data.sphere.hit_point = add_vector(rt->data.camera.ray.origin, multiply_vector(rt->data.camera.ray.dir, t, t, t));
	rt->data.sphere.normal = normalize_vector(subtract_vector(rt->data.sphere.hit_point, sphere_center));
}

void	intersect_plane(t_rt *rt)
{
	double	d;
	double	t;
	t_vtr3	plane_center;

	plane_center = rt->data.plane.center;
	d = dot_product(subtract_vector(plane_center, rt->data.camera.ray.origin), rt->data.plane.normal);
	t = d / dot_product(rt->data.camera.ray.dir, rt->data.plane.normal);
	if (t < 0)
		return ;
	rt->data.plane.t = t;
	rt->data.plane.hit_point = add_vector(rt->data.camera.ray.origin, multiply_vector(rt->data.camera.ray.dir, t, t, t));
	rt->data.plane.normal = rt->data.plane.normal;
}

void	intersect_cylinder(t_rt *rt)
{
	t_vtr3	oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	t;
	t_vtr3	cylinder_center;

	cylinder_center = rt->data.cylinder.center;
	oc = subtract_vector(rt->data.camera.ray.origin, cylinder_center);
	a = dot_product(rt->data.camera.ray.dir, rt->data.camera.ray.dir) - pow(dot_product(rt->data.camera.ray.dir, rt->data.cylinder.dir), 2);
	b = 2.0 * (dot_product(oc, rt->data.camera.ray.dir) - dot_product(oc, rt->data.cylinder.dir) * dot_product(rt->data.camera.ray.dir, rt->data.cylinder.dir));
	c = dot_product(oc, oc) - pow(dot_product(oc, rt->data.cylinder.dir), 2) - pow(rt->data.cylinder.radius, 2);
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return ;
	t = (-b - sqrt(discriminant)) / (2.0 * a);
	if (t < 0)
		t = (-b + sqrt(discriminant)) / (2.0 * a);
	if (t < 0)
		return ;
	rt->data.cylinder.t = t;
	rt->data.cylinder.hit_point = add_vector(rt->data.camera.ray.origin, multiply_vector(rt->data.camera.ray.dir, t, t, t));
	rt->data.cylinder.normal = normalize_vector(subtract_vector(rt->data.cylinder.hit_point, cylinder_center));
}

void	find_min_hit_intersection(t_rt *rt)
{
	double	min_t;
	double	t;

	min_t = INFINITY;
	if (rt->data.sphere.t > 0 && rt->data.sphere.t < min_t)
		min_t = rt->data.sphere.t;
	if (rt->data.plane.t > 0 && rt->data.plane.t < min_t)
		min_t = rt->data.plane.t;
	if (rt->data.cylinder.t > 0 && rt->data.cylinder.t < min_t)
		min_t = rt->data.cylinder.t;
	rt->data.camera.t = min_t;
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