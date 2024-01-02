/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 20:50:10 by nahyulee          #+#    #+#             */
/*   Updated: 2024/01/03 02:13:51 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	press_key(int key_val, t_rt *rt)
{
	if (key_val == KEY_ESC)
		ft_exit(0, "Exit_miniRT\n");
	return (0);
}

int	print_error(int key_val, t_rt *rt)
{
	(void)rt;
	(void)key_val;
	ft_exit(1, "Exit_miniRT\n");
	return (0);
}

void	init_mlx(t_mlx mlx)
{
	mlx.mlx = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx, mlx.width, mlx.height, "miniRT");
	mlx.img_ptr = mlx_new_image(mlx.mlx, mlx.width, mlx.height);
	mlx.addr = \
		mlx_get_data_addr(mlx.img_ptr, &mlx.bpp, &mlx.size_line, &mlx.endian);
}

void	rander(t_rt *rt, t_mlx mlx)
{
	mlx_put_image_to_window(mlx.mlx, mlx.window, mlx.img_ptr, 0, 0);
	mlx_hook(mlx.window, X_EVENT_KEY_PRESS, 0, press_key, rt);
	mlx_hook(mlx.window, X_EVENT_KEY_EXIT, 0, print_error, rt);
	mlx_loop(mlx.mlx);
}
