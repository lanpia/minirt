/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:51:11 by nahyulee          #+#    #+#             */
/*   Updated: 2023/12/02 21:23:11 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define WIDTH 800
#define HEIGHT 600

typedef struct s_v
{
	float x, y, z;
}	Vector3D;

// 카메라 정의
typedef struct s_c
{
	Vector3D position;
	Vector3D direction;
	float fov;
	float aspectRatio;
	float nearPlane;
	float farPlane;
}   Camera;

// 원근 투영을 위한 함수
Vector3D perspectiveProjection(Camera cam, Vector3D point3D)
{
	Vector3D point2D;
	float scale = tan(cam.fov * 0.5 * M_PI / 180) * cam.nearPlane;
	point2D.x = (point3D.x / point3D.z) * scale * cam.aspectRatio;
	point2D.y = (point3D.y / point3D.z) * scale;
	point2D.z = point3D.z;
	return point2D;
}

// 뷰포트 변환
Vector3D viewportTransform(Vector3D point2D)
{
	point2D.x = (point2D.x + 1) * WIDTH / 2;
	point2D.y = (1 - point2D.y) * HEIGHT / 2;
	return point2D;
}

void drawViewport(Camera cam, Vector3D *points, int numPoints, void *mlx_ptr, void *win_ptr)
{
	for (int i = 0; i < numPoints; i++) {
		Vector3D projectedPoint = perspectiveProjection(cam, points[i]);
		Vector3D screenPoint = viewportTransform(projectedPoint);
		mlx_pixel_put(mlx_ptr, win_ptr, screenPoint.x, screenPoint.y, 0xFFFFFF);
	}
}
