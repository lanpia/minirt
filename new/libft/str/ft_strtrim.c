/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:39:33 by nahyulee          #+#    #+#             */
/*   Updated: 2023/03/15 09:39:35 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;

	if (!*s1)
		return (ft_strdup(""));
	start = (char *)s1;
	if (*start)
		while (*start && ft_strchr(set, *start))
			start++;
	end = (char *)s1 + ft_strlen(s1) - 1;
	if (*end)
		while (ft_strchr(set, *end))
			end--;
	return (ft_substr(s1, start - s1, end - start + 1));
}
