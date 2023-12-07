/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:20:51 by nahyulee          #+#    #+#             */
/*   Updated: 2023/12/07 19:25:30 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	intersect(t_rt *rt)
{
	intersect_sphere(rt);
	intersect_plane(rt);
	intersect_cylinder(rt);
}

void	intersect_sphere(t_rt *rt)
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
