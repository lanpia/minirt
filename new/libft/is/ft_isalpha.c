/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 22:41:32 by nahyulee          #+#    #+#             */
/*   Updated: 2023/05/19 17:55:12 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	is_lower(int x)
{
	return (x >= 'a' && x <= 'z');
}

static char	is_upper(int x)
{
	return (x >= 'A' && x <= 'Z');
}

int	ft_isalpha(int c)
{
	if (is_lower(c) || is_upper(c))
		return (1);
	return (0);
}
