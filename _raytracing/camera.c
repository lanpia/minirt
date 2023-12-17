/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohkang <soohkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 01:25:16 by nahyulee          #+#    #+#             */
/*   Updated: 2023/12/17 18:30:06 by soohkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

// camera setting
void	initialize_camera(t_rt *rt)
{
	// 카메라 관련 변수 선언
	double	viewport[2]; // width, height
	double	fov_degree_to_rad; // field of view's half in radians
	t_vtr3	cam_position;
	t_vtr3	cam_up_position;

	// 카메라 위치 초기화
	cam_position.x = 0.0; // x position
	cam_position.y = 0.0; // y position
	cam_position.z = 5.0; // z position
	
	// 카메라 객체에 위치 설정
	rt->data.camera.cam = cam_position;

	// up vector: Determine the "up" orien–tation of the camera
	cam_up_position = (t_vtr3){0.0, 1.0, 0.0};

	// setting fov degree
	rt->data.camera.fov = 120;
	fov_degree_to_rad = tan(degree_to_radian(rt->data.camera.fov / 2.0));

	// setting viewport
	viewport[0] = 3.0;
	viewport[1] = 3.0;
}

// void	move_camera(t_c camera, int x, int y, int z)
// {
// 	camera.cam.x += x;
// 	camera.cam.y += y;
// 	camera.cam.z += z;
// }
