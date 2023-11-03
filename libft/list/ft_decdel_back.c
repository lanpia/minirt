/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decdel_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 02:24:05 by nahyulee          #+#    #+#             */
/*   Updated: 2023/08/21 08:57:23 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_decdel_back(t_que *lst)
{
	t_node	*tmp;

	if (lst->size == 0)
		exit(0);
	tmp = lst->rear;
	lst->rear = tmp->prev;
	if (lst->rear == NULL)
		lst->front = NULL;
	else
		lst->rear->next = NULL;
	free(tmp);
	tmp = NULL;
	lst->size--;
}
