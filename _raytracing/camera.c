/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 01:25:16 by nahyulee          #+#    #+#             */
/*   Updated: 2024/01/03 03:35:58 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	cam_lookat(t_c cam, t_vwpl view)
{
	t_vtr3 forward = normalize_vector(cam.dir);
	t_vtr3 up = (t_vtr3){0, 1, 0};
	t_vtr3 right = normalize_vector(cross_product(up, forward));
	t_vtr3 view_center = add_vector(cam.position, \
		multiply_vector(forward, view.distance, view.distance, view.distance));
	up = cross_product(forward, right);
	view.half_height = tan(cam.fov * 0.5 * (M_PI / 180.0));
	view.half_width = view.half_height * view.aspect_ratio;
	t_vtr3 up_scaled = multiply_vector(up, view.half_height, view.half_height, view.half_height);
	t_vtr3 right_scaled = multiply_vector(right, view.half_width, view.half_width, view.half_width);
	view.left_top = subtract_vector(subtract_vector(view_center, right_scaled), up_scaled);
}
void	raycast(t_rt *rt, t_d data, t_mlx mlx)
{
	t_rt	rt;
	int		i;
	int		j;
	int		color;

	i = 0;
	while (i < mlx.height)
	{
		j = 0;
		while (j < mlx.width)
		{
			data.ray = get_ray(data.camera, data.viewplane, i, j);
			my_mlx_pixel_put(mlx, j, i, intersect(rt, data));
			j++;
		}
		i++;
	}
}

int	intersect(t_rt *rt, t_d data)
{
	int	color;

	if (data.obj_flag[plane] == true)
		color = intersect_plane(rt);
	else if (data.obj_flag[sphere] == true)
		color = intersect_sphere(rt);
	else if (data.obj_flag[cylinder] == true)
		color = intersect_cylinder(rt);
	return (color);
}