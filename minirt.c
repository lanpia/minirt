/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 03:28:03 by nahyulee          #+#    #+#             */
/*   Updated: 2023/11/22 10:19:36 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// // 레이와 구의 교차 검사
int	intersectRaySphere(t_ray ray, t_sp sphere, float* t)
{
	t_vtr3 oc = subtract_vector(ray.origin, sphere.center);
	float a = dotProduct(ray.direction, ray.direction);
	float b = 2.0 * dotProduct(oc, ray.direction);
	float c = dotProduct(oc, oc) - sphere.radius * sphere.radius;
	float discriminant = b * b - 4 * a * c;

	if (discriminant < 0)
		return (0);
	else
	{
		*t = (-b - sqrt(discriminant)) / (2.0 * a);
		return (1);
	}
}
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
	t_sp	sphere;

	(void)av;
	if (ac != 2)
		ft_exit(1, "bad argument\n");
	rt = make_array();
	// read_data(rt, av);
	sphere.center.x = 0.0;
	sphere.center.y = 0.0;
	sphere.center.z = 20.6;
	sphere.radius = 12.6;
	sphere.color = rgb_hex(10, 100, 225);
	rt->mlx = mlx_init();
	rt->window = mlx_new_window(rt->mlx, rt->width, rt->height, "miniRT");

	drawsphere(rt, sphere);
	Ray ray = {{0, 0, 0}, {1, 2, 3}};
	if (intersectRaySphere(ray, sphere, &t))
		mlx_pixel_put(rt->mlx, rt->window, rt->width / 2, rt->height / 2, 0x00FF00);
	mlx_hook(rt->window, X_EVENT_KEY_PRESS, 0, press_key, rt);
	mlx_hook(rt->window, X_EVENT_KEY_EXIT, 0, press_key, rt);
	mlx_loop(rt->mlx);
	return (0);
}

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
