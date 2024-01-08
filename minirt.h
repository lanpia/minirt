/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:43:42 by soohkang          #+#    #+#             */
/*   Updated: 2024/01/05 23:13:54 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>

# include "obj.h"
# include "_vector/vector.h"

/**** **** **** DELETE after submitted ~!~!~!~!~!!!!!!!!!!!! **** **** ****/
# include <stdio.h>
# ifndef M_PI
#  define M_PI	3.14159265358979323846
# endif

# define WIDTH 800
# define HEIGHT 600

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

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	char	*addr;
	void	*img_ptr;
	int		size_line;
	int		bpp;
	int		endian;
	int		line_length;
}	t_mlx;

typedef struct s_rt
{
	t_mlx	mlx;
	t_d		data;
}	t_rt;
void			vtr3print(char *s, t_vtr3 v); // deberg
/* ***************		_parse		************************************ */
void			parse_extensions(char **av, int *i);
void			part_of_parse_extens(char **av, int **i);
t_rt			*open_scene_file(t_rt *d, char **av, int *i);
void			check_data_condition(t_rt *rt, char **data);
void			color_atoi(int color[3], char **data, int i);
void			put_r(t_mlx *mlx, char **data);
void			put_a(t_a *ambient, char **data);
void			put_c(t_c *cam, char **data);
void			put_l(t_l *light, char **data);
void			put_pl(t_pl *plane, char **data);
void			put_sp(t_sp *sphere, char **data);
void			put_cy(t_cy *cylinder, char **data);
/* ***************		_utils		************************************* */
int				press_key(int key_val, t_rt *rt);
int				print_error(int key_val, t_rt *rt);
void			init_mlx(t_mlx *mlx);
void			rander(t_rt *rt, t_mlx mlx);
void			my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
/* ***************		_raytracing		********************************* */
void			cam_lookat(t_c *cam, t_vwpl *view, double ratio);
t_ray			get_ray(t_c cam, t_vwpl viewplane, int i, int j);
void			raycast(t_d data, t_mlx *mlx);
int				intersect(t_d data);
int				phong_shading(t_d data, t_intr intr, t_ray ray, int color[3]);
/* ***************		_raytracing		********************************* */
t_intr			intersect_plane(t_pl plane, t_ray ray);
t_intr			intersect_sphere(t_sp sp, t_ray ray);


unsigned int	rgb_hex(int red, int green, int blue);

#endif
