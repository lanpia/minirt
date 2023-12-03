/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohkang <soohkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 03:28:03 by nahyulee          #+#    #+#             */
/*   Updated: 2023/12/02 18:58:04 by soohkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft/libft.h"
#include <stdlib.h>

// 완료 후 프로토타입 삭제 예정
void	parse_extens(char **av);
void	sphere(t_rt *rt);

// 완료 후 헤더 삭제 예정
#include <stdio.h>

int	main(int ac, char **av)
{
	t_rt	*rt;

	// file만 받으면 받으면 되서 `3`에 `=` 붙임
	if (ac < 2 || ac >= 3)
		ft_exit(1, "bad argument\n");
	rt = (t_rt *)ft_calloc(sizeof(t_rt), 1);
	// parse file name extensions
	parse_extens(av);
	
	// parse data
	read_data(rt, av);
	
	// 구체용 함수로 빼기
	sphere(rt);
	
	rt->mlx = mlx_init();
	rt->window = mlx_new_window(rt->mlx, rt->width, rt->height, "miniRT");
	drawsphere(rt, rt->data.sphere);
	// draw_cylinder(rt, rt ->data.);
	mlx_hook(rt->window, X_EVENT_KEY_PRESS, 0, press_key, rt);
	mlx_hook(rt->window, X_EVENT_KEY_EXIT, 0, print_error, rt);
	mlx_loop(rt->mlx);
	return (0);
}

void	sphere(t_rt *rt)
{
	// 구체를 고정값으로 처리한 상태. 즉, 파싱해서 이 고정된 값에 다가 값을 넣어야 함
	// sphere: 구체
	rt->data.sphere.center = (t_vtr3){0, 0, 20};
	rt->data.sphere.radius = 20;
	rt->data.sphere.color = rgb_hex(255, 0, 0);
	
	rt->data.camera.cam = (t_vtr3){-50, 0, 20};
	rt->data.camera.dir = (t_vtr3){0, 0, 0};
	rt->data.camera.fov = 70;
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
		printf("Error: File '%s' is not a valid .rt file\n", av[1]);
	if (flag == 1)
		printf("Error: The '%s' contains .rt multiple times.\n", av[1]);
}
