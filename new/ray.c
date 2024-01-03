/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:20:51 by nahyulee          #+#    #+#             */
/*   Updated: 2024/01/02 22:27:06 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	cam_lookat(t_c cam, t_vwpl view)
{
    // 카메라 방향 벡터 정규화
    t_vtr3 forward = normalize_vector(cam.dir);
    // 카메라 up 벡터 설정 (세계 좌표계에서의 위 방향)
    t_vtr3 up = (t_vtr3){0, 1, 0}; // Y 축이 위를 가리킴
    // right 벡터 계산 (forward 벡터와 up 벡터의 외적)
    t_vtr3 right = normalize_vector(cross_product(up, forward));
    // 뷰플레인의 중심 계산
    t_vtr3 view_center = add_vector(cam.position, multiply_vector(forward, view.distance, view.distance, view.distance));
    // 실제 up 벡터 계산 (forward 벡터와 right 벡터의 외적)
    up = cross_product(forward, right);
    // 뷰플레인의 너비와 높이 계산
    view.half_height = tan(cam.fov * 0.5 * (M_PI / 180.0));
    view.half_width = view.half_height * view.aspect_ratio;
    // 뷰플레인의 좌상단 모서리 계산
    t_vtr3 up_scaled = multiply_vector(up, view.half_height, view.half_height, view.half_height);
    t_vtr3 right_scaled = multiply_vector(right, view.half_width, view.half_width, view.half_width);
    view.left_top = subtract_vector(subtract_vector(view_center, right_scaled), up_scaled);
}

void	intersect(t_rt rt, t_d data)
{
	int	color;

	if (data.obj[plane] == true)
		color = intersect_plane(rt);
	else if (data.obj[sphere] == true)
		color = intersect_sphere(rt);
	else if (data.obj[cylinder] == true)
		color = intersect_cylinder(rt);
	
}

