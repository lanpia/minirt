/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 00:48:41 by nahyulee          #+#    #+#             */
/*   Updated: 2023/09/29 00:49:34 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	countlen(int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_ltoa(int nn)
{
	long long	nb;
	long long	n;
	int			len;
	char		*num;

	n = nn;
	len = countlen(n) + (n <= 0);
	nb = n * (n > 0) - n * (n < 0);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (NULL);
	num[len] = '\0';
	if (n < 0)
		num[0] = '-';
	if (!n)
		num[0] = '0';
	while (nb > 0)
	{
		num[--len] = nb % 10 + '0';
		nb /= 10;
	}
	return (num);
}
