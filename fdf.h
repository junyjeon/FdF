/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:20:14 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/15 20:56:37 by junyojeo         ###   ########.fr       */
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
# define SCRN_WIDTH 1920
# define SCRN_HEIGHT 1080
# define SUB_SCRN_WIDTH 1680

/* color */
# define CLR_MAIN_SCRN_BG 0x222222
# define CLR_SUB_SCRN_BG 0x1E1E1E

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
t_camera	*parse(t_map *map, char *filename);

/* Algorithm */
void		isometric(int *x, int *y, int z);
t_point		*point(t_map *map, t_camera *camera, t_point *p);

void		draw(t_mlx *mlx, t_map *map);
//void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);

/* utils */
void		ft_puterror(char *str);
int			get_abs(int a);
int			get_min(int a, int b);

// void	draw_map(t_mlx *mlx);
// int	create_argb(int a, int r, int g, int b);

#endif
