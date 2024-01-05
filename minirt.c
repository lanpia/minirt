/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:43:47 by soohkang          #+#    #+#             */
/*   Updated: 2024/01/05 04:10:26 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	leakcheck(void)
{
	system("leaks miniRT");
}

void	vtr3print(char *s, t_vtr3 v) // debug
{
	printf("%s\tx: %f, y: %f, z: %f\n", s, v.x, v.y, v.z);
}

unsigned int	rgb_hex(int red, int green, int blue) // debug
{
	unsigned int	color;

	color = (red << 16) | (green << 8) | blue;
	return (color);
}

void	print_value(t_rt *rt) // debug
{
	printf("ambient: \n");
	printf("ratio: %f\n", rt->data.ambient.ratio);
	printf("color: %x\n", rgb_hex(rt->data.ambient.color[red], \
								rt->data.ambient.color[green], \
								rt->data.ambient.color[blue]));
	printf("====================================\n");
	printf("camera: \n");
	vtr3print("cam\t", rt->data.camera.position);
	vtr3print("dir\t", rt->data.camera.dir);
	printf("fov: %d\n", rt->data.camera.fov);
	printf("====================================\n");
	printf("light: \n");
	vtr3print("position", rt->data.light.position);
	printf("brightness: %f\n", rt->data.light.brightness);
	printf("color: %x\n", rgb_hex(rt->data.light.color[red], \
								rt->data.light.color[green], \
								rt->data.light.color[blue]));
	printf("====================================\n");
	printf("plane: \n");
	vtr3print("position", rt->data.plane.position);
	vtr3print("orientation", rt->data.plane.orientation);
	printf("sphere: \n");
	vtr3print("center\t", rt->data.sphere.center);
	printf("radius: %f\n", rt->data.sphere.radius);
	printf("color: %x\n", rgb_hex(rt->data.sphere.color[red], \
								rt->data.sphere.color[green], \
								rt->data.sphere.color[blue]));
	printf("====================================\n");
	printf("cylinder: \n");
	vtr3print("center\t", rt->data.cylinder.center);
	vtr3print("orientation", rt->data.cylinder.orientation);
	printf("diameter: %f\n", rt->data.cylinder.diameter);
	printf("height: %f\n", rt->data.cylinder.height);
	printf("color: %x\n", rgb_hex(rt->data.cylinder.color[red], \
								rt->data.cylinder.color[green], \
								rt->data.cylinder.color[blue]));
	printf("====================================\n");
	printf("viewplane: \n");
	printf("h-width: %f, h-height: %f\n", rt->data.viewplane.half_width, \
										rt->data.viewplane.half_height);
	printf("distance: %f\n", rt->data.viewplane.t);
	vtr3print("left_top", rt->data.viewplane.left_top);
	vtr3print("center\t", rt->data.viewplane.center);
	printf("====================================\n");
}

int	main(int ac, char **av)
{
	t_rt	*rt;
	int		i;

	// atexit(leakcheck);
	if (ac != 2)
		ft_exit(1, "Error\n:bad argument\n");
	rt = (t_rt *)ft_calloc(sizeof(t_rt), 1);
	i = 1;
	parse_extensions(av, &i);
	rt = open_scene_file(rt, av, &i);
	// if (rt->data.obj_cnt[plane] == false && 
	// 	rt->data.obj_cnt[sphere] == false && 
	// 	rt->data.obj_cnt[cylinder] == false)
	// 	ft_exit(1, "Error\n:There are no objects.\n");
	init_mlx(rt->mlx);
	cam_lookat(&rt->data.camera, &rt->data.viewplane, WIDTH/HEIGHT);
	print_value(rt); //debug
	// raycast(rt->data, rt->mlx);
	rander(rt, rt->mlx);
	free(rt);
	return (0);
}
