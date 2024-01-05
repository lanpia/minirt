/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:44:20 by soohkang          #+#    #+#             */
/*   Updated: 2024/01/05 03:47:20 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_intr	intersect_plane(t_pl plane, t_ray ray)
{
	t_intr	intr;
	t_vtr3	p0l0;
	float	demo;

	demo = dot_product(ray.dir, plane.orientation);
	p0l0 = subtract_vector(plane.position, ray.origin);
	if (fabs(demo) > 1e-6)
	{
		intr.t = dot_product(p0l0, plane.orientation) / demo;
		if (intr.t >= 0)
		{
			intr.hit = add_vector(ray.origin, \
									multiply_vector(ray.dir, \
									intr.t, intr.t, intr.t));
			intr.normal = plane.orientation;
			intr.color[red] = plane.color[red];
			intr.color[green] = plane.color[green];
			intr.color[blue] = plane.color[blue];
		}
	}
	// printf("intr %x, plane %x\n", rgb_hex(intr.color[0], intr.color[1], intr.color[2]), rgb_hex(plane.color[0], plane.color[1], plane.color[2]));
	return (intr);
}

// t_intr	intersect_sphere(t_sp sp, t_ray ray)
// {
// 	t_intr	intr;
// 	t_vtr3	oc;
// 	double	a;
// 	double	b;
// 	double	c;

// 	oc = subtract_vector(ray.origin, sp.center);
// 	a = dot_product(ray.dir, ray.dir);
// 	b = 2.0 * dot_product(oc, ray.dir);
// 	c = dot_product(oc, oc) - sp.radius * sp.radius;
// 	if ((b * b - 4 * a * c) < 0)
// 		return (NULL);
// 	intr.t = (-b - sqrt(b * b - 4 * a * c)) / (2.0 * a);
// 	if (intr.t < 0)
// 		intr.t = (-b + sqrt(b * b - 4 * a * c)) / (2.0 * a);
// 	if (intr.t < 0)
// 		return (NULL);
// 	intr.hit = add_vector(ray.origin, 
// 					multiply_vector(ray.dir, 
// 					intr.t, intr.t, intr.t));
// 	intr.normal = normalize_vector(subtract_vector(intr.hit, sp.center));
// 	*intr.color = *sp.color;
// 	return (intr);
// }

// // 광선과 구의 교차 여부를 확인하고 교차 정보를 반환하는 함수
// bool ray_intersect(t_ray *ray, t_rt *rt, t_intersec *intr)
// {
// 	t_intersec	temp_intr;
// 	bool		hit;
// 	float		closest_t;

// 	hit = false;
// 	closest_t = INFINITY;
// 	// 구와의 교차 검사
// 	if (ray_intersect_sphere(ray, &rt->data.sphere, 
// 							&temp_intr) 
// 							&& temp_intr.t < closest_t)
// 	{
// 		closest_t = temp_intr.t;
// 		*intr = temp_intr;
// 		hit = true;
// 	}

// 	// 평면과의 교차 검사
// 	if (ray_intersect_plane(ray, &rt->data.plane, 
// 								&temp_intr) 
// 							&& temp_intr.distance < closest_distance) 
// 	{
// 		closest_distance = temp_intr.distance;
// 		*intr = temp_intr;
// 		hit = true;
// 	}

// 	// 원기둥과의 교차 검사
// 	if (ray_intersect_cylinder(ray, &rt->data.cylinder, 
// 									&temp_intr) 
// 							&& temp_intr.distance < closest_distance)
// 	{
// 		closest_distance = temp_intr.distance;
// 		*intr = temp_intr;
// 		hit = true;
// 	}

// 	return (hit);
// }

// bool ray_intersect_sphere(t_ray *ray, t_sp *sphere, t_intersec *intr)
// {
// 	t_vtr3 oc = subtract_vector(ray->origin, sphere->center);
// 	float a = dot_product(ray->direction, ray->direction);
// 	float b = 2.0 * dot_product(oc, ray->direction);
// 	float c = dot_product(oc, oc) - sphere->radius * sphere->radius;
// 	float discriminant = b * b - 4 * a * c;

// 	if (discriminant < 0) {
// 		return false;
// 	}

// 	float sqrt_discriminant = sqrt(discriminant);
// 	float root = (-b - sqrt_discriminant) / (2.0 * a);

// 	if (root < 0) {
// 		root = (-b + sqrt_discriminant) / (2.0 * a);
// 		if (root < 0) {
// 			return false;
// 		}
// 	}

// 	intr->distance = root;
// 	intr->position = add_vector(ray->origin, 
// 										multiply_vector(ray->direction, 
// 										root));
// 	intr->normal = subtract_vector(intr->position, 
// 										sphere->center);
// 	intr->normal = divide_vector(intr->normal, 
// 												sphere->radius); // 정규화
// 	intr->color = sphere->color;

// 	return (true);
// }

// bool	ray_intersect_plane(t_ray *ray, t_pl *plane, t_intersec *intr)
// {
// 	float demo = dot_product(ray->direction, plane->orientation);

// 	if (fabs(demo) > 1e-6) { // 평행이 아닌 경우
// 		t_vtr3 p0l0 = subtract_vector(plane->position, ray->origin);
// 		float t = dot_product(p0l0, plane->orientation) / demo;

// 		if (t >= 0) {
// 			intr->distance = t;
// 			intr->position = add_vector(ray->origin, 
// 								multiply_vector(ray->direction, t));
// 			intr->normal = plane->orientation;
// 			intr->color = plane->color;

// 			return true;
// 		}
// 	}

// 	return (false);
// }

// bool ray_intersect_cylinder(t_ray *ray, t_cy *cylinder, 
// 													t_intersec *intr)
// {
// 	// 원기둥과의 교차 판별 로직 작성
// 	// 원기둥과의 교차 로직은 구현에 따라 복잡할 수 있으므로, 
// 	// 여기에는 기본적인 구조만 제공하고 상세한 구현은 생략합니다.
	
// 	// 예시 로직:
// 	// 1. 광선과 원기둥의 기준축 사이의 거리 계산
// 	// 2. 광선과 원기둥의 기준원 사이의 교차 계산
// 	// 3. 교차 거리 및 위치, 교차점에서의 법선 계산

// 	// 이 함수의 세부 구현은 프로젝트의 요구 사항 및 기하학적 계산에 따라 달라질 수 있습니다.

// 	return (false); // 임시 반환 값
// }
