/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 03:28:03 by nahyulee          #+#    #+#             */
/*   Updated: 2023/11/17 13:26:59 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


int	main(int ac, char **av)
{
	t_rt	*rt;

	if (ac != 2)
		ft_exit(1, "rt file missing\n");
	make_array(rt);
	read_data(rt->data);
	rt->mlx = mlx_init();
	
	mlx_hook(mini->window, X_EVENT_KEY_PRESS, 0, press_key, mini);
	mlx_hook(mini->window, X_EVENT_KEY_EXIT, 0, print_err, mini);
	mlx_loop_hook(mini->mlx, put_image, mini);
	mlx_loop(mini->mlx);
	return (0);
}


int	press_key(int key_val, t_rt *rt)
{
	if (key_val == KEY_ESC)
		exit(0);
	if (key_val == KEY_W || key_val == KEY_UP)
		move_player(mini, -1, 0);
	if (key_val == KEY_A || key_val == KEY_LEFT)
		move_player(mini, 0, -1);
	if (key_val == KEY_S || key_val == KEY_DOWN)
		move_player(mini, 1, 0);
	if (key_val == KEY_D || key_val == KEY_RIGHT)
		move_player(mini, 0, 1);
	return (0);
}
