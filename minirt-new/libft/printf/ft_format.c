/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:54:57 by nahyulee          #+#    #+#             */
/*   Updated: 2023/05/19 17:55:12 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_c(char c, int *i)
{
	(*i)++;
	write(1, &c, 1);
}

void	ft_s(char *s, int *i)
{
	int		strlen;

	if (!s)
		s = "(null)";
	strlen = (int)ft_strlen(s);
	*i += strlen;
	write(1, s, strlen);
}

void	ft_p(t_ul p, int *i)
{
	if (p >= 16)
		ft_p(p / 16, i);
	write(1, &"0123456789abcdef"[p % 16], 1);
	(*i)++;
}

void	ft_x(t_ui x, int *i)
{
	if (x >= 16)
		ft_x(x / 16, i);
	write(1, &"0123456789abcdef"[x % 16], 1);
	(*i)++;
}

void	ft_lx(t_ui X, int *i)
{
	if (X >= 16)
		ft_lx(X / 16, i);
	write(1, &"0123456789ABCDEF"[X % 16], 1);
	(*i)++;
}
