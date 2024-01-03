/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 01:25:16 by nahyulee          #+#    #+#             */
/*   Updated: 2024/01/03 14:17:54 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	cam_lookat(t_c cam, t_vwpl *view, double ratio)
{
	t_vtr3	up;
	t_vtr3	right;
	t_vtr3	up_scaled;
	t_vtr3	right_scaled;

	right = normalize_vector(cross_product((t_vtr3){0, 1, 0}, \
					normalize_vector(cam.dir)));
	view->center = add_vector(cam.position, \
		multiply_vector(normalize_vector(cam.dir), view->t, view->t, view->t));
	up = cross_product(normalize_vector(cam.dir), right);
	view->half_height = tan(cam.fov * 0.5 * (M_PI / 180.0)) / ratio;
	view->half_width = 1;
	up_scaled = multiply_vector(up, view->half_height, \
						view->half_height, view->half_height);
	right_scaled = multiply_vector(right, view->half_width, \
						view->half_width, view->half_width);
	view->left_top = subtract_vector(subtract_vector(view->center, \
						right_scaled), up_scaled);
}

// void	raycast(t_rt *rt, t_d data, t_mlx mlx)
// {
// 	t_rt	rt;
// 	int		i;
// 	int		j;
// 	int		color;

// 	i = 0;
// 	while (i < mlx.height)
// 	{
// 		j = 0;
// 		while (j < mlx.width)
// 		{
// 			data.ray = get_ray(data.camera, data.viewplane, i, j);
// 			my_mlx_pixel_put(mlx, j, i, intersect(rt, data));
// 			j++;
// 		}
// 		i++;
// 	}
// }

int	intersect(t_rt *rt, t_d data)
{
	int	color;

	if (data.obj_cnt[plane] > 0)
		color = intersect_plane(rt);
	else if (data.obj_cnt[sphere] > 0)
		color = intersect_sphere(rt);
	else if (data.obj_cnt[cylinder] > 0)
		color = intersect_cylinder(rt);
	return (phong_shading(data, data.intersec, data.ray, data.intersec.color));
}

void	my_mlx_pixel_put(t_mlx mlx, int x, int y, int color)
{
	char	*pixel;

	if (0 <= x && x < WIDTH && 0 <= y && y < HEIGHT)
	{
		pixel = mlx.addr + (y * mlx.size_line + x * 4);
		*(int *)pixel = color;
	}
}

int	phong_shading(t_d data, t_intr intr, t_ray ray, int color[3])
{
	t_vtr3	reflect_dir;
	double	diff;
	double	spec;
	int		result[3];
	int		i;

	reflect_dir = reflect_vector(multiply_vector(ray.direction, -1), \
					intr.normal);
	diff = max(dot_product(intr.normal, ray.direction), 0.0);
	spec = pow(max(dot_product(ray.direction, reflect_dir), 0.0), 32);
	i = -1;
	while (++i < 3)
	{
		result[i] = (data.ambient.ratio * data.ambient.color[i] + \
					diff * data.light.color[i] + \
					0.5 * spec * data.light.color[i]) * color[i];
		result[i] = max(min(result[i], 1.0), 0.0);
	}
	return ((result[red] << 16) | (result[green] << 8) | result[blue]);
}
