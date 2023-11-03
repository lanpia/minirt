/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 02:18:09 by nahyulee          #+#    #+#             */
/*   Updated: 2023/08/31 17:19:52 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strtok(char *str, const char *delim)
{
	static char	*last;
	char		*token;

	if (str != NULL)
		last = str;
	if (last == NULL || *last == '\0')
		return (NULL);
	token = last;
	while (*last != '\0')
	{
		if (ft_strchr(delim, *last) != NULL)
		{
			*last = '\0';
			last++;
			break ;
		}
		last++;
	}
	return (token);
}
