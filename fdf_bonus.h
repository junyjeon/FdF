/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:20:14 by junyojeo          #+#    #+#             */
/*   Updated: 2023/05/19 01:09:01 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include "libft.h"
# include "get_next_line.h"
# include "lib/mlx/mlx.h"
# include <math.h>
# include <unistd.h>
# include <fcntl.h>

/* SCREEN SIZE */
# define SCRN_WIDTH			1920
# define SCRN_HEIGHT		1080

/* COLOR */
# define CLR_CHROME_YELLOW	0xFFA700
# define CLR_VIVA_MAGENTA	0xBB2649
# define CLR_DEFAULT		0xFFFFFF

/* PARALLEL_MOVEMENT */
# define ORIGIN				1

/* KEY_MACRO */
# define KEY_RED_CROSS		17
# define KEY_RED_CROSS		17
# define KEY_ESCAPE			53

# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2

# define KEY_U		32
# define KEY_J		38
# define KEY_I		34
# define KEY_K		40
# define KEY_O		31
# define KEY_L		37

# define KEY_MINUS	27
# define KEY_EQUAL	24
# define KEY_SPACE	49

typedef enum	e_projection
{
	PARALLE,
	ISO
}		t_projection;

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
}		t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		offset_x;
	int		offset_y;
	float	alpha;
	float	beta;
	float	gamma;
	int		zoom;
	t_projection	projection;
	t_map	map;
}		t_mlx;

typedef struct s_bresenham
{
	int	w;
	int	h;
	int	increment_x;
	int	increment_y;
}		t_bresenham;

/* functions */
void	fdf(char **argv);

/* init */
void	init(t_mlx *mlx, char *argv);

/* parse */
void	parse(t_map *map, char *argv);

/* draw */
void	draw(t_mlx *mlx);
void	pixel_put(t_mlx *mlx, t_point *p);
void	parallel_movement(t_map *map, int flag);
void	bresenham(t_mlx *mlx, t_point start, t_point end);

/* utils */
void	ft_puterror(char *str);
int		ft_atoi_base(char *str);

/* key_hook */
void	ft_hook(t_mlx *mlx);
int		my_key_hook(int key, t_mlx *mlx);
int		key_press(int key_symbol, t_mlx *mlx);
int		red_cross(t_mlx *mlx);

void	rotate_x(int *y, int *z, double alpha);
void	rotate_y(int *x, int *z, double beta);
void	rotate_z(int *x, int *y, double gamma);

#endif
