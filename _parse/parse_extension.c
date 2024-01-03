/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:59:35 by soohkang          #+#    #+#             */
/*   Updated: 2024/01/03 02:43:36 by nahyulee         ###   ########.fr       */
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

void	parse_extensions(char **av, int *i)
{
	int	last_i;
	int	j;

	part_of_parse_extens(av, &i);
	last_i = ft_strlen(av[*i]) - 1;
	if (av[*i][last_i] == 't' && av[*i][last_i - 1] == 'r' && \
		av[*i][last_i - 2] == '.')
	{
		j = -1;
		while (++j < (last_i - 3))
		{
			if (av[*i][j] == '.' && av[*i][j + 1] == 'r' && \
				av[*i][j + 2] == 't')
			{
				ft_exit(1, "Error\n:File name contains .rt multiple times");
			}
		}
	}
	else
		ft_exit(1, "Error\n:File name is not a valid .rt file");
}
