/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:16:44 by nahyulee          #+#    #+#             */
/*   Updated: 2023/11/22 01:19:19 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rt	*make_array(void)
{
	t_rt	*d;

	d = (t_rt *)ft_calloc(sizeof(t_rt), 1);
	d->width = 800;
	d->height = 600;
	return (d);
}

void	read_data(t_rt *d, char **av)
{
	char	*tmp;
	int		fd;

	(void)av;
	fd = open("test.rt", O_RDONLY);
	tmp = get_next_line(fd);
	if (tmp[0] == 'R')
	{
		d->width = ft_atoi(ft_strtok(tmp, "R \t"));
	}
}

char	*rgb_hex(int red, int green, int blue)
{
	unsigned int	color;
	char			*tmp;
	char			*hexcolor;

	color = (red << 16) | (green << 8) | blue;
	tmp = ft_itoa(color);
	hexcolor = ft_strjoin("0x", tmp);
	free(tmp);
	return (hexcolor);
}
