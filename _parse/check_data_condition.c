/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data_condition.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 03:15:07 by soohkang          #+#    #+#             */
/*   Updated: 2023/12/15 23:54:59 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	check_data_condition(t_rt *rt, char *tmp)
{
	if (ft_strcmp("R", tmp) == 0)
		put_r(rt, tmp);
	else if (ft_strcmp("A", tmp) == 0)
		put_a(rt, tmp);
	else if (ft_strcmp("c", tmp) == 0)
		put_c(rt, tmp);
	else if (ft_strcmp("l", tmp) == 0)
		put_l(rt, tmp);
	else if (ft_strcmp("pl", tmp) == 0)
		put_pl(rt, tmp);
	else if (ft_strcmp("sp", tmp) == 0)
		put_sp(rt, tmp);
	else if (ft_strcmp("cy", tmp) == 0)
		put_cy(rt, tmp);
}

void	put_r(t_rt *rt, char *tmp)
{
	char	**data;
	int		i;

	data = ft_split_bonus(tmp, " \t\n,");
	if (ft_strcmp("R", data[0]) == 0)
	{
		rt->width = ft_atoi(data[1]);
		rt->height = ft_atoi(data[2]);
	}
	else
		ft_exit(1, "Error\nR is not exist\n");
	i = 0;
	while (data[i])
		i++;
	ft_2d_arr_free(data, i);
}

void	put_a(t_rt *rt, char *tmp)
{
	char	**data;
	int		i;

	data = ft_split_bonus(tmp, " \t\n,");
	if (ft_strcmp("A", data[0]) == 0)
	{
		rt->data.ambient.ratio = ft_atof(data[1]);
		rt->data.ambient.ratio = ft_atof(data[2]);
		rt->data.ambient.color = rgb_hex(ft_atoi(data[2]), ft_atoi(data[3]), ft_atoi(data[4]));
	}
	else
		ft_exit(1, "Error\nA is not exist\n");
	i = 0;
	while (data[i])
		i++;
	ft_2d_arr_free(data, i);
}

void	put_c(t_rt *rt, char *tmp)
{
	char	**data;
	int		i;

	data = ft_split_bonus(tmp, " \t\n,");
	if (ft_strcmp("c", data[0]) == 0)
	{
		rt->data.camera.cam = (t_vtr3){ft_atof(data[1]), ft_atof(data[2]), ft_atof(data[3])};
		rt->data.camera.dir = (t_vtr3){ft_atof(data[4]), ft_atof(data[5]), ft_atof(data[6])};
		rt->data.camera.fov = ft_atoi(data[7]);
		// 맨 뒤에 값 에러 핸들링
		if (data[8] != 0)
			ft_exit(2, "Error\n:The value does not exist.");
	}
	else
		ft_exit(1, "Error\nc is not exist\n");
	i = 0;
	while (data[i])
		i++;
	ft_2d_arr_free(data, i);
}

void	put_l(t_rt *rt, char *tmp)
{
	char	**data;
	int		i;

	data = ft_split_bonus(tmp, " \t\n,");
	if (ft_strcmp("l", data[0]) == 0)
	{
		rt->data.light.position = (t_vtr3){ft_atof(data[1]), ft_atof(data[2]), ft_atof(data[3])};
		rt->data.light.brightness = ft_atof(data[4]);
		rt->data.light.color = rgb_hex(ft_atoi(data[5]), ft_atoi(data[6]), ft_atoi(data[7]));
	}
	else
		ft_exit(1, "Error\nl is not exist\n");
	i = 0;
	while (data[i])
		i++;
	ft_2d_arr_free(data, i);
}

void	put_pl(t_rt *rt, char *tmp)
{
	char	**data;
	int		i;

	data = ft_split_bonus(tmp, " \t\n,");
	if (ft_strcmp("pl", data[0]) == 0)
	{
		rt->data.plane.position = (t_vtr3){ft_atof(data[1]), ft_atof(data[2]), ft_atof(data[3])};
		rt->data.plane.orientation = (t_vtr3){ft_atof(data[4]), ft_atof(data[5]), ft_atof(data[6])};
		rt->data.plane.color = rgb_hex(ft_atoi(data[7]), ft_atoi(data[8]), ft_atoi(data[9]));
	}
	else
		ft_exit(1, "Error\npl is not exist\n");
	i = 0;
	while (data[i])
		i++;
	ft_2d_arr_free(data, i);
}

void	put_sp(t_rt *rt, char *tmp)
{
	char	**data;
	int		i;

	data = ft_split_bonus(tmp, " \t\n,");
	if (ft_strcmp("sp", data[0]) == 0)
	{
		rt->data.sphere.center = (t_vtr3){ft_atof(data[1]), ft_atof(data[2]), ft_atof(data[3])};
		rt->data.sphere.radius = ft_atof(data[4]);
		rt->data.sphere.color = rgb_hex(ft_atoi(data[5]), ft_atoi(data[6]), ft_atoi(data[7]));
	}
	else
		ft_exit(1, "Error\nsp is not exist\n");
	i = 0;
	while (data[i])
		i++;
	ft_2d_arr_free(data, i);
}

void	put_cy(t_rt *rt, char *tmp)
{
	char	**data;
	int		i;

	data = ft_split_bonus(tmp, " \t\n,");
	if (ft_strcmp("cy", data[0]) == 0)
	{
		rt->data.cylinder.position = (t_vtr3){ft_atof(data[1]), ft_atof(data[2]), ft_atof(data[3])};
		rt->data.cylinder.orientation = (t_vtr3){ft_atof(data[1]), ft_atof(data[2]), ft_atof(data[3])};
		rt->data.cylinder.diameter = ft_atof(data[4]);
		rt->data.cylinder.height = ft_atof(data[5]);
		rt->data.cylinder.color = rgb_hex(ft_atoi(data[6]), ft_atoi(data[7]), ft_atoi(data[8]));
	}
	else
		ft_exit(1, "Error\ncy is not exist\n");
	i = 0;
	while (data[i])
		i++;
	ft_2d_arr_free(data, i);
}