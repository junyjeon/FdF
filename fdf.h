/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:20:14 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/23 00:39:50 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "get_next_line.h"
# include "lib/mlx/mlx.h"
# include "math.h"
# include <unistd.h>
# include <fcntl.h>

/* SCREEN SIZE */
# define SCRN_WIDTH			1920
# define SCRN_HEIGHT		1080

/* COLOR */
# define CLR_TEXT			0xEAEAEA
# define CLR_MAIN_SCRN_BG	0x222222
# define CLR_SUB_SCRN_BG	0x1E1E1E
# define CLR_DISCO			0x9A1F6A
# define CLR_BRICK_RED		0xC2294E
# define CLR_FLAMINGO		0xEC4B27
# define CLR_JAFFA			0xEF8633
# define CLR_SAFFRON		0xF3AF3D

/* PI */
# define PI_DIVIDE_6		0.5236

/* PARALLEL_MOVEMENT */
# define ORIGIN				1

/* KEY_MACRO */
# define KEY_ESCAPE			53

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_mlx;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}		t_point;

typedef struct s_map
{
	t_point	**dot;
	int		width;
	int		height;
	int		z_min;
	int		z_max;
}		t_map;

typedef struct s_bresenham
{
	int	w;
	int	h;
	int	increment_x;
	int	increment_y;
}		t_bresenham;

	/* function */
void	fdf(char **argv);

void	init(t_mlx *mlx, t_map *map, char *argv);
t_point	*init_point(int x, int y);

void	parse(t_map *map, char *argv);

void	draw(t_mlx *mlx, t_map *map);
void	pixel_put(t_mlx *mlx, t_point *p);
void	parallel_movement(t_map *map, int flag);
void	bresenham(t_mlx *mlx, t_point start, t_point end);
void	isometric(t_map *map);

/* utils */
void	rotate_x(int *y, int *z, double alpha);
void	rotate_y(int *x, int *z, double beta);
void	rotate_z(int *x, int *y, double gamma);
void	ft_puterror(char *str);
int		ft_atoi_base(char *str, char *base, int base_l);

/* key_hook */
int		key_hook(t_mlx *mlx, int keycode);

#endif
