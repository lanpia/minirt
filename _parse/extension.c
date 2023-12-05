/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohkang <soohkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:59:35 by soohkang          #+#    #+#             */
/*   Updated: 2023/12/04 23:39:00 by soohkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	part_of_parse_extens(char **av, int **i)
{
	if (!ft_strcmp(av[**i], "--save"))
		(*i)++;
	if (ft_strnstr(av[**i], ".rt", ft_strlen(av[**i])) == NULL)
		ft_exit(1, "Error\nFile is not .rt\n");
}

void	parse_extens(char **av, int *i)
{
	int	last_i;
	int	j;
	int	flag;

	part_of_parse_extens(av, &i);
	last_i = ft_strlen(av[*i]);
	last_i--;
	flag = 0;
	if (av[*i][last_i] == 't' && av[*i][last_i - 1] == 'r' && av[*i][last_i - 2] == '.')
	{
		j = -1;
		while (++j < (last_i - 3))
		{
			if (av[*i][j] == '.' && av[*i][j + 1] == 'r' && av[*i][j + 2] == 't')
			{
				flag = 1;
				break ;
			}
		}
	}
	else
		ft_exit(1, "Error\n:File '%s' is not a valid .rt file\n"); //av[i]
	if (flag == 1)
		ft_exit(1, "Error\n:The '%s' contains .rt multiple times.\n"); //av[i]
}
