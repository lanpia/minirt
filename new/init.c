/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:58:25 by nahyulee          #+#    #+#             */
/*   Updated: 2024/01/02 21:58:42 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_mlx(t_mlx mlx)
{
	mlx.mlx = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx, mlx.width, mlx.height, "miniRT");
	mlx.img_ptr = mlx_new_image(mlx.mlx, mlx.width, mlx.height);
	mlx.addr = \
		mlx_get_data_addr(mlx.img_ptr, &mlx.bpp, &mlx.size_line, &mlx.endian);
}

void	rander(t_mlx mlx)
{
	mlx_put_image_to_window(mlx.mlx, mlx.window, mlx.img_ptr, 0, 0);
	mlx_hook(rt->mlx.window, X_EVENT_KEY_PRESS, 0, press_key, rt);
	mlx_hook(rt->mlx.window, X_EVENT_KEY_EXIT, 0, print_error, rt);
	mlx_loop(rt->mlx.mlx);
}
