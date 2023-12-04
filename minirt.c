/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohkang <soohkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 03:28:03 by nahyulee          #+#    #+#             */
/*   Updated: 2023/12/05 02:35:11 by soohkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	draw(t_rt *rt)
{
	drawsphere(rt, rt->data.sphere);
	// draw_cylinder(rt, rt ->data.cylinder);
	// draw_???(rt, rt ->data.);
}

int	main(int ac, char **av)
{
	t_rt	*rt;
	int		i;

	// file만 받으면 받으면 되서 `3`에 `=` 붙임
	if (ac < 2 || ac >= 3)
		ft_exit(1, "Error\n:bad argument\n");
	rt = (t_rt *)ft_calloc(sizeof(t_rt), 1);

	/* parsing */
	i = 1;
	parse_extens(av, &i); // file name extensions
	open_scene_file(rt, av, &i); // scene file reading and parsing

	/* mlx */
	rt->mlx = mlx_init();
	rt->window = mlx_new_window(rt->mlx, rt->width, rt->height, "miniRT");

	/* draw objects */
	draw(rt);

	mlx_hook(rt->window, X_EVENT_KEY_PRESS, 0, press_key, rt);
	mlx_hook(rt->window, X_EVENT_KEY_EXIT, 0, print_error, rt);
	mlx_loop(rt->mlx);
	return (0);
}
