/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_trigonometric.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohkang <soohkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 03:05:32 by nahyulee          #+#    #+#             */
/*   Updated: 2023/12/15 14:44:59 by soohkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

typedef struct s_pow
{
	double	base;
	double	value;
	int		exponent;
}	t_pow;

double	factorial(int n)
{
	double	result;
	int		i;

	i = 2;
	result = 1.0;
	while (i++ <= n)
		result *= i;
	return (result);
}

double	next_power(t_pow pow)
{
	pow.exponent++;
	pow.value *= pow.base;
	return (pow.value);
}

double	ft_sin(double x)
{
	double	result;
	int		i;
	double	term;
	t_pow	pow;

	result = 0.0;
	i = 0;
	pow.exponent = 0;
	while (i++ < 100)
	{
		pow.base = x;
		pow.value = 2 * i + 1;
		term = next_power(pow) / factorial(2 * i + 1);
		if (i % 2 == 0)
			result += term;
		else
			result -= term;
	}
	return (result);
}

double	ft_cos(double x)
{
	double	result;
	int		i;
	double	term;
	t_pow	pow;

	result = 0.0;
	i = 0;
	pow.exponent = 0;
	while (i++ < 100)
	{
		pow.base = x;
		pow.value = 2 * i;
		term = next_power(pow) / factorial(2 * i);
		if (i % 2 == 0)
			result += term;
		else
			result -= term;
	}
	return (result);
}

double	ft_tan(double x)
{
	return (ft_sin(x) / ft_cos(x));
}
