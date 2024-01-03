/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohkang <soohkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:43:47 by soohkang          #+#    #+#             */
/*   Updated: 2024/01/03 11:42:27 by soohkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	vtr3print(char *s, t_vtr3 v) // debug
{
	printf("%s\tx: %f, y: %f, z: %f\n", s, v.x, v.y, v.z);
}

void	print_value(t_rt *rt) // debug
{
	printf("ambient: \n");
	printf("ratio: %f\n", rt->data.ambient.ratio);
	printf("color: %d\n", rgb_hex(rt->data.ambient.color[red], \
								rt->data.ambient.color[green], \
								rt->data.ambient.color[blue]));
	printf("====================================\n");
	printf("camera: \n");
	vtr3print("cam", rt->data.camera.position);
	vtr3print("cam_lookat", rt->data.camera.dir);
	printf("fov: %d\n", rt->data.camera.fov);
	printf("light: \n");
	vtr3print("position", rt->data.light.position);
	printf("brightness: %f\n", rt->data.light.brightness);
	printf("color: %d\n", rgb_hex(rt->data.light.color[red], \
								rt->data.light.color[green], \
								rt->data.light.color[blue]));
	printf("====================================\n");
	printf("plane: \n");
	vtr3print("position", rt->data.plane.position);
	vtr3print("orientation", rt->data.plane.orientation);
	printf("sphere: \n");
	vtr3print("center", rt->data.sphere.center);
	printf("radius: %f\n", rt->data.sphere.radius);
	printf("color: %d\n", rgb_hex(rt->data.sphere.color[red], \
								rt->data.sphere.color[green], \
								rt->data.sphere.color[blue]));
	printf("====================================\n");
	printf("cylinder: \n");
	vtr3print("center", rt->data.cylinder.center);
	vtr3print("orientation", rt->data.cylinder.orientation);
	printf("diameter: %f\n", rt->data.cylinder.diameter);
	printf("height: %f\n", rt->data.cylinder.height);
	printf("color: %d\n", rgb_hex(rt->data.cylinder.color[red], \
								rt->data.cylinder.color[green], \
								rt->data.cylinder.color[blue]));
	printf("====================================\n");
	printf("viewplane: \n");
	printf("h-width: %f, h-height: %f\n", rt->data.viewplane.half_width, \
										rt->data.viewplane.half_height);
	printf("distance: %f\n", rt->data.viewplane.t);
	vtr3print("left_top", rt->data.viewplane.left_top);
	vtr3print("center", rt->data.viewplane.center);
	printf("====================================\n");
}

int	main(int ac, char **av)
{
	t_rt	*rt;
	int		i;

	if (ac != 2)
		ft_exit(1, "Error\n:bad argument\n");
	rt = (t_rt *)ft_calloc(sizeof(t_rt), 1);
	i = 1;
	parse_extensions(av, &i);
	rt = open_scene_file(rt, av, &i);
	if (rt->data.obj_cnt[plane] == false && \
		rt->data.obj_cnt[sphere] == false && \
		rt->data.obj_cnt[cylinder] == false)
		ft_exit(1, "Error\n:There are no objects.\n");
	init_mlx(rt->mlx);
	cam_lookat(rt->data.camera, &rt->data.viewplane, WIDTH / HEIGHT);
	print_value(rt); //debug
	// raycast(rt->data, rt->mlx);
	rander(rt, rt->mlx);
	return (0);
}
