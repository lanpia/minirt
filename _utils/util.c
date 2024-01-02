/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 20:50:10 by nahyulee          #+#    #+#             */
/*   Updated: 2023/12/30 04:27:55 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	move_camera(t_c camera, int x, int y, int z)
{
	camera.cam.x += x;
	camera.cam.y += y;
	camera.cam.z += z;
}

int	press_key(int key_val, t_rt *rt)
{
	if (key_val == KEY_ESC)
		ft_exit(0, "Exit_miniRT\n");
	if (key_val == KEY_W)
		move_camera(rt->data.camera, 0, 0, 1);
	if (key_val == KEY_UP)
		move_camera(rt->data.camera, 0, 1, 0);
	if (key_val == KEY_A || key_val == KEY_LEFT)
		move_camera(rt->data.camera, -1, 0, 0);
	if (key_val == KEY_S)
		move_camera(rt->data.camera, 0, 0, -1);
	if (key_val == KEY_DOWN)
		move_camera(rt->data.camera, 0, -1, 0);
	if (key_val == KEY_D || key_val == KEY_RIGHT)
		move_camera(rt->data.camera, 1, 0, 0);
	return (0);
}

int	print_error(int key_val, t_rt *rt)
{
	(void)rt;
	(void)key_val;
	ft_exit(1, "Exit_miniRT\n");
	return (0);
}

int	get_color_component(int color, int shift)
{
	return ((color >> shift) & 0xFF);
}

unsigned int	rgb_hex(int red, int green, int blue)
{
	unsigned int	color;

	color = (red << 16) | (green << 8) | blue;
	return (color);
}
