/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_normalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhyeon <suhyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:12:59 by suhyeon           #+#    #+#             */
/*   Updated: 2023/12/23 17:14:23 by suhyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_vtr3	normalize_vector(t_vtr3 v)
{
	double	length;

	length = sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
	v.x /= length;
	v.y /= length;
	v.z /= length;
	return (v);
}