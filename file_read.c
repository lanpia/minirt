/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:16:44 by nahyulee          #+#    #+#             */
/*   Updated: 2023/11/30 16:20:05 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	read_data(t_rt *rt, char **av)
{
	// char	*tmp;
	// int		fd;
	int		i;

	i = 1;
	if (!ft_strcmp(av[i], "--save"))
		i++;
	if (ft_strnstr(av[i], ".rt", ft_strlen(av[i])) == NULL)
		ft_exit(1, "Error\nFile is not .rt\n");
	rt->height = 600;
	rt->width = 800;
	rt->data.ambient.ratio = 0.2;
	rt->data.ambient.color = rgb_hex(255, 255, 255);
	rt->data.camera.cam = (t_vtr3){-50, 0, 20};
	rt->data.camera.dir = (t_vtr3){0, 0, 0};
	rt->data.camera.fov = 70;
	rt->data.light.position = (t_vtr3){-50, 0, 20};
	rt->data.light.brightness = 0.7;
	rt->data.light.color = rgb_hex(255, 255, 255);
	rt->data.plane.position = (t_vtr3){0, 0, 0};
	rt->data.plane.orientation = (t_vtr3){0, 1.0, 0};
	rt->data.plane.color = rgb_hex(255, 0, 255);
	rt->data.sphere.center = (t_vtr3){0, 0, 20};
	rt->data.sphere.radius = 20;
	rt->data.sphere.color = rgb_hex(255, 0, 0);
	rt->data.cylinder.position = (t_vtr3){50.0, 0, 20.6};
	rt->data.cylinder.orientation = (t_vtr3){0, 0, 1.0};
	rt->data.cylinder.diameter = 14.2;
	rt->data.cylinder.height = 21.42;
	rt->data.cylinder.color = rgb_hex(10, 0, 255);

	// fd = open(av[i], O_RDONLY);
	// tmp = get_next_line(fd);
	// while (*tmp)
	// {
	// 	check_data_condition(rt, tmp);
	// 	free(tmp);
	// 	tmp = get_next_line(fd);
	// }
}

// void	check_data_condition(t_rt *rt, char *tmp)
// {
// 	if (!ft_strnstr(tmp, "R", ft_strlen(tmp)))
// 		put_r(rt, tmp);
// 	else if (!ft_strnstr(tmp, "A", ft_strlen(tmp)))
// 		put_a(rt, tmp);
// 	else if (!ft_strnstr(tmp, "c", ft_strlen(tmp)))
// 		put_c(rt, tmp);
// 	else if (!ft_strnstr(tmp, "l", ft_strlen(tmp)))
// 		put_l(rt, tmp);
// 	else if (!ft_strnstr(tmp, "pl", ft_strlen(tmp)))
// 		put_pl(rt, tmp);
// 	else if (!ft_strnstr(tmp, "sp", ft_strlen(tmp)))
// 		put_sp(rt, tmp);
// 	else if (!ft_strnstr(tmp, "cy", ft_strlen(tmp)))
// 		put_cy(rt, tmp);
// 	// else if (!ft_strnstr(tmp, "sq", ft_strlen(tmp)))
// 	// 	put_sq(rt, tmp);
// 	// else if (!ft_strnstr(tmp, "tr", ft_strlen(tmp)))
// 	// 	put_tr(rt, tmp);
// 	else
// 		ft_exit(1, "Error\nData is not exist\n");
// }

// void	put_r(t_rt *rt, char *tmp)
// {
// 	char	**data;
// 	int		i;

// 	data = ft_split_bonus(tmp, " \t\n,");
// 	if (data[0][0] == 'R')
// 	{
// 		rt->width = ft_atoi(data[1]);
// 		rt->height = ft_atoi(data[2]);
// 	}
// 	else
// 		ft_exit(1, "Error\nR is not exist\n");
// 	i = 0;
// 	while (data[i])
// 		i++;
// 	ft_2d_arr_free(data, i);
// }

// void	put_a(t_rt *rt, char *tmp)
// {
// 	char	**data;
// 	int		i;

// 	data = ft_split_bonus(tmp, " \t\n,");
// 	if (data[0][0] == 'A')
// 	{
// 		rt->data.ambient.ratio = ft_atof(data[1]);
// 		rt->data.ambient.color = rgb_hex(ft_atoi(data[2]), ft_atoi(data[3]), ft_atoi(data[4]));
// 	}
// 	else
// 		ft_exit(1, "Error\nA is not exist\n");
// 	i = 0;
// 	while (data[i])
// 		i++;
// 	ft_2d_arr_free(data, i);
// }

unsigned int	rgb_hex(int red, int green, int blue)
{
	unsigned int	color;

	color = (red << 16) | (green << 8) | blue;
	return (color);
}
