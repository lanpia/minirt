/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 20:50:10 by nahyulee          #+#    #+#             */
/*   Updated: 2024/01/05 23:13:34 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	press_key(int key_val, t_rt *rt)
{
	if (key_val == KEY_ESC)
	{
		free(rt);
		ft_exit(0, "Exit_miniRT\n");
	}
	return (0);
}

int	print_error(int key_val, t_rt *rt)
{
	(void)key_val;
	free(rt);
	ft_exit(1, "Exit_miniRT\n");
	return (0);
}

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "miniRT");
	mlx->img_ptr = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->addr = \
		mlx_get_data_addr(mlx->img_ptr, &mlx->bpp, &mlx->size_line, &mlx->endian);
}

void	rander(t_rt *rt, t_mlx mlx)
{
	raycast(rt->data, &mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.window, mlx.img_ptr, 0, 0);
	mlx_hook(mlx.window, X_EVENT_KEY_PRESS, 0, press_key, rt);
	mlx_hook(mlx.window, X_EVENT_KEY_EXIT, 0, print_error, rt);
	mlx_loop(mlx.mlx);
}

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*pixel;

	if (0 <= x && x < WIDTH && 0 <= y && y < HEIGHT)
	{
		pixel = mlx->addr + (y * mlx->size_line + x * 4);
		*(int *)pixel = color;
	}
}
