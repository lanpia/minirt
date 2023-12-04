/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohkang <soohkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 03:28:03 by nahyulee          #+#    #+#             */
/*   Updated: 2023/12/04 15:35:23 by soohkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft/libft.h"
#include <stdlib.h>

// 완료 후 프로토타입 삭제 예정
void	parse_extens(char **av);

// 완료 후 헤더 삭제 예정
#include <stdio.h>

int	main(int ac, char **av)
{
	t_rt	*rt;

	// file만 받으면 받으면 되서 `3`에 `=` 붙임
	if (ac < 2 || ac >= 3)
		ft_exit(1, "Error\n:bad argument\n");
	rt = (t_rt *)ft_calloc(sizeof(t_rt), 1);
	// parse file name extensions
	parse_extens(av);
	
	// parse data
	read_data(rt, av);
	
	rt->mlx = mlx_init();
	rt->window = mlx_new_window(rt->mlx, rt->width, rt->height, "miniRT");


	// 구체용 함수로 빼기
	drawsphere(rt, rt->data.sphere);
	// draw_cylinder(rt, rt ->data.);


	mlx_hook(rt->window, X_EVENT_KEY_PRESS, 0, press_key, rt);
	mlx_hook(rt->window, X_EVENT_KEY_EXIT, 0, print_error, rt);
	mlx_loop(rt->mlx);
	return (0);
}

void	parse_extens(char **av)
{
	int			last_i;
	int			f_len;
	int			j;
	int			flag;

	f_len = ft_strlen(av[1]);
	last_i = f_len--;
	last_i--;
	flag = 0;
	if (av[1][last_i] == 't' && av[1][last_i - 1] == 'r' && av[1][last_i - 2] == '.')
	{
		j = -1;
		while (++j < (last_i - 3))
		{
			if (av[1][j] == '.' && av[1][j + 1] == 'r' && av[1][j + 2] == 't')
			{
				flag = 1;
				break ;
			}
		}
	}
	else
		printf("Error\n:File '%s' is not a valid .rt file\n", av[1]);
	if (flag == 1)
		printf("Error\n:The '%s' contains .rt multiple times.\n", av[1]);
}
