/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:25:10 by nahyulee          #+#    #+#             */
/*   Updated: 2024/01/08 16:16:23 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>

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
bool	avilable_vtr3_value(t_vtr3 v, int start, int end);

#endif
