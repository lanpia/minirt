/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohkang <soohkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 20:50:10 by nahyulee          #+#    #+#             */
/*   Updated: 2023/12/04 17:46:57 by soohkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

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
