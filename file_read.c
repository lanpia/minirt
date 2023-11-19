/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:16:44 by nahyulee          #+#    #+#             */
/*   Updated: 2023/11/17 13:18:24 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	make_array(t_rt *d)
{
	d = (t_rt *)ft_calloc(sizeof(t_rt), 1);
	d->data = (t_d *)ft_calloc(sizeof(t_d), 1);
	d->data->c = (float *)ft_calloc(sizeof(float), )
}

void	read_data(t_d *data)
