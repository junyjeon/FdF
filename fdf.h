/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:20:14 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/12 15:56:25 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include <unistd.h>
# include <fcntl.h>

# define WIDTH 256
# define HEIGHT 256

typedef struct s_camera
{
}		t_camera;

typedef struct s_map
{
	int		width;
	int		height;
	char	**line;
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
void	init(t_mlx *mlx);
void	parse_map(t_map *map, char *filename);
void	ft_puterror(char *str);
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);

// void	draw_map(t_mlx *mlx);
// int	create_argb(int a, int r, int g, int b);

#endif
