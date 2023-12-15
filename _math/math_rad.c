/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_rad.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohkang <soohkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:42:16 by soohkang          #+#    #+#             */
/*   Updated: 2023/12/15 03:38:15 by soohkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

float degree_to_radian(float degree)
{
	float PI = 3.14;
	float rad;

	rad = degree * (PI / 180);
	return (rad);
}
