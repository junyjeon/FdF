/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:20:14 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/27 08:07:45 by junyojeo         ###   ########.fr       */
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
# define CLR_CHROME_YELLOW	0xFFA700
# define CLR_VIVA_MAGENTA	0xBB2649
# define CLR_DEFAULT		0xFFFFFF

/* PI */
# define PI_DIVIDE_6		0.5236

/* PARALLEL_MOVEMENT */
# define ORIGIN				1

/* KEY_MACRO */
# define KEY_ESCAPE			53
# define KEY_RED_CROSS		17

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
}		t_map;

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
void	draw(t_mlx *mlx, t_map *map);
void	pixel_put(t_mlx *mlx, t_point *p);
void	parallel_movement(t_map *map, int flag);
void	bresenham(t_mlx *mlx, t_point start, t_point end);
void	isometric(t_map *map);

/* utils */
void	ft_puterror(char *str);
int		ft_atoi_base(char *str);
void	ft_free(t_map *map);

/* key_hook */
void	ft_hook(t_mlx *mlx);
int		key_press(int key_symbol, t_mlx *mlx);
int		red_cross(t_mlx *mlx);

#endif
