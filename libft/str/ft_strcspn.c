/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 02:54:05 by nahyulee          #+#    #+#             */
/*   Updated: 2023/05/24 15:19:56 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strcspn(const char *str, const char *reject)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (ft_strchr(reject, str[i]) != NULL)
			return (i);
		i++;
	}
	return (i);
}
