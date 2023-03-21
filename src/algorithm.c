/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:21:18 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/21 23:40:46 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_map *map)
{
	int	prev_x;
	int	prev_y;
	int	i;
	int	j;

	j = -1;
	while (++j < map->height)
	{
		i = -1;
		while (++i < map->width)
		{
			prev_x = map->dot[j][i].x;
			prev_y = map->dot[j][i].y;
			map->dot[j][i].x = (prev_x - prev_y) * cos(PI_DIVIDE_6);
			map->dot[j][i].y = (prev_x + prev_y) * sin(PI_DIVIDE_6) \
			- map->dot[j][i].z;
		}
	}
}

static void	slope_lower_than_one(t_mlx *mlx, t_point start, \
t_point end, t_bresenham br)
{
	int	f;

	if ((0 <= start.x && start.x <= SCRN_WIDTH) && \
	(0 <= start.y && start.y <= SCRN_HEIGHT))
		pixel_put(mlx, &start);
	f = 2 * br.h - br.w;
	while (start.x != end.x)
	{
		if (f >= 0)
		{
			start.y += br.increment_y;
			f -= 2 * br.w;
		}
		start.x += br.increment_x;
		f += 2 * br.h;
		if ((0 <= start.x && start.x <= SCRN_WIDTH) && \
		(0 <= start.y && start.y <= SCRN_HEIGHT))
			pixel_put(mlx, &start);
	}
}

static void	slope_upper_than_one(t_mlx *mlx, t_point start, \
t_point end, t_bresenham br)
{
	int	f;

	if ((0 <= start.x && start.x <= SCRN_WIDTH) && \
	(0 <= start.y && start.y <= SCRN_HEIGHT))
		pixel_put(mlx, &start);
	f = 2 * br.w - br.h;
	while (start.y != end.y)
	{
		if (f >= 0)
		{
			start.x += br.increment_x;
			f -= 2 * br.h;
		}
		start.y += br.increment_y;
		f += 2 * br.w;
		if ((0 <= start.x && start.x <= SCRN_WIDTH) && \
		(0 <= start.y && start.y <= SCRN_HEIGHT))
			pixel_put(mlx, &start);
	}
}

static void	nagative_increase(int *delta, int *increment)
{
	*delta *= -1;
	*increment *= -1;
}

void	bresenham(t_mlx *mlx, t_point start, t_point end)
{
	t_bresenham	br;

	br.w = end.x - start.x;
	br.h = end.y - start.y;
	br.increment_x = 1;
	br.increment_y = 1;
	if (br.w < 0)
		nagative_increase(&br.w, &br.increment_x);
	if (br.h < 0) 
		nagative_increase(&br.h, &br.increment_y);
	if (br.h > br.w)
		slope_upper_than_one(mlx, start, end, br);
	else
		slope_lower_than_one(mlx, start, end, br);
}
