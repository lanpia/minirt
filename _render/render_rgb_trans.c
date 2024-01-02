/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rgb_trans.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:43:42 by soohkang          #+#    #+#             */
/*   Updated: 2024/01/03 01:02:10 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

// unsigned int 형태의 RGB 색상을 t_color 구조체로 변환하는 함수
t_color	convert_int_to_color(unsigned int rgb_color)
{
	t_color	color;

	color.r = (float)((rgb_color >> 16) & 0xFF) / 255.0;
	color.g = (float)((rgb_color >> 8) & 0xFF) / 255.0;
	color.b = (float)(rgb_color & 0xFF) / 255.0;
	return (color);
}
