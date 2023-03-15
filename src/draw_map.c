/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:34:30 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/15 18:45:50 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	get_ratio(int s, int f, int cur)
{
	double	ratio;

	if (s == f)
		return (1.0);
	ratio = (double)(cur - s) / (f - s);
	return (ratio);
}

//static int	process_lerp(int s, int f, double ratio)
//{
//	return ((int)((ratio) * s + (1 - ratio) * f));
//}

/*
** quadrant 1, 4, 5, 8(delta.x > delta.y): sample by x
** quadrant 2, 3, 6, 7(delta.x < delta.y): sample by y
*/

//int	get_clr(t_point cur, t_point *s, t_point *f, t_point delta)
//{
//	double	ratio;
//	int		red;
//	int		green;
//	int		blue;

//	if (cur.clr == f->clr)
//		return (cur.clr);
//	if (delta.x > delta.y)
//		ratio = get_ratio(s->x, f->x, cur.x);
//	else
//		ratio = get_ratio(s->y, f->y, cur.y);
//	red = process_lerp((f->clr >> 16) & 0xFF, (s->clr >> 16) & 0xFF, ratio);
//	green = process_lerp((f->clr >> 8) & 0xFF, (s->clr >> 8) & 0xFF, ratio);
//	blue = process_lerp(f->clr & 0xFF, s->clr & 0xFF, ratio);
//	return ((red << 16) | (green << 8) | blue);
//}

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

int create_argb(int a, int r, int g, int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

//void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
//{
//	int	*dst;

//	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
//	*(unsigned int*)dst = color;
//}

static void	put_pixel(t_mlx *mlx, int x, int y, int color)
{
	int	 *i;

	if ((SUB_SCRN_WIDTH <= x && x < SCRN_WIDTH) && (0 <= y && y < SCRN_HEIGHT))
	{
		i = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
		*(unsigned int *)i = create_argb();
	}
}

static void init_delta(t_point *px, t_point *py, t_point *delta, t_point *step)
{
	delta->x = get_abs(py->x - px->x);
	delta->y = get_abs(py->y - px->y);
	if (px->x < py->x)
		step->x = 1;
	else
		step->x = -1;
	if (px->y < py->y)
		step->y = 1;
	else
		step->y = -1;
}

static void	draw_line(t_mlx *mlx, t_point *px, t_point *py)
{
	t_point delta;
	t_point	step;
	t_point	cur;
	int		err[2];

	init_delta(px, py, &delta, &step);
	err[0] = delta.x - delta.y;
	cur = *px;
	while (cur.x != py->x || cur.y != py->y)
	{
		put_pixel(mlx, cur.x, cur.y, get_clr(cur, px, py, delta));
		err[1] = err[0] * 2;
		if (err[1] < delta.x)
		{
			err[0] += delta.x;
			cur.y += step.y;
		}
		if (err[1] > -delta.y)
		{
			err[0] -= delta.y;
			cur.x += step.x;
		}
	}
	free(px);
	px = NULL;
	free(py);
	py = NULL;
}

static void	draw_background(t_mlx *mlx)
{
	int	i;
	int	*img;

	img = (int *)(mlx->addr);
	i = -1;
	while (++i < SCRN_WIDTH * SCRN_HEIGHT)
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

void	draw(t_mlx *mlx, t_map *map, t_camera *camera)
{
	int	x;
	int	y;

	draw_background(mlx);
	y = -1;
	while (++y < map->length)
	{
		x = -1;
		while (++x < map->width)
		{
			if (x < map->width - 1)
			{
				draw_line(mlx, point(mlx, camera, init_point(x, y, map), \
				point(mlx, camera, init_point(x + 1, y, map))));
			}
			if (y < map->length - 1)
			{
				draw_line(mlx, camera, point(mlx, init_point(x, y, map), \
				point(mlx, camera, init_point(x, y + 1, map))));
			}
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
