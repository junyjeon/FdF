/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:20:14 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/14 08:52:40 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include <unistd.h>
# include <fcntl.h>

# define WIDTH 1920
# define HEIGHT 1080
# define SUB_WIDTH 1680

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

typedef struct s_handle
{
}		t_handle;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*addr;
}		t_mlx;

void	fdf(char **argv);
void	init(t_mlx *mlx, t_map *map, t_camera *camera);
void	parse(t_map *map, char *filename);
void	ft_puterror(char *str);
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);

// void	draw_map(t_mlx *mlx);
// int	create_argb(int a, int r, int g, int b);

#endif
