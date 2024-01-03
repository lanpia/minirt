/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_open_scene_file.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:16:44 by nahyulee          #+#    #+#             */
/*   Updated: 2024/01/03 14:52:15 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_rt	*open_scene_file(t_rt *rt, char **av, int *i)
{
	char	**data;
	char	*tmp;
	int		fd;
	int		len;

	fd = open(av[*i], O_RDONLY);
	if (fd < 0)
		ft_exit(1, "Error\n: not exist file");
	tmp = get_next_line(fd);
	while (tmp)
	{
		data = ft_split_bonus(tmp, " \t\n,");
		if (*data)
			check_data_condition(rt, data);
		free(tmp);
		len = 0;
		while (data[len])
			len++;
		ft_2d_arr_free(data, len);
		tmp = get_next_line(fd);
	}
	free(tmp);
	return (rt);
}

void	check_data_condition(t_rt *rt, char **data)
{
	if (ft_strcmp("A", data[0]) == 0)
		put_a(&rt->data.ambient, data);
	else if (ft_strcmp("c", data[0]) == 0)
		put_c(&rt->data.camera, data);
	else if (ft_strcmp("l", data[0]) == 0)
		put_l(&rt->data.light, data);
	else if (ft_strcmp("pl", data[0]) == 0)
	{
		rt->data.obj_cnt[plane] += 1;
		put_pl(&rt->data.plane, data);
	}
	else if (ft_strcmp("sp", data[0]) == 0)
	{
		rt->data.obj_cnt[sphere] += 1;
		put_sp(&rt->data.sphere, data);
	}
	else if (ft_strcmp("cy", data[0]) == 0)
	{
		rt->data.obj_cnt[cylinder] += 1;
		// ㅈㅏ료형을 바꿔야한다??? >>> 여러개의 실린더를 어떤 자료형으로 처리할지
		put_cy(&rt->data.cylinder, data);
	}
	else
		return ;
}

void	color_atoi(int color[3], char **data, int i)
{
	int	j;

	j = 0;
	while (j < 3)
	{
		color[j] = ft_atoi(data[i + j]);
		if (ft_compare_int(color[j], 0, 255) == false)
			ft_exit(1, "Error\n:Color is not between 0 and 255.\n");
		j++;
	}
}

void	put_a(t_a *ambient, char **data)
{
	if (ft_strcmp("A", data[0]) == 0)
	{
		ambient->ratio = ft_atof(data[1]);
		if (ft_compare_int(ambient->ratio, 0, 1) == false)
			ft_exit(1, "Error\n:Ambient ratio is not between 0 and 1.\n");
		color_atoi(ambient->color, data, 2);
	}
	else
		ft_exit(1, "Error\nA is not exist\n");
}
