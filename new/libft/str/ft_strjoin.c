/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 07:32:57 by nahyulee          #+#    #+#             */
/*   Updated: 2023/03/15 07:33:00 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s_len1;
	size_t	s_len2;
	char	*result;

	s_len1 = ft_strlen(s1);
	s_len2 = ft_strlen(s2);
	result = (char *)ft_calloc(sizeof(char), (s_len1 + s_len2 + 1));
	if (!result)
		return (NULL);
	ft_memcpy(result, s1, s_len1);
	ft_memcpy(result + s_len1, s2, s_len2 + 1);
	return (result);
}

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	size_t	s_len;
// 	char	*result;

// 	s_len = ft_strlen(s1) + ft_strlen(s2);
// 	result = (char *)malloc(sizeof(char) * (s_len + 1));
// 	if (!result)
// 		return (NULL);
// 	s_len = 0;
// 	while (*s1)
// 	{
// 		*(result + s_len) = *s1;
// 		s_len++;
// 		s1++;
// 	}
// 	while (*s2)
// 	{
// 		*(result + s_len) = *s2;
// 		s_len++;
// 		s2++;
// 	}
// 	*(result + s_len) = '\0';
// 	return (result);
// }