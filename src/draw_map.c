/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:34:30 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/16 15:15:28 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** quadrant 1, 4, 5, 8(delta.x > delta.y): sample by x
** quadrant 2, 3, 6, 7(delta.x < delta.y): sample by y
*/

// int width = abs(endPosition.X - startPosition.X);
// int height = abs(endPosition.Y - startPosition.Y);

// SetPixel(startPosition, InColor);
// int x = startPosition.X;
// int y = startPosition.Y;

// int YValue = InEndPos.Y >= 0 ? -1 : 1;
// int XValue = InEndPos.X >= 0 ? 1 : -1;

// // 1,4,5,8 팔분면일 경우
// if (width > height)
// {
// 	int det = (2 * height) - width; // 판별식
// 	for (x = startPosition.X; x != endPosition.X; x += XValue)
// 	{
// 		if (det < 0)
// 		{
// 			det += 2 * height;
// 		}
// 		else
// 		{
// 			y += YValue;
// 			det += (2 * height - 2 * width);
// 		}
// 		SetPixel(ScreenPoint(x, y), InColor);
// 	}
// }
// // 2,3,6,7 팔분면일 경우
// else
// {
// 	int det = (2 * width) - height; // 판별식
// 	for (y = startPosition.Y; y != endPosition.Y; y += YValue)
// 	{
// 		if (det < 0)
// 		{
// 			det += 2 * width;
// 		}
// 		else
// 		{
// 			x += XValue;
// 			det += (2 * width - 2 * height);
// 		}
// 		SetPixel(ScreenPoint(x, y), InColor);
// 	}
// }

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

/*
** bits per pixel: 32(4 bytes; int)
** line_length: 4000
*/

/*
algorithm Bresenham(x1, y1, x2, y2)
{
	x = x1;
	y = y1;
	dx = x2 - x1;
	dy = y2 - y1;
	F = 2 * dx - dy;
	while (x <= x2)
	{
		put_pixel(x, y);
		++x;
		if (F < 0)
			F = F + 2 * dy;
		else
		{
			F = F + 2 * dy - 2 * dx;
			++y;
		}
}
*/

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
				my_mlx_pixel_put(mlx, x, y, CLR_TEXT);
			}
			// draw_line(mlx, point(map, camera, init_point(map, x, y)), point(map, camera, init_point(map, x + 1, y)));
			if (y < map->height - 1)
			{
				my_mlx_pixel_put(mlx, x, y, CLR_TEXT);
			}
			// draw_line(mlx, point(map, camera, init_point(map, x, y)), point(map, camera, init_point(map, x, y + 1)));
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
