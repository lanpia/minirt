/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rgb_trans.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohkang <soohkang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:59:34 by soohkang           #+#    #+#             */
/*   Updated: 2023/12/23 17:00:02 by soohkang          ###   ########.fr       */
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

unsigned int convert_color_to_int(t_color color)
{
	int r = (int)(color.r * 255.0);
	int g = (int)(color.g * 255.0);
	int b = (int)(color.b * 255.0);

	return (r << 16) | (g << 8) | b;
}
