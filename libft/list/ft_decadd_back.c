/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_decadd_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 02:29:01 by nahyulee          #+#    #+#             */
/*   Updated: 2023/05/20 02:36:04 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_decadd_back(t_que *lst, void *value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->content = value;
	new_node->prev = lst->rear;
	new_node->next = NULL;
	if (lst->size == 0)
		lst->front = new_node;
	else
		lst->rear->next = new_node;
	lst->rear = new_node;
	lst->size++;
}
