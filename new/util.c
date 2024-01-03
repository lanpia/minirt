/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 20:50:10 by nahyulee          #+#    #+#             */
/*   Updated: 2024/01/02 22:00:54 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

void	my_mlx_pixel_put(t_rt *rt, int x, int y, int color)
{
	char	*pixel;

	if (0 <= x && x < rt->mlx.width && 0 <= y && y < rt->mlx.height)
	{
		pixel = rt->mlx.addr + (y * rt->mlx.size_line + x * 4);
		*(int *)pixel = color;
	}
}
