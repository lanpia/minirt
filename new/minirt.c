/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 20:50:10 by nahyulee          #+#    #+#             */
/*   Updated: 2024/01/02 22:29:12 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	value(char **av, t_rt *rt)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_exit(1, "Error\n:bad file\n");
	rt->data = (t_d){0};
	rt->data.camera = (t_c){0};
	rt->data.light = (t_l){0};
	rt->data.plane = (t_pl){0};
	rt->data.sphere = (t_sp){0};
	rt->data.cylinder = (t_cy){0};
	rt->data.ambient = (t_a){0};
	rt->data.camera = (t_c){0};
	rt->data.viewplane = (t_vwpl){0};
	rt->data.camera.dir = (t_vtr3){0};
	rt->data.camera.position = (t_vtr3){0};
	rt->data.light.position = (t_vtr3){0};
	rt->data.light.color = (t_vtr3){0};
	rt->data.plane.position = (t_vtr3){0};
	rt->data.plane.orientation = (t_vtr3){0};
	rt->data.plane.normal = (t_vtr3){0};
	rt->data.plane.center = (t_vtr3){0};
	rt->data.plane.hit_point = (t_vtr3){0};
	rt->data.sphere.normal = (t_vtr3){0};
	rt->data.sphere.center = (t_vtr3){0};
	rt->data.sphere.hit_point = (t_vtr3){0};
	rt->data.cylinder.normal = (t_vtr3){0};
	rt->data.cylinder.center = (t_vtr3){0};
	rt->data.cylinder.hit_point = (t_vtr3){0};
	rt->data.ambient.color = (t_vtr3){0};
}

void	vtr3print(char *s, t_vtr3 v)
{
	printf("%s\tx: %f, y: %f, z: %f\n", s, v.x, v.y, v.z);
}

int	main(int ac, char **av)
{
	t_rt	*rt;
	t_mlx	mlx;
	t_d		data;

	if (ac != 2)
		ft_exit(1, "Error\n:bad argument\n");
	rt = (t_rt *)ft_calloc(sizeof(t_rt), 1);
	value(av[1], rt);
	init_mlx(rt->mlx);
	cam_lookat(rt->data.camera, rt->data.viewplane);
	raycast(rt->data, rt->mlx);
	rander(rt->mlx);
	return (0);
}
