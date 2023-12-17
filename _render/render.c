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

void	trace_ray(t_ray *ray, t_rt *rt)
{
	// 원기둥 그리기
	// render_cylinder(rt, rt->data.cylinder);
	
	// 구체 sphere
	sphere(rt, rt->data.sphere);
	
	// plane 그리기
	// render_plane(rt, rt ->data.);
	
	// 타원 그리기
	// render_ellipsoid(rt, rt->data.ellipsoid);
}

void generate_ray(t_rt *rt, int x, int y)
{
	
}

void set_pixel_color(t_rt *rt_img, int x, int y, int color)
{

}

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
			color = trace_ray(ray, rt);

			// 계산된 색상을 이미지 버퍼에 저장
			set_pixel_color(rt->image, x, y, color);

			x++;
		}
		y++;
	}
	render_geometric_objects(rt);
}
