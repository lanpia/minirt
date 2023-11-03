/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 07:26:52 by nahyulee          #+#    #+#             */
/*   Updated: 2023/09/28 12:44:03 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	len;

	len = ft_strlen(s1);
	dest = (char *)ft_calloc(sizeof(char), len + 1);
	if (dest == 0)
		return (0);
	ft_memcpy(dest, s1, len);
	dest[len] = '\0';
	return (dest);
}
