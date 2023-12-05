/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_scene_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohkang <soohkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:16:44 by nahyulee          #+#    #+#             */
/*   Updated: 2023/12/05 19:16:22 by soohkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../mlx/mlx.h"

unsigned int	rgb_hex(int red, int green, int blue)
{
	unsigned int	color;

	color = (red << 16) | (green << 8) | blue;
	return (color);
}

/* sphere: 구체 */
void	sphere(t_rt *rt)
{
	// 구체를 고정값으로 처리한 상태. 즉, 파싱해서 이 고정된 값에 다가 값을 넣어야 함
	rt->data.sphere.center = (t_vtr3){0, 0, 20};
	rt->data.sphere.radius = 20;
	rt->data.sphere.color = rgb_hex(255, 0, 0);
	
	rt->data.camera.cam = (t_vtr3){-50, 0, 20};
	rt->data.camera.dir = (t_vtr3){0, 0, 0};
	rt->data.camera.fov = 70;
}

void	open_scene_file(t_rt *rt, char **av, int *i)
{
	// (void) av;
	// (void) rt;
	char	*tmp;
	int		fd;

	rt->height = 300; // 창 가로
	rt->width = 300; // 창 세로

	/* 고정값 테스트 */
	// sphere(rt);

	// printf("Result\ti:%d\n", *i);
	/* open, read */
	fd = open(av[*i], O_RDONLY);
	if (fd < 0)
		ft_exit(1, "Error\n: not exist file");
	tmp = get_next_line(fd);
	// printf("tmp:%s", tmp);
	while (*tmp)
	{
		check_data_condition(rt, tmp);
		free(tmp);
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
	}
	printf("R width:%d, height:%d\n", rt->width, rt->height); // 출력되는 것 확인
	printf("A ratio:%f, color:%x\n", rt->data.ambient.ratio, rt->data.ambient.color); // 출력되는 것 확인
	
}
