/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_scene_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohkang <soohkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:16:44 by nahyulee          #+#    #+#             */
/*   Updated: 2023/12/10 16:56:52 by soohkang         ###   ########.fr       */
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
// 예시 함수고, 안씀
// void	sphere(t_rt *rt)
// {
// 	// 구체를 고정값으로 처리한 상태. 즉, 파싱해서 이 고정된 값에 다가 값을 넣어야 함
// 	rt->data.sphere.center = (t_vtr3){0, 0, 20};
// 	rt->data.sphere.radius = 20;
// 	rt->data.sphere.color = rgb_hex(255, 0, 0);
	
// 	rt->data.camera.cam = (t_vtr3){-50, 0, 20};
// 	rt->data.camera.dir = (t_vtr3){0, 0, 0};
// 	rt->data.camera.fov = 70;
// }

void	open_scene_file(t_rt *rt, char **av, int *i)
{
	// (void) av;
	// (void) rt;
	char	*tmp;
	int		fd;

	rt->height = 300; // 창 가로
	rt->width = 300; // 창 세로

	/* open, read */
	fd = open(av[*i], O_RDONLY);
	if (fd < 0)
		ft_exit(1, "Error\n: not exist file");
	tmp = get_next_line(fd);
	while (*tmp)
	{
		check_data_condition(rt, tmp);
		free(tmp);
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
	}

	/* 값 잘 들어어가는지 확인*/
	// printf("R width:%d, height:%d\n", rt->width, rt->height);
	// printf("A ratio:%f, color:%u\n", rt->data.ambient.ratio, rt->data.ambient.color);
	
	// printf("c cam:%f, %f, %f\n", rt->data.camera.cam.x, rt->data.camera.cam.y, rt->data.camera.cam.z);
	// printf("l position:%f, %f, %f\n", rt->data.light.position.x, rt->data.light.position.y, rt->data.light.position.z);
	// printf("l brightness:%f, color:%u\n", rt->data.light.brightness, rt->data.light.color);
	
	// printf("pl position:%f, %f, %f\n", rt->data.plane.position.x, rt->data.plane.position.y, rt->data.plane.position.z);
	// printf("pl orientation:%f, %f, %f\n", rt->data.plane.orientation.x, rt->data.plane.orientation.y, rt->data.plane.orientation.z);
	// printf("pl color:%u\n", rt->data.plane.color);
	// printf("sp center:%f, %f, %f\n", rt->data.sphere.center.x, rt->data.sphere.center.y, rt->data.sphere.center.z);
	// printf("sp radius:%f, color:%u\n", rt->data.sphere.radius, rt->data.sphere.color);
	// printf("cy center:%f, %f, %f\n", rt->data.cylinder.position.x, rt->data.cylinder.position.y, rt->data.cylinder.position.z);
	// printf("cy orientation:%f, %f, %f\n", rt->data.cylinder.orientation.x, rt->data.cylinder.orientation.y, rt->data.cylinder.orientation.z);
	// printf("cy diameter:%f, height:%f, color:%u\n", rt->data.cylinder.diameter, rt->data.cylinder.height, rt->data.cylinder.color);
}
