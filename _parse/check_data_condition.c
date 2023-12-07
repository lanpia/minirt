/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data_condition.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 03:15:07 by soohkang          #+#    #+#             */
/*   Updated: 2023/12/07 16:27:06 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	check_data_condition(t_rt *rt, char *tmp)
{
	// printf("tmp:%s", tmp);

	if (ft_strnstr(tmp, "R", ft_strlen(tmp)))
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
	// int		i;

	data = ft_split_bonus(tmp, " \t\n,");
	if (data[0][0] == 'R')
	{
		// printf(">>>> 1 >>>>> width:%s, height:%s\n", data[1], data[2]); // R 뒤의 값 출력
		rt->width = ft_atoi(data[1]);
		rt->height = ft_atoi(data[2]);
		// printf(">>>> 2 >>>>> width:%d, height:%d\n", rt->width, rt->height); // 출력되는 것 확인
	}
	else
		ft_exit(1, "Error\nR is not exist\n");
	// i = 0;
	// while (data[i])
	// 	i++;
	// ft_2d_arr_free(data, i);
}

void	put_a(t_rt *rt, char *tmp)
{
	char	**data;
	int		i;

	data = ft_split_bonus(tmp, " \t\n,");
	if (data[0][0] == 'A')
	{
		rt->data.ambient.ratio = ft_atof(data[1]);
		rt->data.ambient.ratio = ft_atof(data[1]);
		rt->data.ambient.color = rgb_hex(ft_atoi(data[2]), ft_atoi(data[3]), ft_atoi(data[4]));
	}
	else
		ft_exit(1, "Error\nA is not exist\n");
	i = 0;
	while (data[i])
		i++;
	ft_2d_arr_free(data, i);
}
