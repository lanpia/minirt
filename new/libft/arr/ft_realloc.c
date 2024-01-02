/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:00:41 by nahyulee          #+#    #+#             */
/*   Updated: 2023/08/27 02:20:16 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_realloc(void *ptr, ssize_t old_size, ssize_t size)
{
	void	*new_ptr;

	if (size <= 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = ft_calloc(sizeof(*ptr), size);
	if (new_ptr == NULL)
		return (NULL);
	if (ptr != NULL)
	{
		if (old_size > size)
			old_size = size;
		ft_memcpy(new_ptr, ptr, old_size * sizeof(*ptr));
		free(ptr);
	}
	return (new_ptr);
}

// void	*ft_realloc(void *ptr, size_t size)
// {
// 	void	*new_ptr;
// 	size_t	old_size;
// 	size_t	copy_size;

// 	if (size == 0)
// 	{
// 		free(ptr);
// 		return (NULL);
// 	}
// 	new_ptr = ft_calloc(size, 1);
// 	if (new_ptr == NULL)
// 		return (NULL);
// 	if (ptr != NULL)
// 	{
// 		old_size = 0;
// 		ft_memcpy(&old_size, (char *)ptr - sizeof(size_t), sizeof(size_t));
// 		copy_size = size;
// 		if (size > old_size)
// 			copy_size = old_size;
// 		ft_memcpy(new_ptr, ptr, copy_size);
// 		free(ptr);
// 	}
// 	ft_memcpy((char *)new_ptr - sizeof(size_t), &size, sizeof(size_t));
// 	return (new_ptr);
// }