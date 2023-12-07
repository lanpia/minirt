/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 03:28:03 by nahyulee          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/12/07 15:23:08 by nahyulee         ###   ########.fr       */
=======
/*   Updated: 2023/12/07 16:35:52 by nahyulee         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int ac, char **av)
{
	t_rt	*rt;
	int		i;

	if (ac != 2)
		ft_exit(1, "Error\n:bad argument\n");
	rt = (t_rt *)ft_calloc(sizeof(t_rt), 1);
<<<<<<< HEAD
	read_data(rt, av);
	rt->mlx = mlx_init();
	rt->window = mlx_new_window(rt->mlx, rt->width, rt->height, "miniRT");
	cam_lookat(rt);
	viewplane(rt);
	raycast(rt);
=======

	/* parsing */
	i = 1;
	parse_extens(av, &i); // file name extensions
	open_scene_file(rt, av, &i); // scene file reading and parsing

	/* mlx */
	rt->mlx = mlx_init();
	rt->window = mlx_new_window(rt->mlx, rt->width, rt->height, "miniRT");
	/*camera*/
	cam_lookat(rt);
	viewplane(rt);
	raycast(rt);
	/* draw objects */
	draw(rt);

>>>>>>> main
	mlx_hook(rt->window, X_EVENT_KEY_PRESS, 0, press_key, rt);
	mlx_hook(rt->window, X_EVENT_KEY_EXIT, 0, print_error, rt);
	mlx_loop(rt->mlx);
	return (0);
}
