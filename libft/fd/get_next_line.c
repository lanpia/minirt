/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 00:26:33 by nahyulee          #+#    #+#             */
/*   Updated: 2023/08/29 12:53:13 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*no_read_or_error(char *result, int buflen)
{
	if (*result == '\0' || buflen <= -1)
	{
		free((void *)result);
		result = NULL;
	}
	return (result);
}

static char	*get_next_line_internal(int fd)
{
	char			*result;
	static char		buf[BUFFER_SIZE + 1];
	int				buflen;
	char			*temp;

	result = ft_strdup(buf);
	while (ft_strchr(result, '\n') == 0)
	{
		ft_memset(buf, 0, BUFFER_SIZE + 1);
		buflen = read(fd, buf, BUFFER_SIZE);
		if (buflen <= 0)
			break ;
		buf[buflen] = '\0';
		temp = ft_strjoin(result, buf);
		free(result);
		result = temp;
	}
	if (ft_strchr(result, '\n'))
	{
		*(ft_strchr(result, '\n') + 1) = '\0';
		buflen = ft_strchr(buf, '\0') - ft_strchr(buf, '\n');
		ft_memmove(buf, ft_strchr(buf, '\n') + 1, buflen);
	}
	result = no_read_or_error(result, buflen);
	return (result);
}

char	*get_next_line(int fd)
{
	if (BUFFER_SIZE <= 0 || fd < 0 || fd == 1 || fd == 2)
		return (NULL);
	return (get_next_line_internal(fd));
}
