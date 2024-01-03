/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:25:10 by nahyulee          #+#    #+#             */
/*   Updated: 2024/01/02 22:24:05 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

// # include "mlx/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include "obj.h"
# include "vector.h"
# include "../example/minilibx-linux/mlx.h"

# include <stdio.h>

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

# ifndef M_PI
#  define M_PI	3.14159265358979323846
# endif

typedef struct s_intersect
{
	int			color;
	double		t;
	t_vtr3		normal;
	t_vtr3		hit_point;
}	t_intr;

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	char	*addr;
	void	*img_ptr;
	int		size_line;
	int		bpp;
	int		endian;
	int		width;
	int		height;
	int		line_length;
}	t_mlx;

typedef struct s_rt
{
	t_mlx	mlx;
	t_d		data;
}	t_rt;

/* ***********************util********************************************** */
int				press_key(int key_val, t_rt *rt);
int				print_error(int key_val, t_rt *rt);
int				get_color_component(int color, int shift);
unsigned int	rgb_hex(int red, int green, int blue);
void			my_mlx_pixel_put(t_rt *rt, int x, int y, int color);

/* ************************************************************************** */
void			init_mlx(t_mlx mlx);
void			rander(t_mlx mlx);
/* ***********************ray************************************************ */
void			cam_lookat(t_c cam, t_vwpl *view);

#endif
