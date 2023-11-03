/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decdel_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 02:23:08 by nahyulee          #+#    #+#             */
/*   Updated: 2023/08/21 08:57:13 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_decdel_front(t_que *lst)
{
	t_node	*tmp;

	if (lst->size == 0)
		exit(0);
	tmp = lst->front;
	lst->front = tmp->next;
	if (lst->front == NULL)
		lst->rear = NULL;
	else
		lst->front->prev = NULL;
	free(tmp);
	tmp = NULL;
	lst->size--;
}
