/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 02:08:22 by nahyulee          #+#    #+#             */
/*   Updated: 2023/05/19 17:55:12 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*s;
	unsigned char		*d;
	size_t				i;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	i = 0;
	if (d == 0 && s == 0)
		return (0);
	if (d < s)
		ft_memcpy(d, s, len);
	else
	{
		while (len > i)
		{
			d[len - i - 1] = s[len - i - 1];
			i++;
		}
	}
	return ((void *)d);
}
