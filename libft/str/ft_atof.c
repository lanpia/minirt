/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohkang <soohkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:22:06 by nahyulee          #+#    #+#             */
/*   Updated: 2023/12/04 00:51:34 by soohkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void check_sign(const char **str, int *sign)
{
	while (ft_isspace(**str))
		(*str)++;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			*sign = -1;
		(*str)++;
	}
}

double	ft_atof(const char *str)
{
	double	result;
	int		sign;
	int		decimal;

	result = 0.0;
	sign = 1;
	decimal = 0;
	check_sign(&str, &sign);
	while (ft_isdigit(*str))
	{
		result = result * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
		str++;
	while (ft_isdigit(*str))
	{
		result = result * 10.0 + (*str - '0');
		str++;
		decimal++;
	}
	while (decimal-- > 0)
		result *= 0.1;
	return (sign * result);
}

