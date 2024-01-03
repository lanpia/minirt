/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 01:25:50 by nahyulee          #+#    #+#             */
/*   Updated: 2024/01/03 06:38:28 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

bool	ft_compare_int(int check, int min, int max)
{
	if (check <= max && check >= min)
		return (true);
	return (false);
}

bool	ft_compare_float(float check, float min, float max)
{
	if (check <= max && check >= min)
		return (true);
	return (false);
}

bool	ft_compare_double(double check, double min, double max)
{
	if (check <= max && check >= min)
		return (true);
	return (false);
}
