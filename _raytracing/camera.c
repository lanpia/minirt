/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohkang <soohkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 01:25:16 by nahyulee          #+#    #+#             */
/*   Updated: 2023/12/10 01:30:25 by soohkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

// 뷰포트 생성
// t_c	create_viewport()
// {
	
// }

// 중앙을 기준으로 뷰포트의 x, y 좌표를 계산
void	turn_on_camera(t_rt *rt)
{
	(void)rt;
	
}

void	move_camera(t_c camera, int x, int y, int z)
{
	camera.cam.x += x;
	camera.cam.y += y;
	camera.cam.z += z;
}
