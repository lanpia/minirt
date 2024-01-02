/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_data_condition.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 03:15:07 by soohkang          #+#    #+#             */
/*   Updated: 2024/01/03 03:48:31 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	put_c(t_c cam, char **data)
{
	char	**data;

	if (ft_strcmp("c", data[0]) == 0)
	{
		cam.position = (t_vtr3){ft_atof(data[1]), ft_atof(data[2]), \
								ft_atof(data[3])};
		cam.dir = (t_vtr3){ft_atof(data[4]), ft_atof(data[5]), \
							ft_atof(data[6])};
		if (ft_compare_int(cam.dir.x, -1, 1) == false || \
			ft_compare_int(cam.dir.y, -1, 1) == false || \
			ft_compare_int(cam.dir.z, -1, 1) == false)
			ft_exit(1, "Error\n:Direction is not between -1 and 1.\n");
		cam.fov = ft_atoi(data[7]);
		if (ft_compare_int(cam.fov, 0, 180) == false)
			ft_exit(1, "Error\n:FOV is not between 0 and 180.\n");
		if (data[8] != 0)
			ft_exit(2, "Error\n:The value does not exist.");
	}
	else
		ft_exit(1, "Error\nc is not exist\n");
}

void	put_l(t_l light, char **data)
{
	if (ft_strcmp("l", data[0]) == 0)
	{
		light.position = (t_vtr3){ft_atof(data[1]), ft_atof(data[2]), \
								ft_atof(data[3])};
		light.brightness = ft_atof(data[4]);
		if (ft_compare_int(light.brightness, 0, 1) == false)
			ft_exit(1, "Error\n:Brightness is not between 0 and 1.\n");
		color_atoi(light.color, data, 5);
	}
	else
		ft_exit(1, "Error\nl is not exist\n");
}

void	put_pl(t_pl plane, char **data)
{
	if (ft_strcmp("pl", data[0]) == 0)
	{
		plane.position = (t_vtr3){ft_atof(data[1]), ft_atof(data[2]), \
								ft_atof(data[3])};
		plane.orientation = (t_vtr3){ft_atof(data[4]), ft_atof(data[5]), \
									ft_atof(data[6])};
		if (ft_compare_int(plane.orientation.x, -1, 1) == false || \
			ft_compare_int(plane.orientation.y, -1, 1) == false || \
			ft_compare_int(plane.orientation.z, -1, 1) == false)
			ft_exit(1, "Error\n:Orientation is not between -1 and 1.\n");
		color_atoi(plane.color, data, 7);
	}
	else
		ft_exit(1, "Error\npl is not exist\n");
}

void	put_sp(t_sp sphere, char **data)
{
	if (ft_strcmp("sp", data[0]) == 0)
	{
		sphere.center = (t_vtr3){ft_atof(data[1]), ft_atof(data[2]), \
								ft_atof(data[3])};
		sphere.radius = ft_atof(data[4]);
		if (ft_compare_int(sphere.radius, 0, 1) == false)
			ft_exit(1, "Error\n:Radius is not between 0 and 1.\n");
		color_atoi(sphere.color, data, 5);
	}
	else
		ft_exit(1, "Error\nsp is not exist\n");
}

void	put_cy(t_cy cylinder, char **data)
{
	if (ft_strcmp("cy", data[0]) == 0)
	{
		cylinder.center = (t_vtr3){ft_atof(data[1]), ft_atof(data[2]), \
									ft_atof(data[3])};
		cylinder.orientation = (t_vtr3){ft_atof(data[1]), ft_atof(data[2]), \
								ft_atof(data[3])};
		if (ft_compare_int(cylinder.orientation.x, -1, 1) == false || \
			ft_compare_int(cylinder.orientation.y, -1, 1) == false || \
			ft_compare_int(cylinder.orientation.z, -1, 1) == false)
			ft_exit(1, "Error\n:Orientation is not between -1 and 1.\n");
		cylinder.diameter = ft_atof(data[4]);
		cylinder.height = ft_atof(data[5]);
		color_atoi(cylinder.color, data, 6);
	}
	else
		ft_exit(1, "Error\ncy is not exist\n");
}
