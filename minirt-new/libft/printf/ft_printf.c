/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 04:15:23 by nahyulee          #+#    #+#             */
/*   Updated: 2023/05/19 17:55:12 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_format(char c, va_list va, int *result)
{
	if (c == '%')
	{
		(*result)++;
		write(1, "%", 1);
	}
	else if (c == 'c')
		ft_c(va_arg(va, int), result);
	else if (c == 's')
		ft_s(va_arg(va, char *), result);
	else if (c == 'u')
		ft_u(va_arg(va, t_ui), result);
	else if (c == 'i' || c == 'd')
		ft_di(va_arg(va, int), result);
	else if (c == 'x')
		ft_x(va_arg(va, t_ul), result);
	else if (c == 'X')
		ft_lx(va_arg(va, t_ul), result);
	else if (c == 'p')
	{
		write(1, "0x", 2);
		ft_p(va_arg(va, t_ul), result);
		(*result) += 2;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	va;	
	int		result;
	int		i;

	i = 0;
	result = 0;
	va_start(va, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			write(1, format + i, 1);
			result++;
			i++;
		}
		else
		{
			i++;
			ft_format(*(format + i), va, &result);
			i++;
		}
	}
	va_end(va);
	return (result);
}
