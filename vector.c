/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3dvector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 03:28:03 by nahyulee          #+#    #+#             */
/*   Updated: 2023/11/22 02:23:50 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_2d	project3dto2d(t_rt *rt, t_vtr3 point3d, t_2d point2d)
{
	point2d.x = (int)(rt->width / 2 + point3d.x);
	point2d.y = (int)(rt->height / 2 - point3d.y);
	return (point2d);
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

t_vtr3	multiply_vector(t_vtr3 v, float scalar)
{
	t_vtr3	result;

	result.x = v.x * scalar;
	result.y = v.y * scalar;
	result.z = v.z * scalar;
	return (result);
}

t_vtr3	divide_vector(t_vtr3 v, float scalar)
{
	t_vtr3	result;

	if (scalar == 0)
	{
		write(1, "Error: Division by zero.\n", 25);
		return (v);
	}
	result.x = v.x / scalar;
	result.y = v.y / scalar;
	result.z = v.z / scalar;
	return (result);
}
