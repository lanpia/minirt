/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 01:25:16 by nahyulee          #+#    #+#             */
/*   Updated: 2024/01/05 04:13:15 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	cam_lookat(t_c *cam, t_vwpl *view, double ratio)
{
	t_vtr3	center;
	t_vtr3	left_top;
	t_vtr3	x_dir;
	t_vtr3	y_dir;

	view->half_height = tan(cam->fov * 0.5 * (M_PI / 180.0)) / ratio;
	view->half_width = 1;
	view->t = view->half_width / tan((cam->fov * (M_PI / 180.0)) / 2.0);
	center = multiply_vector((cam->dir), view->t, view->t, view->t);
	view->center = add_vector(cam->position, center);
	left_top = subtract_vector(view->center, \
					multiply_vector((t_vtr3){1, 0, 0}, view->half_width, \
					view->half_width, view->half_width));
	cam->right = normalize_vector(cross_product((t_vtr3){0, 1, 0}, \
					normalize_vector(cam->dir)));
	cam->up = normalize_vector(cross_product(cam->right, cam->dir));
	x_dir = multiply_vector(cam->right, view->half_width * 2, \
					view->half_width * 2, view->half_width * 2);
	y_dir = multiply_vector((t_vtr3){0, 1, 0}, view->half_height * 2, \
					view->half_height * 2, view->half_height * 2);
	view->left_top = add_vector(left_top, x_dir);
	view->left_top = add_vector(view->left_top, y_dir);
}

t_ray	get_ray(t_c cam, t_vwpl view, int y, int x)
{
	t_ray	ray;
	t_vtr3	loc_pos_x;
	t_vtr3	loc_pos_y;

	ray.origin = cam.position;
	loc_pos_x = multiply_vector(cam.right, x, x, x);
	loc_pos_y = multiply_vector(cam.up, y, y, y);
	ray.dir = add_vector(view.left_top, add_vector(loc_pos_x, loc_pos_y));
	ray.dir = normalize_vector(subtract_vector(ray.dir, ray.origin));
	return (ray);
}


void	raycast(t_d data, t_mlx *mlx)
{
	int		i;
	int		j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			data.ray = get_ray(data.camera, data.viewplane, i, j);
			intersect(data);
			my_mlx_pixel_put(mlx, j, i, intersect(data));
			j++;
		}
		i++;
	}
}

int	intersect(t_d data)
{
	t_intr	intersec;

	// if (data.obj_cnt[plane] > 0)
	intersec = intersect_plane(data.plane, data.ray);
	// else if (data.obj_cnt[sphere] > 0)
	// 	intersec = intersect_sphere(data.sphere, data.ray);
	// else if (data.obj_cnt[cylinder] > 0)
	// 	color = intersect_cylinder(rt);
	// return (phong_shading(data, intersec, data.ray, intersec.color));
	return (rgb_hex(intersec.color[red], intersec.color[green], \
					intersec.color[blue]));
}

int	phong_shading(t_d data, t_intr intr, t_ray ray, int color[3])
{
	t_vtr3	reflect_dir;
	double	diff;
	double	spec;
	int		result[3];
	int		i;

	reflect_dir = reflect_vector(multiply_vector(ray.dir, -1, -1, -1), \
					intr.normal);
	diff = fmax(dot_product(intr.normal, ray.dir), 0.0);
	spec = pow(fmax(dot_product(ray.dir, reflect_dir), 0.0), 32);
	i = -1;
	while (++i < 3)
	{
		result[i] = (data.ambient.ratio * data.ambient.color[i] + \
					diff * data.light.color[i] + \
					0.5 * spec * data.light.color[i]) * color[i];
		result[i] = fmax(fmin(result[i], 1.0), 0.0);
	}
	return ((result[red] << 16) | (result[green] << 8) | result[blue]);
}
