/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 00:36:40 by nahyulee          #+#    #+#             */
/*   Updated: 2023/05/19 17:55:12 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	**ft_split_bonus(char *str, char *charset);

int	ft_len(char *str, char *charset)
{
	int	len;

	len = 0;
	while (*(str + len) && !ft_strchr((const char *)charset, *(str + len)))
		len++;
	return (len);
}

int	ft_word(char *str, char *charset)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (!ft_strchr(charset, str[i]) && str[i])
		{
			count++;
			while (!ft_strchr((const char *)charset, str[i]) && str[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	*ft_strndup(char *str, int len, char *charset)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(len + 1);
	while (str[i] && !ft_strchr((const char *)charset, str[i]))
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split_bonus(char *str, char *charset)
{
	int		len;
	int		count;
	int		i;
	char	**arr;

	i = -1;
	if (!str)
		return (NULL);
	len = ft_word(str, charset);
	arr = (char **)ft_calloc(sizeof(char *), (len + 1));
	if (!arr)
		return (NULL);
	arr[len] = NULL;
	while (++i < len)
	{
		while (*str && ft_strchr((const char *)charset, *str))
			str++;
		count = ft_len(str, charset);
		arr[i] = ft_strndup(str, count, charset);
		if (!arr[i])
			return (ft_2d_arr_free(arr, i));
		str += count;
	}
	return (arr);
}
