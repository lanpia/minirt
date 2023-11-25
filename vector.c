/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 03:28:03 by nahyulee          #+#    #+#             */
/*   Updated: 2023/11/25 21:30:10 by nahyulee         ###   ########.fr       */
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
