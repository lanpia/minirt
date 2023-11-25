/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:00:18 by nahyulee          #+#    #+#             */
/*   Updated: 2023/11/25 21:23:28 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// t_vtr2	project3dto2d(t_rt *rt, t_vtr3 point3d)
// {
// 	t_vtr2	point2d;
//     float scale;
//     float xProjected;
//     float yProjected;

// 	scale = tan(rt->data.camera.fov * 0.5 * M_PI / 180) * rt->data.camera.cam.z;
// 	xProjected = (point3d.x - rt->data.camera.cam.x) * scale / point3d.z;
// 	yProjected = (point3d.y - rt->data.camera.cam.y) * scale / point3d.z;
// 	point2d.x = (int)((xProjected + 1) * rt->width / 2);
//     point2d.y = (int)((1 - yProjected) * rt->height / 2);
// 	return (point2d);
// }

t_vtr2	project3dto2d(t_rt *rt, t_vtr3 point3d)
{
	t_vtr2	point2d;

    point2d.x = (int)(rt->width / 2 + point3d.x);
    point2d.y = (int)(rt->height / 2 - point3d.y);
	return (point2d);
}

void	drawsphere(t_rt *rt, t_sp sphere)
{
	t_vtr3	point3d;
    t_vtr2	coord;
	float	u;
    float	angle;
	float	v;

	angle = 0.0f;
    while (angle < 360.0f)
	{
        v = -rt->data.sphere.radius;
        while (v < rt->data.sphere.radius)
		{
            u = sqrt(rt->data.sphere.radius * rt->data.sphere.radius - v * v);
            point3d = (t_vtr3){rt->data.sphere.center.x + u * cos(angle * M_PI / 180), rt->data.sphere.center.y + v, rt->data.sphere.center.z + u * sin(angle * M_PI / 180)};
            coord = project3dto2d(rt, point3d);
			mlx_pixel_put(rt->mlx, rt->window, coord.x, coord.y, sphere.color);
            v += 0.1f;
        }
        angle += 0.1f;
    }
}