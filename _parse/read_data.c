/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohkang <soohkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:16:44 by nahyulee          #+#    #+#             */
/*   Updated: 2023/12/04 22:04:50 by soohkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../mlx/mlx.h"

void	read_data(t_rt *rt, char **av)
{
	// (void) rt;
	// char	*tmp;
	// int		fd;
	int		i;

	i = 1;
	if (!ft_strcmp(av[i], "--save"))
		i++;

	rt->height = 300; // 창 가로
	rt->width = 300; // 창 세로
	sphere(rt);
	
	// fd = open(av[i], O_RDONLY);
	// tmp = get_next_line(fd);
	// while (*tmp)
	// {
	// 	check_data_condition(rt, tmp);
	// 	free(tmp);
	// 	tmp = get_next_line(fd);
	// }
}

void	check_data_condition(t_rt *rt, char *tmp)
{
	if (!ft_strnstr(tmp, "R", ft_strlen(tmp)))
		put_r(rt, tmp);
	else if (!ft_strnstr(tmp, "A", ft_strlen(tmp)))
		put_a(rt, tmp);
	// else if (!ft_strnstr(tmp, "c", ft_strlen(tmp)))
	// 	put_c(rt, tmp);
	// else if (!ft_strnstr(tmp, "l", ft_strlen(tmp)))
	// 	put_l(rt, tmp);
	// else if (!ft_strnstr(tmp, "pl", ft_strlen(tmp)))
	// 	put_pl(rt, tmp);
	// else if (!ft_strnstr(tmp, "sp", ft_strlen(tmp)))
	// 	put_sp(rt, tmp);
	// else if (!ft_strnstr(tmp, "cy", ft_strlen(tmp)))
	// 	put_cy(rt, tmp);
	// else if (!ft_strnstr(tmp, "sq", ft_strlen(tmp)))
	// 	put_sq(rt, tmp);
	// else if (!ft_strnstr(tmp, "tr", ft_strlen(tmp)))
	// 	put_tr(rt, tmp);
	else
		ft_exit(1, "Error\nData is not exist\n");
}

void	put_r(t_rt *rt, char *tmp)
{
	char	**data;
	int		i;

	data = ft_split_bonus(tmp, " \t\n,");
	if (data[0][0] == 'R')
	{
		rt->width = ft_atoi(data[1]);
		rt->height = ft_atoi(data[2]);
	}
	else
		ft_exit(1, "Error\nR is not exist\n");
	i = 0;
	while (data[i])
		i++;
	ft_2d_arr_free(data, i);
}

void	put_a(t_rt *rt, char *tmp)
{
	char	**data;
	int		i;

	data = ft_split_bonus(tmp, " \t\n,");
	if (data[0][0] == 'A')
	{
		rt->data.ambient.ratio = ft_atof(data[1]);
		rt->data.ambient.ratio = atof(data[1]); //ft_atof로 변경하세용, 나중에 만드세용 수캉
		rt->data.ambient.color = rgb_hex(ft_atoi(data[2]), ft_atoi(data[3]), ft_atoi(data[4]));
	}
	else
		ft_exit(1, "Error\nA is not exist\n");
	i = 0;
	while (data[i])
		i++;
	ft_2d_arr_free(data, i);
}

unsigned int	rgb_hex(int red, int green, int blue)
{
	unsigned int	color;

	color = (red << 16) | (green << 8) | blue;
	return (color);
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