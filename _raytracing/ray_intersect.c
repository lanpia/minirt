/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhyeon <suhyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 06:25:23 by suhyeon           #+#    #+#             */
/*   Updated: 2023/12/24 06:25:44 by suhyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

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
