/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:20:14 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/16 17:04:12 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "get_next_line.h"
# include "lib/mlx/mlx.h"
# include "key_macros.h"
# include "math.h"
# include <unistd.h>
# include <fcntl.h>

/* SCREEN SIZE */
# define SCRN_WIDTH 1920
# define SCRN_HEIGHT 1080
# define SUB_SCRN_WIDTH 1680

/* color */
# define CLR_TEXT			0xEAEAEA
# define CLR_MAIN_SCRN_BG	0x222222
# define CLR_SUB_SCRN_BG	0x1E1E1E
# define CLR_DISCO			0x9A1F6A
# define CLR_BRICK_RED		0xC2294E
# define CLR_FLAMINGO		0xEC4B27
# define CLR_JAFFA			0xEF8633
# define CLR_SAFFRON		0xF3AF3D

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_mlx;

typedef struct s_map
{
	int	**map;
	int	width;
	int	length;
	int	height;
	int	*arr_color;
	int	*arr_z;
	int	z_max;
	int	z_min;
}		t_map;

typedef enum e_projection
{
	ISOMETRIC,
	PARALLEL
}	t_projection;

typedef struct s_camera
{
	t_projection	projection;
	int				alpha;
	int				beta;
	int				gamma;
	int				x_offset;
	int				y_offset;
	int				zoom;
	int				z_divisor;
}		t_camera;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}		t_point;

void		fdf(char **argv);
void		init(t_mlx *mlx, t_map *map, t_camera *camera);
void		init_camera(t_camera *camera);
void		parse(t_map *map, char *filename);

/* Algorithm */
void		isometric(int *x, int *y, int z);
void		my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);

// t_point		*init_point(t_map *map, int x, int y);
void		draw(t_mlx *mlx, t_map *map);
//void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);

/* color */
int get_color(t_point cur, t_point *s, t_point *f, t_point delta);
int	get_default_color(int z, t_map *map);

/* utils */
void	rotate_x(int *y, int *z, double alpha);
void	rotate_y(int *x, int *z, double beta);
void	rotate_z(int *x, int *y, double gamma);
void	ft_puterror(char *str);
// int		get_less(int a, int b);

/* key_hook */
int	key_hook(int keycode, t_mlx *mlx);


// void	draw_map(t_mlx *mlx);
// int	create_argb(int a, int r, int g, int b);

#endif
