/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohkang <soohkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:59:35 by soohkang          #+#    #+#             */
/*   Updated: 2023/12/04 17:03:07 by soohkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	parse_extens(char **av)
{
	int			last_i;
	int			f_len;
	int			j;
	int			flag;
	int		i;

	i = 1;
	if (!ft_strcmp(av[i], "--save"))
		i++;

	f_len = ft_strlen(av[i]);
	last_i = f_len--;
	last_i--;
	flag = 0;
	if (av[i][last_i] == 't' && av[i][last_i - 1] == 'r' && av[i][last_i - 2] == '.')
	{
		j = -1;
		while (++j < (last_i - 3))
		{
			if (av[i][j] == '.' && av[i][j + 1] == 'r' && av[i][j + 2] == 't')
			{
				flag = 1;
				break ;
			}
		}
	}
	else
		printf("Error\n:File '%s' is not a valid .rt file\n", av[i]);
	if (flag == 1)
		printf("Error\n:The '%s' contains .rt multiple times.\n", av[i]);
}