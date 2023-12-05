/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_scalar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 01:25:16 by nahyulee          #+#    #+#             */
/*   Updated: 2023/11/26 05:11:10 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
