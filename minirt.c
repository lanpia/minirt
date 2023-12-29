/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhyeon <suhyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 03:28:03 by nahyulee          #+#    #+#             */
/*   Updated: 2023/12/29 12:05:04 by suhyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int ac, char **av)
{
	t_rt	*rt;
	int		i;

	// file만 받으면 받으면 되서 `3`에 `=` 붙임
	if (ac < 2 || ac >= 3)
		ft_exit(1, "Error\n:bad argument\n");
	rt = (t_rt *)ft_calloc(sizeof(t_rt), 1);

	// parsing
	i = 1;
	parse_extensions(av, &i); // file name extensions
	open_scene_file(rt, av, &i); // scene file reading and parsing

	// mlx
	rt->mlx = mlx_init();
	rt->window = mlx_new_window(rt->mlx, rt->width, 
										rt->height, "miniRT");

	// create image buffer
	rt->img_buffer = mlx_new_image(rt->mlx, rt->width,
													rt->height);

	// camera setting
	initialize_camera(rt);

	// render objects
	render_scene(rt);

	mlx_hook(rt->window, X_EVENT_KEY_PRESS, 
									0, press_key, rt);
	mlx_hook(rt->window, X_EVENT_KEY_EXIT, 
									0, print_error, rt);
	mlx_loop(rt->mlx);
	return (0);
}

// int	main(void)
// {
// 	int i;
// 	int j;
// 	double r;
// 	double g;
// 	double b;
// 	int canvas_width;
// 	int canvas_height;

// 	canvas_width = 256;
// 	canvas_height = 256;
	
// 	printf("P3\n%d %d\n255\n", canvas_width, canvas_height);
// 	j = canvas_height - 1;
// 	while (j >= 0)
// 	{
// 		i = 0;
// 		while (i < canvas_width)
// 		{
// 			r = (double)i / (canvas_width - 1);
// 			g = (double)j / (canvas_height - 1);
// 			b = 0.25;
// 			printf("%d %d %d\n", (int)(255.999 * r), (int)(255.999 * g), (int)(255.999 * b));
// 			++i;
// 		}
// 		--j;
// 	}
// 	return (0);
// }
