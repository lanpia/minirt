/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 00:37:38 by nahyulee          #+#    #+#             */
/*   Updated: 2023/10/02 00:46:54 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*arr1;
	unsigned char	*arr2;

	i = 0;
	arr1 = (unsigned char *)s1;
	arr2 = (unsigned char *)s2;
	while (arr1[i] || arr2[i])
	{
		if (arr1[i] != arr2[i])
			return (arr1[i] - arr2[i]);
		i++;
	}
	return (0);
}

// int	ft_strcmp(const char *s1, const char *s2)
// {
// 	while (*s1 || *s2)
// 	{
// 		if (*s1 != *s2)
// 			return (*s1 - *s2);
// 		else
// 		{
// 			s1++;
// 			s2++;
// 		}
// 	}
// 	return (0);
// }
