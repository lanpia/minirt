/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 01:25:16 by nahyulee          #+#    #+#             */
/*   Updated: 2023/12/25 17:59:21 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

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
	t_vtr3	coordi;

	rt->viewplane.aspect_ratio = (double)rt->width / (double)rt->height;
	rt->viewplane.theta = rt->data.camera.fov * M_PI / 180;
	rt->viewplane.half_height = tan(rt->viewplane.theta / 2);
	rt->viewplane.half_width = rt->viewplane.aspect_ratio * \
								rt->viewplane.half_height;
	rt->viewplane.distance = rt->width / (2 * tan(rt->viewplane.theta / 2));
	coordi = multiply_vector(rt->data.camera.uvw.w, \
										rt->viewplane.distance, \
										rt->viewplane.distance, \
										rt->viewplane.distance);
	rt->viewplane.center = add_vector(rt->data.camera.cam, coordi);
	rt->viewplane.left_top = subtract_vector(rt->viewplane.center, \
										(t_vtr3){rt->viewplane.half_width, \
										rt->viewplane.half_height, 0});
}

void	raycast(t_rt *rt)
{
	int		i;
	int		j;
	double	x;
	double	y;
	t_vtr3	uvw;

	i = -1;
	while (++i < rt->height)
	{
		j = -1;
		while (++j < rt->width)
		{
			x = (2 * ((j + 0.5) / rt->width) - 1) * \
				rt->data.camera.viewplane.half_width;
			y = (1 - 2 * ((i + 0.5) / rt->height)) * \
				rt->data.camera.viewplane.half_height;
			uvw = add_val_vtr3(rt->data.camera.cam, x, y, 0);
			rt->data.camera.ray.dir = normalize_vector(uvw);
			rt->data.camera.ray.origin = rt->data.camera.cam;
			rt->data.camera.color = 0;
			intersect(rt);
			my_mlx_pixel_put(rt, j, i, rt->data.camera.color);
		}
	}
}

void	my_mlx_pixel_put(t_rt *rt, int x, int y, int color)
{
	char	*pixel;

	if (0 <= x && x < rt->width && 0 <= y && y < rt->height)
	{
		pixel = rt->addr + (y * rt->size_line + x * 4);
		*(int *)pixel = color;
	}
}

int	compute_phong_shading(t_rt *rt, t_vtr3 hit_point, t_vtr3 normal, int color)
{
	// Light direction
	t_vtr3 light_dir = normalize_vector(subtract_vector(rt->data.light.position, hit_point));
	// Ambient color
	int ambient_r = get_color_component(rt->data.ambient.color, 16) * rt->data.ambient.ratio;
	int ambient_g = get_color_component(rt->data.ambient.color, 8) * rt->data.ambient.ratio;
	int ambient_b = get_color_component(rt->data.ambient.color, 0) * rt->data.ambient.ratio;
	// Diffuse color
	double diff = fmax(dot_product(normal, light_dir), 0.0);
	int diffuse_r = get_color_component(rt->data.light.color, 16) * diff;
	int diffuse_g = get_color_component(rt->data.light.color, 8) * diff;
	int diffuse_b = get_color_component(rt->data.light.color, 0) * diff;
	// Specular color
	t_vtr3 reflect_dir = reflect_vector(multiply_vector(light_dir, -1, -1, -1), normal);
	double spec = pow(fmax(dot_product(rt->data.camera.dir, reflect_dir), 0.0), rt->data.light.brightness);
	int specular_r = 0.5 * spec * 255;
	int specular_g = 0.5 * spec * 255;
	int specular_b = 0.5 * spec * 255;
	// Combine colors
	int r = fmin((get_color_component(color, 16) + ambient_r + diffuse_r + specular_r), 255);
	int g = fmin((get_color_component(color, 8) + ambient_g + diffuse_g + specular_g), 255);
	int b = fmin((get_color_component(color, 0) + ambient_b + diffuse_b + specular_b), 255);
	return (rgb_hex(r, g, b));
}
