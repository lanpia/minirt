/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 02:39:22 by nahyulee          #+#    #+#             */
/*   Updated: 2023/03/14 02:39:24 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_wordlen(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static int	ft_wordcount(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		count;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	count = ft_wordcount(s, c);
	arr = (char **)ft_calloc(sizeof(char *), (count + 1));
	if (!arr)
		return (NULL);
	arr[count] = NULL;
	i = -1;
	while (++i < count)
	{
		while (*s && *s == c)
			s++;
		len = ft_wordlen(s, c);
		arr[i] = ft_substr(s, 0, len);
		if (!arr[i])
			return (ft_2d_arr_free(arr, i));
		s += len;
	}
	return (arr);
}
