/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 00:31:04 by nahyulee          #+#    #+#             */
/*   Updated: 2023/08/29 13:05:56 by nahyulee         ###   ########.fr       */
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
	int				buflen;	
	char			*result;
	static char		buf[65535][BUFFER_SIZE + 1];
	char			*temp;

	result = ft_strdup(buf[fd]);
	while (ft_strchr(result, '\n') == 0)
	{
		ft_memset(buf[fd], 0, BUFFER_SIZE + 1);
		buflen = read(fd, buf[fd], BUFFER_SIZE);
		if (buflen <= 0)
			break ;
		buf[fd][buflen] = '\0';
		temp = ft_strjoin(result, buf[fd]);
		free(result);
		result = temp;
	}
	if (ft_strchr(result, '\n'))
	{
		*(ft_strchr(result, '\n') + 1) = '\0';
		buflen = ft_strchr(buf[fd], '\0') - ft_strchr(buf[fd], '\n');
		ft_memmove(buf[fd], ft_strchr(buf[fd], '\n') + 1, buflen);
	}
	result = no_read_or_error(result, buflen);
	return (result);
}

char	*get_next_line_bonus(int fd)
{
	if (BUFFER_SIZE <= 0 || fd < 0 || fd == 1 || fd == 2)
		return (NULL);
	return (get_next_line_internal(fd));
}
