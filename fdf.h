/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:20:14 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/15 12:54:57 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include <unistd.h>
# include <fcntl.h>

/* SCREEN SIZE */
# define SCRN_WIDTH 1920
# define SCRN_HEIGHT 1080
# define SUB_SCRN_WIDTH 1680

/* color */
# define CLR_MAIN_SCRN_BG	0x222222
# define CLR_SUB_SCRN_BG	0x1E1E1E

typedef struct s_camera
{
	int	alpha;
	int	beta;
	int	gamma;
	int	x_offset;
	int	y_offset;
	int	zoom;
	int	z_divisor;
}		t_camera;

typedef struct s_map
{
	int	**map;
	int	width;
	int	length;
}		t_map;

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	int				clr;
}		t_point;

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

void	fdf(char **argv);
void	init(t_mlx *mlx, t_map *map, t_camera *camera);
void	parse(t_map *map, char *filename);
void	ft_puterror(char *str);
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);

// void	draw_map(t_mlx *mlx);
// int	create_argb(int a, int r, int g, int b);

#endif
