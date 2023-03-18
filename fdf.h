/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:20:14 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/18 20:52:18 by junyojeo         ###   ########.fr       */
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

/* PI */
# define PI_DIVIDE_6 0.5236

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

typedef struct s_map
{
	int	**map;
	int	width;
	int	length;
	int	height;
	int	z_max;
	int	z_min;
}		t_map;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}		t_point;

/* function */
void	fdf(char **argv);

void	init(t_mlx *mlx);
t_point	*init_point(int x, int y, int z);

void	parse(t_map *map, char *filename);

void	draw(t_mlx *mlx, t_map *map);
void	pixel_put(t_mlx *mlx, t_point *p);
void	bresenham(t_mlx *mlx, t_point *start, t_point *end);
int		gradient(t_point start, t_point end, t_point x);

/* utils */
void	rotate_x(int *y, int *z, double alpha);
void	rotate_y(int *x, int *z, double beta);
void	rotate_z(int *x, int *y, double gamma);
void	ft_puterror(char *str);

/* key_hook */
int		key_hook(int keycode, t_mlx *mlx);


// void	draw_map(t_mlx *mlx);
// int	create_argb(int a, int r, int g, int b);

#endif
