/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:34:30 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/18 17:37:44 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_put(t_mlx *mlx, t_point p)
{
	char	*dst;

	dst = mlx->addr + (p.y * mlx->line_length) + p.x * 4;
	*(unsigned int *)dst = p.color;
}

static void isometric(t_point dot)
{
	int		prev_x;
	int		prev_y;

	prev_x = x;
	prev_y = y;
	dot.x = (prev_x - prev_y) * cos(PI_DIVIDE_6);
	dot.y = (prev_x + prev_y) * sin(PI_DIVIDE_6) - z;
	dot.z = z;
	return (&dot);
}

static void	draw_background(t_mlx *mlx)
{
	int		x;
	int		y;

	y = -1;
	while (++y < SCRN_HEIGHT)
	{
		x = -1;
		while (++x < SCRN_WIDTH)
			pixel_put(mlx, init_point(x, y, 0));
	}
}

void	draw(t_mlx *mlx, t_map *map)
{
	int	i;
	int	j;

	draw_background(mlx);
	j = -1;
	while (++j < map->height)
	{
		i = -1;
		while (++i < map->width)
		{
			if (i < map->width - 1)
				bresenham(mlx, init_point(i, j, map->map[j][i]), \
				init_point(i + 1, j, map->map[j + 1][i]));
			if (j < map->height - 1)
				bresenham(mlx, init_point(i, j, map->map[j][i]), \
				init_point(i, j + 1, map->map[j][i + 1]));
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
