/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 01:25:16 by nahyulee          #+#    #+#             */
/*   Updated: 2023/11/22 03:31:10 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	move_camera(t_cam camera, int x, int y, int z)
{
	camera.cam.x += x;
	camera.cam.y += y;
	camera.cam.z += z;
}

void project3Dto2D(t_vtr3 point3D, int *x2D, int *y2D, t_vtr3 camera, float fov)
{
    // 카메라 시야각을 기반으로 하는 간단한 투영
    float scale = tan(fov * 0.5 * M_PI / 180) * camera.z;
    float xProjected = (point3D.x - camera.x) * scale / point3D.z;
    float yProjected = (point3D.y - camera.y) * scale / point3D.z;

    // 화면 좌표로 변환
    *x2D = (int)((xProjected + 1) * 800 / 2);
    *y2D = (int)((1 - yProjected) * 600 / 2);
}

// 간단한 3D 객체를 렌더링하는 함수
void render3DObject(t_rt *rt, t_vtr3 camera, float fov)
{
    // 임의의 3D 점 (예시)
    t_vtr3 point3D = {0, 0, 100}; // 원점에서 z축으로 100 단위 떨어진 점
    int x2D, y2D;

    // 3D 점을 2D로 투영
    project3Dto2D(point3D, &x2D, &y2D, camera, fov);

    // 화면에 그리기
    mlx_pixel_put(rt->mlx, rt->window, x2D, y2D, 0xFFFFFF); // 흰색 점
}
