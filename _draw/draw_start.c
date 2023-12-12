/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohkang <soohkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:00:18 by nahyulee          #+#    #+#             */
/*   Updated: 2023/12/10 16:57:53 by soohkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	draw_start(t_rt *rt)
{
	// 고정값 sphere
	sphere(rt, rt->data.sphere);
	
	// 타원 그리기
	// draw_ellipsoid(rt, rt->data.ellipsoid);
	
	// 원기둥 그리기
	// draw_cylinder(rt, rt->data.cylinder);
	
	// draw_plane(rt, rt ->data.);
}
