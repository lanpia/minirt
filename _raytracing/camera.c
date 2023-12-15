/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohkang <soohkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 01:25:16 by nahyulee          #+#    #+#             */
/*   Updated: 2023/12/15 03:28:09 by soohkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

// camera setting
void	turn_on_camera(t_rt *rt)
{
	// 카메라 관련 변수 선언
	double	viewport[2]; // width, height
	double	fov_degree_to_rad; // field of view

	viewport[0] = 3.0;
	viewport[1] = 3.0;
	fov_degree_to_rad = tan(degree_to_radian(rt->data.camera.fov));
	
}

// void	move_camera(t_c camera, int x, int y, int z)
// {
// 	camera.cam.x += x;
// 	camera.cam.y += y;
// 	camera.cam.z += z;
// }
