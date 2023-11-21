/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 03:28:03 by nahyulee          #+#    #+#             */
/*   Updated: 2023/11/22 03:34:19 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// 간단한 3D 점을 2D로 투영하는 함수

// 구 그리기
void	drawsphere(t_rt *rt, t_sp sphere)
{
	t_2d	coord;

	for (float angle = 0; angle < 360; angle += 0.1)
	{
		for (float v = -sphere.radius; v < sphere.radius; v += 0.1)
		{
			float u = sqrt(sphere.radius * sphere.radius - v * v);
			t_vtr3 point3d = {sphere.center.x + u * cos(angle), sphere.center.y + v, sphere.center.z + u * sin(angle)};
			coord = project3dto2d(rt, point3d, coord);
			mlx_pixel_put(rt->mlx, rt->window, coord.x, coord.y, sphere.color);
		}
	}
}

int	press_key(int key_val, t_rt *rt)
{
	if (key_val == KEY_ESC)
		ft_exit(0, "Exit_miniRT\n");
	if (key_val == KEY_W)
		move_camera(rt->data.camera, 0, 0, 1);
	if (key_val == KEY_UP)
		move_camera(rt->data.camera, 0, 1, 0);
	if (key_val == KEY_A || key_val == KEY_LEFT)
		move_camera(rt->data.camera, -1, 0, 0);
	if (key_val == KEY_S)
		move_camera(rt->data.camera, 0, 0, -1);
	if (key_val == KEY_DOWN)
		move_camera(rt->data.camera, 0, -1, 0);
	if (key_val == KEY_D || key_val == KEY_RIGHT)
		move_camera(rt->data.camera, 1, 0, 0);
	ft_exit(0, "Exit_miniRT\n");
	return (0);
}

int	main(int ac, char **av)
{
	t_rt	*rt;
	t_sp sphere = {{0.0, 0.0, 20.6}, 12.6, 0x0A00FF}; // 색상: 10, 0, 255

	(void)av;
	if (ac != 2)
		ft_exit(1, "bad argument\n");
	rt = make_array();
	// read_data(rt, av);
	rt->mlx = mlx_init();
	rt->window = mlx_new_window(rt->mlx, rt->width, rt->height, "miniRT");

	drawsphere(rt, sphere);

	mlx_hook(rt->window, X_EVENT_KEY_PRESS, 0, press_key, rt);
	mlx_hook(rt->window, X_EVENT_KEY_EXIT, 0, press_key, rt);
	mlx_loop(rt->mlx);
	return (0);
}



// #include <mlx.h>
// #include <stdio.h>
// #include <math.h>

// #define WIN_WIDTH 800
// #define WIN_HEIGHT 600

// typedef struct {
//     float x, y, z;
// } Vector3D;

// typedef struct {
//     Vector3D origin;
//     Vector3D direction;
// } Ray;

// typedef struct {
//     Vector3D center;
//     float radius;
// } Sphere;

// // 벡터 연산들
// Vector3D vectorSubtract(Vector3D a, Vector3D b) {
//     return (Vector3D){a.x - b.x, a.y - b.y, a.z - b.z};
// }

// float dotProduct(Vector3D a, Vector3D b) {
//     return a.x * b.x + a.y * b.y + a.z * b.z;
// }

// // 레이와 구의 교차 검사
// int intersectRaySphere(Ray ray, Sphere sphere, float* t) {
//     Vector3D oc = vectorSubtract(ray.origin, sphere.center);
//     float a = dotProduct(ray.direction, ray.direction);
//     float b = 2.0 * dotProduct(oc, ray.direction);
//     float c = dotProduct(oc, oc) - sphere.radius * sphere.radius;
//     float discriminant = b * b - 4 * a * c;
//     if (discriminant < 0) {
//         return 0; // 교차하지 않음
//     } else {
//         // 최소 t 값을 계산
//         *t = (-b - sqrt(discriminant)) / (2.0 * a);
//         return 1; // 교차함
//     }
// }

// int main() {
//     void *mlx_ptr, *win_ptr;

//     // MiniLibX 초기화
//     mlx_ptr = mlx_init();
//     win_ptr = mlx_new_window(mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Raycasting with MiniLibX");

//     // 레이와 구 설정
//     Ray ray = {{0, 0, 0}, {1, 2, 3}};
//     Sphere sphere = {{4, 6, 8}, 10};
//     float t;

//     // 레이와 구의 교차 검사
//     if (intersectRaySphere(ray, sphere, &t)) {
//         // 교차점에 점 그리기 (예시로서, 화면 중앙에 점을 그림)
//         mlx_pixel_put(mlx_ptr, win_ptr, WIN_WIDTH / 2, WIN_HEIGHT / 2, 0x00FF00); // 녹색 점
//     }

//     // 이벤트 루프 시작
//     mlx_loop(mlx_ptr);

//     return 0;
// }
