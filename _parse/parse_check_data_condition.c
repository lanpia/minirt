/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_data_condition.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohkang <soohkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 03:15:07 by soohkang          #+#    #+#             */
/*   Updated: 2024/01/03 13:12:53 by soohkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	put_c(t_c *cam, char **data)
{
	static int	cam_count;

	if (cam_count > 0)
		ft_exit(1, "Error\n:There are more than one camera.\n");
	cam->position = (t_vtr3){ft_atof(data[1]), ft_atof(data[2]), \
							ft_atof(data[3])};
	cam->dir = (t_vtr3){ft_atof(data[4]), ft_atof(data[5]), \
						ft_atof(data[6])};
	if (ft_compare_int(cam->dir.x, -1, 1) == false || \
		ft_compare_int(cam->dir.y, -1, 1) == false || \
		ft_compare_int(cam->dir.z, -1, 1) == false)
		ft_exit(1, "Error\n:Direction is not between -1 and 1.\n");
	cam->fov = ft_atoi(data[7]);
	if (ft_compare_int(cam->fov, 0, 180) == false)
		ft_exit(1, "Error\n:FOV is not between 0 and 180.\n");
	if (data[8] != 0)
		ft_exit(2, "Error\n:The value does not exist.");
	cam_count++;
}

void	put_l(t_l *light, char **data)
{
	static int	light_count;

	if (light_count > 0)
		ft_exit(1, "Error\n:There are more than one light.\n");
	light->position = (t_vtr3){ft_atof(data[1]), ft_atof(data[2]), \
							ft_atof(data[3])};
	light->brightness = ft_atof(data[4]);
	if (ft_compare_int(light->brightness, 0, 1) == false)
		ft_exit(1, "Error\n:Brightness is not between 0 and 1.\n");
	color_atoi(light->color, data, 5);
	light_count++;
}

void	put_pl(t_pl *plane, char **data)
{
	static int	plane_count;

	if (plane_count > 0)
		ft_exit(1, "Error\n:There are more than one plane.\n");
	plane->position = (t_vtr3){ft_atof(data[1]), ft_atof(data[2]), \
							ft_atof(data[3])};
	plane->orientation = (t_vtr3){ft_atof(data[4]), ft_atof(data[5]), \
								ft_atof(data[6])};
	if (ft_compare_int(plane->orientation.x, -1, 1) == false || \
		ft_compare_int(plane->orientation.y, -1, 1) == false || \
		ft_compare_int(plane->orientation.z, -1, 1) == false)
		ft_exit(1, "Error\n:Orientation is not between -1 and 1.\n");
	color_atoi(plane->color, data, 7);
	plane_count++;
}

void	put_sp(t_sp *sphere, char **data)
{
	sphere->center = (t_vtr3){ft_atof(data[1]), ft_atof(data[2]), \
							ft_atof(data[3])};
	sphere->radius = ft_atof(data[4]);
	color_atoi(sphere->color, data, 5);
}

void	put_cy(t_cy *cylinder, char **data)
{
	cylinder->center = (t_vtr3){ft_atof(data[1]), ft_atof(data[2]), \
								ft_atof(data[3])};
	cylinder->orientation = (t_vtr3){ft_atof(data[4]), ft_atof(data[5]), \
							ft_atof(data[6])};
	if (ft_compare_int(cylinder->orientation.x, -1, 1) == false || \
		ft_compare_int(cylinder->orientation.y, -1, 1) == false || \
		ft_compare_int(cylinder->orientation.z, -1, 1) == false)
		ft_exit(1, "Error\n:Orientation is not between -1 and 1.\n");
	cylinder->diameter = ft_atof(data[7]);
	cylinder->height = ft_atof(data[8]);
	color_atoi(cylinder->color, data, 9);
}
