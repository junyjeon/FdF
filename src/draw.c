/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:34:30 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/26 04:01:54 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_put(t_mlx *mlx, t_point *p)
{
	char	*dst;

	dst = mlx->addr + (p->y * mlx->line_length) + p->x * 4;
	*(unsigned int *)dst = p->color;
}

void	parallel_movement(t_map *map, int flag)
{
	int	i;
	int	j;

	j = -1;
	while (++j < map->height)
	{
		i = -1;
		while (++i < map->width)
		{
			if (flag == ORIGIN)
			{
				map->dot[j][i].x -= map->width / 2;
				map->dot[j][i].y -= map->height / 2;
			}
			else
			{
				map->dot[j][i].x += SCRN_WIDTH / 2;
				map->dot[j][i].y += SCRN_HEIGHT / 2;
			}
		}
	}
}

static void	scaling(t_map *map)
{
	int	i;
	int	j;

	j = -1;
	while (++j < map->height)
	{
		i = -1;
		while (++i < map->width)
		{
			map->dot[j][i].x *= SCRN_WIDTH / 2 / map->width;
			map->dot[j][i].y *= SCRN_HEIGHT / 2 / map->height;
			map->dot[j][i].z *= 4;
		}
	}
}

void	draw(t_mlx *mlx, t_map *map)
{
	int	i;
	int	j;

	parallel_movement(map, ORIGIN);
	scaling(map);
	isometric(map);
	parallel_movement(map, 0);
	j = -1;
	while (++j < map->height)
	{
		i = -1;
		while (++i < map->width)
		{
			if (i < map->width - 1)
				bresenham(mlx, map->dot[j][i], map->dot[j][i + 1]);
			if (j < map->height - 1)
				bresenham(mlx, map->dot[j][i], map->dot[j + 1][i]);
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
