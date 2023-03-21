/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:34:30 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/21 18:36:31 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_put(t_mlx *mlx, t_point *p)
{
	char	*dst;

	dst = mlx->addr + (p->y * mlx->line_length) + p->x * 4;
	*(unsigned int *)dst = p->color;
}

static void	draw_background(t_mlx *mlx, t_map *map)
{
	int		i;
	int		j;

	j = -1;
	while (++j < SCRN_HEIGHT)
	{
		i = -1;
		while (++i < SCRN_WIDTH)
			pixel_put(mlx, init_point(map, i, j));
	}
}

void	draw(t_mlx *mlx, t_map *map)
{
	int	i;
	int	j;

	draw_background(mlx, map);
	j = -1;
	while (++j < map->height)
	{
		i = -1;
		while (++i < map->width)
		{
			if (i < map->width - 1)
				bresenham(mlx, map->dot[(map->width * j) + i], \
				map->dot[(map->width * j) + i + 1]);
			if (j < map->height - 1)
				bresenham(mlx, map->dot[(map->width * j) + i], \
				map->dot[(map->width * (j + 1)) + i]);
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
