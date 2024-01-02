/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:44:20 by soohkang          #+#    #+#             */
/*   Updated: 2024/01/02 23:52:48 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

// 광선과 구의 교차 여부를 확인하고 교차 정보를 반환하는 함수
bool ray_intersect(t_ray *ray, t_rt *rt, t_intersec *intersection)
{
	t_intersec	temp_intersection;
	bool		hit;
	float		closest_distance;

	hit = false;
	closest_distance = INFINITY;
	// 구와의 교차 검사
	if (ray_intersect_sphere(ray, &rt->data.sphere, 
							&temp_intersection) 
							&& temp_intersection.distance < closest_distance)
	{
		closest_distance = temp_intersection.distance;
		*intersection = temp_intersection;
		hit = true;
	}

	// 평면과의 교차 검사
	if (ray_intersect_plane(ray, &rt->data.plane, 
								&temp_intersection) 
							&& temp_intersection.distance < closest_distance) 
	{
		closest_distance = temp_intersection.distance;
		*intersection = temp_intersection;
		hit = true;
	}

	// 원기둥과의 교차 검사
	if (ray_intersect_cylinder(ray, &rt->data.cylinder, 
									&temp_intersection) 
							&& temp_intersection.distance < closest_distance)
	{
		closest_distance = temp_intersection.distance;
		*intersection = temp_intersection;
		hit = true;
	}

	return (hit);
}

bool ray_intersect_sphere(t_ray *ray, t_sp *sphere, t_intersec *intersection)
{
	t_vtr3 oc = subtract_vector(ray->origin, sphere->center);
	float a = dot_product(ray->direction, ray->direction);
	float b = 2.0 * dot_product(oc, ray->direction);
	float c = dot_product(oc, oc) - sphere->radius * sphere->radius;
	float discriminant = b * b - 4 * a * c;

	if (discriminant < 0) {
		return false;
	}

	float sqrt_discriminant = sqrt(discriminant);
	float root = (-b - sqrt_discriminant) / (2.0 * a);

	if (root < 0) {
		root = (-b + sqrt_discriminant) / (2.0 * a);
		if (root < 0) {
			return false;
		}
	}

	intersection->distance = root;
	intersection->position = add_vector(ray->origin, 
										multiply_vector(ray->direction, 
										root));
	intersection->normal = subtract_vector(intersection->position, 
										sphere->center);
	intersection->normal = divide_vector(intersection->normal, 
												sphere->radius); // 정규화
	intersection->color = sphere->color;

	return (true);
}

bool	ray_intersect_plane(t_ray *ray, t_pl *plane, t_intersec *intersection)
{
	float denominator = dot_product(ray->direction, plane->orientation);

	if (fabs(denominator) > 1e-6) { // 평행이 아닌 경우
		t_vtr3 p0l0 = subtract_vector(plane->position, ray->origin);
		float t = dot_product(p0l0, plane->orientation) / denominator;

		if (t >= 0) {
			intersection->distance = t;
			intersection->position = add_vector(ray->origin, 
								multiply_vector(ray->direction, t));
			intersection->normal = plane->orientation;
			intersection->color = plane->color;

			return true;
		}
	}

	return (false);
}

bool ray_intersect_cylinder(t_ray *ray, t_cy *cylinder, 
													t_intersec *intersection)
{
	// 원기둥과의 교차 판별 로직 작성
	// 원기둥과의 교차 로직은 구현에 따라 복잡할 수 있으므로, 
	// 여기에는 기본적인 구조만 제공하고 상세한 구현은 생략합니다.
	
	// 예시 로직:
	// 1. 광선과 원기둥의 기준축 사이의 거리 계산
	// 2. 광선과 원기둥의 기준원 사이의 교차 계산
	// 3. 교차 거리 및 위치, 교차점에서의 법선 계산

	// 이 함수의 세부 구현은 프로젝트의 요구 사항 및 기하학적 계산에 따라 달라질 수 있습니다.

	return (false); // 임시 반환 값
}
