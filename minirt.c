/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 03:28:03 by nahyulee          #+#    #+#             */
/*   Updated: 2023/12/23 17:45:29 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// void	value(t_rt *rt)
// {
	// rt->width = 1920;
	// rt->height = 1080;
	// rt->data.ambient.ratio = 0.2;
	// rt->data.ambient.color = rgb_hex(255, 255, 255);
	// rt->data.camera.cam = (t_vtr3){-50, 0, 20};
	// rt->data.camera.dir = (t_vtr3){0, 0, 0};
	// rt->data.camera.fov = 70;
	// rt->data.light.position = (t_vtr3){-40, 0, 30};
	// rt->data.light.brightness = 0.7;
	// rt->data.light.color = rgb_hex(255, 255, 255);
	// rt->data.plane.position = (t_vtr3){0, 0, 0};
	// rt->data.plane.orientation = (t_vtr3){0, 1.0, 0};
	// rt->data.plane.color = rgb_hex(255, 0, 255);
	// rt->data.sphere.center = (t_vtr3){0, 0, 20};
	// rt->data.sphere.radius = 20;
	// rt->data.sphere.color = rgb_hex(255, 0, 0);
	// rt->data.cylinder.position = (t_vtr3){50.0, 0, 20.6};
	// rt->data.cylinder.orientation = (t_vtr3){0, 0.1, 0};
	// rt->data.cylinder.diameter = 14.2;
	// rt->data.cylinder.height = 21.42;
	// rt->data.cylinder.color = rgb_hex(10, 0, 255);
// }
void	value(t_rt *rt)
{
	rt->width = 800;
	rt->height = 600;
	rt->data.ambient.ratio = 0.5;
	rt->data.ambient.color = rgb_hex(255, 255, 255);
	rt->data.camera.cam = (t_vtr3){0, 0, 0};
	rt->data.camera.dir = (t_vtr3){1, 0, 0};
	rt->data.camera.fov = 70;
	rt->data.light.position = (t_vtr3){5, 5, 50};
	rt->data.light.brightness = 0.8;
	rt->data.light.color = rgb_hex(255, 255, 255);
	rt->data.plane.position = (t_vtr3){100, 100, 0};
	rt->data.plane.orientation = (t_vtr3){1, 0, 0};
	rt->data.plane.color = rgb_hex(255, 0, 0);
	rt->data.sphere.center = (t_vtr3){10, 10, 0};
	rt->data.sphere.radius = 5;
	rt->data.sphere.color = rgb_hex(100, 255, 100);
	rt->data.cylinder.position = (t_vtr3){30, 30, 0};
	rt->data.cylinder.orientation = (t_vtr3){0, 1, 0};
	rt->data.cylinder.diameter = 2;
	rt->data.cylinder.height = 4;
	rt->data.cylinder.color = rgb_hex(0, 0, 0);
}

int	main(int ac, char **av)
{
	t_rt	*rt;
	int		i;

	if (ac != 2)
		ft_exit(1, "Error\n:bad argument\n");
	rt = (t_rt *)ft_calloc(sizeof(t_rt), 1);
	value(rt);
	(void)av;
	(void)i;
	/* parsing */
	// i = 1;
	// parse_extensions(av, &i);
	// open_scene_file(rt, av, &i);
	rt->mlx = mlx_init();
	rt->window = mlx_new_window(rt->mlx, rt->width, rt->height, "miniRT");
	rt->img_ptr = mlx_new_image(rt->mlx, rt->width, rt->height);
	rt->addr = \
		mlx_get_data_addr(rt->img_ptr, &rt->bpp, &rt->size_line, &rt->endian);
	cam_lookat(rt);
	viewplane(rt);
	raycast(rt);
	mlx_hook(rt->window, X_EVENT_KEY_PRESS, 0, press_key, rt);
	mlx_hook(rt->window, X_EVENT_KEY_EXIT, 0, print_error, rt);
	mlx_put_image_to_window(rt->mlx, rt->window, rt->img_ptr, 0, 0);
	mlx_loop(rt->mlx);
	return (0);
}

void	vtr3print(char *s, t_vtr3 v)
{
	printf("%s\tx: %f, y: %f, z: %f\n", s, v.x, v.y, v.z);
}