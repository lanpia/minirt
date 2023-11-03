/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2d_arr_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:53:02 by nahyulee          #+#    #+#             */
/*   Updated: 2023/09/27 05:08:10 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	**ft_2d_arr_free(char **arr, int len)
{
	if (!arr)
		return (NULL);
	while (len-- > 0)
		if (arr[len] != NULL)
			free(arr[len]);
	free(arr);
	return (NULL);
}
