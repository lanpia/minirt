/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_scalar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 01:25:16 by nahyulee          #+#    #+#             */
/*   Updated: 2023/12/19 23:56:33 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_vtr3	reflect_vector(t_vtr3 incident, t_vtr3 normal)
{
	double	dot;
	t_vtr3	scaled_normal;
	t_vtr3	reflect;

	dot = dot_product(incident, normal);
	scaled_normal = multiply_vector(normal, 2 * dot, 2 * dot, 2 * dot);
	reflect = subtract_vector(incident, scaled_normal);
	return (reflect);
}

t_vtr3	normalize_vector(t_vtr3 v)
{
	t_vtr3	result;
	float	len;

	if (isnanf(v.x))
		v.x = 0;
	if (isnanf(v.y))
		v.y = 0;
	if (isnanf(v.z))
		v.z = 0;
	len = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	result.x = v.x / len;
	result.y = v.y / len;
	result.z = v.z / len;
	return (result);
}

t_vtr3	add_val_vtr3(t_vtr3 v, float x, float y, float z)
{
	t_vtr3	result;

	result.x = v.x + x;
	result.y = v.y + y;
	result.z = v.z + z;
	return (result);
}

t_vtr3	multiply_vector(t_vtr3 v, float x, float y, float z)
{
	t_vtr3	result;

	result.x = v.x * x;
	result.y = v.y * y;
	result.z = v.z * z;
	return (result);
}

t_vtr3	divide_vector(t_vtr3 v, float x, float y, float z)
{
	t_vtr3	result;

	if (x == 0 || y == 0 || z == 0)
	{
		write(1, "Error: Division by zero.\n", 25);
		return (v);
	}
	result.x = v.x / x;
	result.y = v.y / y;
	result.z = v.z / z;
	return (result);
}
