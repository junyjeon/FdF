/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:34:30 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/16 17:26:38 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// static void	put_pixel(t_mlx *mlx, int x, int y, int color)
// {
// 	int	i;

// 	if ((SUB_SCRN_WIDTH <= x && x < SCRN_WIDTH) && 0 <= y && y < SCRN_HEIGHT)
// 	{
// 		i = (x * mlx->bits_per_pixel / 8) + (y * mlx->line_length);
// 		mlx->addr[i] = color;
// 		mlx->addr[++i] = color >> 8;
// 		mlx->addr[++i] = color >> 16;
// 	}
// }

// static void init_delta(t_point *px, t_point *py, t_point *delta, t_point *step)
// {
// 	delta->x = abs(py->x - px->x);
// 	delta->y = abs(py->y - px->y);
// 	if (px->x < py->x)
// 		step->x = 1;
// 	else
// 		step->x = -1;
// 	if (px->y < py->y)
// 		step->y = 1;
// 	else
// 		step->y = -1;
// }

// static void	draw_line(t_mlx *mlx, t_point *s, t_point *f)
// {
// 	t_point	delta;
// 	t_point	step;
// 	t_point	cur;
// 	int		err[2];

// 	init_delta(s, f, &delta, &step);
// 	err[0] = delta.x - delta.y;
// 	cur = *s;
// 	while (cur.x != f->x || cur.y != f->y)
// 	{
// 		put_pixel(mlx, cur.x, cur.y, get_color(cur, s, f, delta));
// 		err[1] = err[0] * 2;
// 		if (err[1] < delta.x)
// 		{
// 			err[0] += delta.x;
// 			cur.y += step.y;
// 		}
// 		if (err[1] > -delta.y)
// 		{
// 			err[0] -= delta.y;
// 			cur.x += step.x;
// 		}
// 	}
// 	free(s);
// 	s = NULL;
// 	free(f);
// 	f = NULL;
// }

static void	draw_background(t_mlx *mlx)
{
	int	i;
	int	*img;

	img = (int *)(mlx->addr);
	i = -1;
	while (++i < SCRN_WIDTH * SCRN_WIDTH)
	{
		if (i % SCRN_WIDTH < SUB_SCRN_WIDTH)
			img[i] = CLR_SUB_SCRN_BG;
		else
			img[i] = CLR_MAIN_SCRN_BG;
	}
}

void	draw(t_mlx *mlx, t_map *map)
{
	int	x;
	int	y;

	draw_background(mlx);
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (x < map->width - 1)
			{
				isometric(&x, &y, map->map[x][y]);
				bresenham(mlx, x, y, x + 1, y);
			}
			// draw_line(mlx, point(map, camera, init_point(map, x, y)), point(map, camera, init_point(map, x + 1, y)));
			if (y < map->height - 1)
			{
				isometric(&x, &y, map->map[x][y]);
				bresenham(mlx, x, y, x + 1, y);
			}
			// draw_line(mlx, point(map, camera, init_point(map, x, y)), point(map, camera, init_point(map, x, y + 1)));
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
