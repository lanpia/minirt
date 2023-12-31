/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 01:25:16 by nahyulee          #+#    #+#             */
/*   Updated: 2024/01/08 16:16:23 by nahyulee         ###   ########.fr       */
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

int	ft_isnanf(float x)
{
	return (x != x);
}

t_vtr3	normalize_vector(t_vtr3 v)
{
	float	len;

	if (ft_isnanf(v.x))
		v.x = 0;
	if (ft_isnanf(v.y))
		v.y = 0;
	if (ft_isnanf(v.z))
		v.z = 0;
	len = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	if (len == 0)
		len = 1;
	return (divide_vector(v, len, len, len));
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

bool	avilable_vtr3_value(t_vtr3 v, int start, int end)
{
	if (ft_compare_int(v.x, start, end) == false || \
		ft_compare_int(v.y, start, end) == false || \
		ft_compare_int(v.z, start, end) == false)
		return (false);
	return (true);
}
