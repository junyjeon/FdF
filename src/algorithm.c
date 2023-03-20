/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:21:18 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/20 09:19:18 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//static void	less_one(t_mlx *mlx, t_map *map, t_point *start, t_point *end)
//{
//	int	p;
//	int	inc_x;
//	int	inc_y;

//	inc_x = 1;
//	inc_y = 1;
//	if (start->x > end->x)
//		inc_x = -1;
//	if (start->y > end->y)
//		inc_y = -1;
//	p = 2 * abs(end->x - start->x) - abs(end->y - start->y);
//	while (start->x != end->x && (start->x < SCRN_WIDTH && start->y < SCRN_HEIGHT))
//	{
//		if (start->x >= 0 && start->y >= 0)
//			pixel_put(mlx, init_point(map, start->x, start->y, map->map[start->x][start->y]));
//		start->x += inc_x;
//		if (p < 0)
//			p = p + 2 * abs(end->y - start->y);
//		else
//		{
//			p = p + 2 * abs(end->y - start->y) - 2 * abs(end->x - start->x);
//			start->y += inc_y;
//		}
//	}
//}

//static void	more_one(t_mlx *mlx, t_map *map, t_point *start, t_point *end)
//{
//	int	p;
//	int	inc_x;
//	int	inc_y;

//	inc_x = 1;
//	inc_y = 1;
//	if (start->x > end->x)
//		inc_x = -1;
//	if (start->y > end->y)
//		inc_y = -1;
//	p = 2 * abs(end->y - start->y) - abs(end->x - start->x);
//	while (start->y != end->y && (start->x < SCRN_WIDTH && start->y < SCRN_HEIGHT))
//	{
//		if (start->x >= 0 && start->y >= 0)
//			pixel_put(mlx, init_point(map, start->x, start->y, map->map[start->x][start->y]));
//		start->y += inc_y;
//		if (p < 0)
//			p = p + 2 * abs(end->x - start->x);
//		else
//		{
//			p = p + 2 * abs(end->x - start->x) - 2 * abs(end->y - start->y);
//			start->x += inc_x;
//		}
//	}
//}

static void	draw_horizon(t_mlx *mlx, t_map *map, t_point *start, t_point *end)
{
	int	i;

	i = start->x - 1;
	while (++i < end->x && i != SCRN_WIDTH)
		pixel_put(mlx, i, start->y, start->color);
}

static void	draw_vertical(t_mlx *mlx, t_point *start, t_point *end)
{
	int	i;

	i = start->y - 1;
	while (++i < end->y && i != SCRN_HEIGHT)
		pixel_put(mlx, start->x, i, start->color);
}

void	bresenham(t_mlx *mlx, t_point *start, t_point *end)
{
	if (end->y - start->y == 0)
		draw_horizon(mlx, start, end);
	else if (end->x - start->x == 0)
		draw_vertical(mlx, start, end);
	else if (abs(end->y - start->y) < abs(end->x - start->x))
		less_one(mlx, start, end);
	else
		more_one(mlx, start, end);
}

void bresenham(int x0, int y0, int x1, int y1)
{
	int dx = abs(x1 - x0);
	int dy = -abs(y1 - y0);

	int sx = x0 < x1 ? 1 : -1;
	int sy = y0 < y1 ? 1 : -1;
	int err = dx + dy; // error value e_xy
	while (true)
	{
		pixel_put(mlx, x0, y0, map->dot[(map->width * y0) + x0]->color);
		if (x0 == x1 && y0 == y1)
			break;
		int e2 = 2 * err;
		if (e2 >= dy) // e_xy+e_x > 0
			err += dy;
		x0 += sx;
		if (e2 <= dx) // e_xy+e_y < 0
			err += dx;
		y0 += sy;
	}
}