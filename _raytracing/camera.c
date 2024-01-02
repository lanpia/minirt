/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 01:25:16 by nahyulee          #+#    #+#             */
/*   Updated: 2024/01/03 08:18:41 by nahyulee         ###   ########.fr       */
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

// int	intersect(t_rt *rt, t_d data)
// {
// 	int	color;

// 	if (data.obj_flag[plane] == true)
// 		color = intersect_plane(rt);
// 	else if (data.obj_flag[sphere] == true)
// 		color = intersect_sphere(rt);
// 	else if (data.obj_flag[cylinder] == true)
// 		color = intersect_cylinder(rt);
// 	return (color);
// }

void	my_mlx_pixel_put(t_mlx mlx, int x, int y, int color)
{
	char	*pixel;

	if (0 <= x && x < WIDTH && 0 <= y && y < HEIGHT)
	{
		pixel = mlx.addr + (y * mlx.size_line + x * 4);
		*(int *)pixel = color;
	}
}

unsigned int	rgb_hex(int red, int green, int blue)
{
	unsigned int	color;

	color = (red << 16) | (green << 8) | blue;
	return (color);
}