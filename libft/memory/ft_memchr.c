/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 03:27:37 by nahyulee          #+#    #+#             */
/*   Updated: 2023/05/19 17:55:12 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	unsigned char		v;
	size_t				i;

	p = (const unsigned char *)s;
	v = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*(p + i) == v)
			return ((void *)(p + i));
		i++;
	}
	return (NULL);
}
