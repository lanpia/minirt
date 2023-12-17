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
	// 고정값 sphere
	sphere(rt, rt->data.sphere);
	
	// plane 그리기
	// render_plane(rt, rt ->data.);
	
	// 타원 그리기
	// render_ellipsoid(rt, rt->data.ellipsoid);
	
	// 원기둥 그리기
	// render_cylinder(rt, rt->data.cylinder);
	
}
