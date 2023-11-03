/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_decadd_front.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 02:27:54 by nahyulee          #+#    #+#             */
/*   Updated: 2023/05/20 02:36:18 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_decadd_front(t_que *lst, void *value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->content = value;
	new_node->next = lst->front;
	if (lst->size == 0)
		lst->rear = new_node;
	else
		lst->front->prev = new_node;
	lst->front = new_node;
	lst->size++;
}
