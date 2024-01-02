/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:43:47 by soohkang          #+#    #+#             */
/*   Updated: 2024/01/03 02:32:00 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	vtr3print(char *s, t_vtr3 v) // deberg
{
	printf("%s\tx: %f, y: %f, z: %f\n", s, v.x, v.y, v.z);
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
	open_scene_file(rt, av, &i);
	init_mlx(rt->mlx);
	cam_lookat(rt->data.camera, rt->data.viewplane);
	raycast(rt->data, rt->mlx);
	rander(rt, rt->mlx);
	return (0);
}
