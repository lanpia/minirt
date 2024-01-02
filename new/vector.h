/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:25:10 by nahyulee          #+#    #+#             */
/*   Updated: 2023/12/30 17:41:25 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vector3d
{
	float	x;
	float	y;
	float	z;
}	t_vtr3;

typedef struct s_vector2d
{
	int	x;
	int	y;
}	t_vtr2;

/* ***********************vector********************************************* */
float	dot_product(t_vtr3 a, t_vtr3 b);
t_vtr3	cross_product(t_vtr3 a, t_vtr3 b);
t_vtr3	add_vector(t_vtr3 a, t_vtr3 b);
t_vtr3	subtract_vector(t_vtr3 a, t_vtr3 b);
t_vtr3	vtr3_length(t_vtr3 v);
t_vtr3	reflect_vector(t_vtr3 incident, t_vtr3 normal);
t_vtr3	normalize_vector(t_vtr3 v);
t_vtr3	add_val_vtr3(t_vtr3 v, float x, float y, float z);
t_vtr3	multiply_vector(t_vtr3 v, float x, float y, float z);
t_vtr3	divide_vector(t_vtr3 v, float x, float y, float z);

#endif