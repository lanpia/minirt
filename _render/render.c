/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:44:25 by soohkang          #+#    #+#             */
/*   Updated: 2024/01/03 03:33:12 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

// 화면, 3D 렌더링에서 일반적으로 사용되는 뷰포트를 의미
// 뷰포트는 3D 장면을 2D 이미지로 변환할 때 사용되는 화면 영역
// 실제로 렌더링되는 2D 이미지의 크기와 위치를 결정
void	render_scene(t_rt *rt)
{
	int		y;
	int		x;
	t_ray	ray;
	t_color	color;

	y = 0;
	// 화면(뷰포트)의 높이 순회
	while (y < rt->height)
	{
		x = 0;
		// 화면의 너비 순회
		while (x < rt->width)
		{
			// 현재 픽셀에 대한 광선 생성
			ray = generate_ray(rt, x, y);
			// 광선과 기하학적 객체의 교차 계산 및 색상 계산
			color = trace_ray(&ray, rt);
			// 계산된 색상을 이미지 버퍼에 저장
			set_pixel_color(rt, x, y, color);
			x++;
		}
		y++;
	}
}

// 카메라에서 화면으로 광선을 생성하는 기능
t_ray	generate_ray(t_rt *rt, int x, int y)
{
	t_ray	ray;
	// 화면의 '가로', '세로' 비율 계산
	double	aspect_ratio;
	// '카메라의 시야각'을 라디안 단위로 변환
	double	fov;
	// 시야각의 절반을 이용하여 화면의 스케일을 계산
	double	scale;
	// 화면상의 x, y 픽셀 좌표를 정규화된 화면 공간의 좌표 -1 ~ 1로 변환
	double	screen_x;
	double	screen_y;

	// 화면의 가로, 세로 비율 계산
	aspect_ratio = (double)rt->width / (double)rt->height;
	// 카메라의 시야각을 라디안 단위로 변환
	fov = degree_to_radian(rt->data.camera.fov);
	// 시야각의 절반을 이용하여 화면의 스케일을 계산
	scale = tan(fov / 2.0);
	// 화면상의 (x, y) 위치를 -1, 1 사이의 값으로 변환
	screen_x = (2 * (x + 0.5) / (double)rt->width - 1) * aspect_ratio * scale;
	screen_y = (1 - 2 * (y + 0.5) / (double)rt->height) * scale;
	
	// 광선의 방향 설정
	ray.direction.x = screen_x;
	ray.direction.y = screen_y;
	// 화면은 카메라 앞에 위치
	ray.direction.z = -1;
	// 3차원 벡터를 정규화
	ray.direction = normalize_vector(ray.direction);
	// 광선의 시작점은 카메라의 위치
	ray.origin = rt->data.camera.cam;
	return (ray);
}

// 장면에 있는 각 객체와 광선의 교차를 확인하고 가장 가까운 교차점을 찾는 함수
t_color trace_ray(t_ray *ray, t_rt *rt)
{
	t_color		color;
	t_intersec	nearest_intersection;
	bool		hit;

	hit = ray_intersect(ray, rt, &nearest_intersection);
	if (hit)
	{
		// 교차한 객체의 색상 반환
		return convert_int_to_color(nearest_intersection.color);
	}
	else
		return (t_color){255, 255, 255}; // 교차하지 않은 경우, 흰색 배경 사용
}


// 이미지 버퍼에 픽셀 색상을 설정하는 함수
void	set_pixel_color(t_rt *rt, int x, int y, t_color color)
{
	char	*dst; // 이미지 데이터에 접근하기위한 포인터
	int		color_value; // 정수 형태의 색상 값

	// t_color 구조체를 정수형 색상 값으로 변환
	// 색상 처널 (R, G, B)의 값을 하나의 정수로 결합
	color_value = rgb_hex(color.r, color.g, color.b);
	// 이미지 버퍼의 주소를 얻고, 각 픽셀에 대한 정보를 설정
	dst = mlx_get_data_addr(rt->img_buffer
		, &rt->bits_per_pixel 
		, &rt->line_length, &rt->endian);
	*(unsigned int*)(dst + y * rt->line_length + x * (rt->bits_per_pixel / 8)) 
					= mlx_get_color_value(rt->mlx, color_value);
}

unsigned int	rgb_hex(int red, int green, int blue)
{
	unsigned int	color;

	color = (red << 16) | (green << 8) | blue;
	return (color);
}

void	my_mlx_pixel_put(t_mlx mlx, int x, int y, int color)
{
	char	*pixel;

	if (0 <= x && x < mlx.width && 0 <= y && y < mlx.height)
	{
		pixel = mlx.addr + (y * mlx.size_line + x * 4);
		*(int *)pixel = color;
	}
}

double	degree_to_radian(float degree)
{
	double	rad;

	rad = degree * (M_PI / 180.0);
	return (rad);
}
