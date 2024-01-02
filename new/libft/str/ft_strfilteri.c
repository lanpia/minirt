/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfilteri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:58:01 by nahyulee          #+#    #+#             */
/*   Updated: 2023/10/08 14:47:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strfilteri(char const *s, int (*f)(unsigned int, char))
{
	char	*filtered_str;
	int		i;
	int		j;

	if (!s || !f)
		return (NULL);
	filtered_str = (char *)ft_calloc(sizeof(char), (ft_strlen(s) + 1));
	if (!filtered_str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (f(i, s[i]))
		{
			filtered_str[j] = s[i];
			j++;
		}
		i++;
	}
	filtered_str[j] = '\0';
	return (filtered_str);
}
