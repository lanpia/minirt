/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:25:10 by nahyulee          #+#    #+#             */
/*   Updated: 2023/11/17 13:17:23 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "minilibx_opengl_20191021/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_EXIT		17
# define KEY_ESC				53

# define KEY_W					13
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2
# define KEY_UP					126
# define KEY_LEFT				123
# define KEY_DOWN				125
# define KEY_RIGHT				124
// 3차원 벡터를 표현하는 구조체
typedef struct s_vector3D
{
	float	x;
	float	y;
	float	z;
}	t_vctr3;

typedef struct s_data
{
	float	*c;
	float	*l;
	float	*pl;
	float	*sp;
	float	*sq;
	float	*cy;
	float	*tr;
}	t_d;

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	int		width;
	int		height;
	t_d		*data;
}	t_rt;

void	make_array(t_rt *d);

#endif