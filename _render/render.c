/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_render.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohkang <soohkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:00:18 by nahyulee          #+#    #+#             */
/*   Updated: 2023/12/16 23:41:08 by soohkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	render_scene(t_rt *rt)
{
	int		y;
	int		x;
	t_ray	ray;
	t_color	color;

	y = 0;
	while (y < rt->height)
	{
		x = 0;
		while (x < rt->width)
		{
			// 각 픽셀에 대한 광선 생성
			ray = generate_ray(rt, x, y);
			// 광선과 기하학적 객체의 교차 계산
			color = trace_ray(&ray, rt);
			// 계산된 색상을 이미지 버퍼에 저장
			set_pixel_color(rt, x, y, color);
			x++;
		}
		y++;
	}
}

// unsigned int 형태의 RGB 색상을 t_color 구조체로 변환하는 함수
t_color	convert_int_to_color(unsigned int rgb_color)
{
	t_color	color;

	color.r = (float)((rgb_color >> 16) & 0xFF) / 255.0;
	color.g = (float)((rgb_color >> 8) & 0xFF) / 255.0;
	color.b = (float)(rgb_color & 0xFF) / 255.0;
	return (color);
}

unsigned int convert_color_to_int(t_color color)
{
	int r = (int)(color.r * 255.0);
	int g = (int)(color.g * 255.0);
	int b = (int)(color.b * 255.0);

	return (r << 16) | (g << 8) | b;
}

// 광선과 구의 교차 여부를 확인하고 교차 정보를 반환하는 함수
bool	intersect_sphere(t_ray *ray, t_sp *sphere, t_intersec *intersection)
{
	t_vtr3	oc;
	float	a;
	float	b;
	float	c;
	(void) intersection;

	oc = subtract_vector(ray->origin, sphere->center);
	a = dot_product(ray->direction, ray->direction);
	b = (2.0 * dot_product(oc, ray->direction));
	c = dot_product(oc, oc) - (sphere->radius * sphere->radius);
	return (1);
}

// 장면에 있는 각 객체와 광선의 교차를 확인하고 가장 가까운 교차점을 찾는 함수
t_color trace_ray(t_ray *ray, t_rt *rt)
{
	t_color		color;
	float		closest_distance;
	t_intersec	nearest_intersection;
	bool		hit;

	closest_distance = INFINITY;
	hit = false;
	// 초기화
	color = (t_color){0, 0, 0}; // 기본 색상을 검은색으로 설정
	nearest_intersection = (t_intersec){0}; // 교차 정보 초기화

	// 여기에서 각 기하학적 객체(예: 구, 평면 등)와 광선의 교차를 검사
	// 예를 들어, 구와 광선의 교차:
	if (intersect_sphere(ray, &rt->data.sphere, &nearest_intersection) 
					&& nearest_intersection.distance < closest_distance)
	{
		closest_distance = nearest_intersection.distance;
		// 구와 교차한 경우, 구의 색상을 사용
		color = convert_int_to_color(rt->data.sphere.color);
		hit = true;
	}

	// 여기에 다른 기하학적 객체에 대한 교차 검사 코드를 추가할 수 있습니다.

	// 광선이 어떤 객체와도 교차하지 않은 경우, 기본 배경색을 반환합니다.
	if (!hit)
	{
		// 교차하지 않은 경우, 흰색 배경 사용
		color = (t_color){255, 255, 255};
	}

	return color;
}

t_vtr3	nomalize_vector(t_vtr3 v)
{
	double	length;

	length = sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
	v.x /= length;
	v.y /= length;
	v.z /= length;
	return (v);
}

// 카메라에서 화면으로 광선을 생성하는 기능
t_ray	generate_ray(t_rt *rt, int x, int y)
{
	t_ray	ray;
	double	aspect_ratio; // 화면의 가로 세로 비율 계산
	double	fov; // 카메라의 시야각을 라디안 단위로 변환
	double	scale; // 시야각의 절반을 이용하여 화면의 스케일을 계산
	double	screen_x; // 화면상의 x, y 픽셀 좌표를 정규화된 화면 공간의 좌표 -1 ~ 1로 변환
	double	screen_y;

	// 화면의 가로 세로 비율 계산
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
	ray.direction.z = -1; // 화면은 카메라 앞에 위치
	ray.direction = nomalize_vector(ray.direction); // 3차원 벡터를 정규화

	// 광선의 시작점은 카메라의 위치
	ray.origin = rt->data.camera.cam;
	return (ray);
}

// 이미지 버퍼에 픽셀 색상을 설정하는 함수
void set_pixel_color(t_rt *rt, int x, int y, t_color color)
{
	char	*dst; // 이미지 데이터에 접근하기위한 포인터
	int		color_value; // 정수 형태의 색상 값

	// t_color 구조체를 정수형 색상 값으로 변환
	// 색상 처널 (R, G, B)의 값을 하나의 정수로 결합
	color_value = convert_color_to_int(color);
	// 이미지 버퍼의 주소를 얻고, 각 픽셀에 대한 정보를 설정
	dst = mlx_get_data_addr(rt->img_buffer
		, &rt->bits_per_pixel 
		, &rt->line_length, &rt->endian);
	*(unsigned int*)(dst + y * rt->line_length 
						 + x * (rt->bits_per_pixel / 8)) 
						 = mlx_get_color_value(rt->mlx, color_value);
}
