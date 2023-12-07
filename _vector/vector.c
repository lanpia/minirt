/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 03:28:03 by nahyulee          #+#    #+#             */
/*   Updated: 2023/12/07 16:18:14 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	dot_product(t_vtr3 a, t_vtr3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vtr3	cross_product(t_vtr3 a, t_vtr3 b)
{
	t_vtr3	result;

	result.x = a.y * b.z - a.z * b.y;
	result.y = a.z * b.x - a.x * b.z;
	result.z = a.x * b.y - a.y * b.x;
	return (result);
}

t_vtr3	add_vector(t_vtr3 a, t_vtr3 b)
{
	t_vtr3	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	return (result);
}

t_vtr3	subtract_vector(t_vtr3 a, t_vtr3 b)
{
	t_vtr3	result;

	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
	return (result);
}

t_vtr3	vtr3_length(t_vtr3 v)
{
	t_vtr3	result;
	float	len;

	len = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	result.x = v.x / len;
	result.y = v.y / len;
	result.z = v.z / len;
	return (result);
}
