/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 03:18:48 by nahyulee          #+#    #+#             */
/*   Updated: 2023/03/14 03:18:50 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*result;

	i = 0;
	len = ft_strlen(s);
	result = (char *)ft_calloc(sizeof(char), len + 1);
	if (!result)
		return (NULL);
	while (*(s + i))
	{
		result[i] = (*f)(i, (char)*(s + i));
		i++;
	}
	result[i] = '\0';
	return (result);
}
