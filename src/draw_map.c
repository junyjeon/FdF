/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:34:30 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/15 12:30:27 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_x(int *y, int *z, double alpha)
{
	int	prev_y;

	prev_y = *y;
	*y = prev_y * cos(alpha) + (*z) * sin(alpha);
	*z = -prev_y * sin(alpha) + (*z) * cos(alpha);
}

static void	rotate_y(int *x, int *z, double beta)
{
	int	prev_x;

	prev_x = *x;
	*x = prev_x * cos(beta) + (*z) * sin(beta);
	*z = -prev_x * sin(beta) + (*z) * cos(beta);
}

static void	rotate_z(int *x, int *y, double gamma)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(gamma) - prev_y * sin(gamma);
	*y = prev_x * sin(gamma) + prev_y * cos(gamma);
}

static double	get_ratio(int s, int f, int cur)
{
	double	ratio;

	if (s == f)
		return (1.0);
	ratio = (double)(cur - s) / (f - s);
	return (ratio);
}

static int	process_lerp(int s, int f, double ratio)
{
	return ((int)((ratio) * s + (1 - ratio) * f));
}

/*
** quadrant 1, 4, 5, 8(delta.x > delta.y): sample by x
** quadrant 2, 3, 6, 7(delta.x < delta.y): sample by y
*/

int	get_clr(t_point cur, t_point *s, t_point *f, t_point delta)
{
	double	ratio;
	int		red;
	int		green;
	int		blue;

	if (cur.clr == f->clr)
		return (cur.clr);
	if (delta.x > delta.y)
		ratio = get_ratio(s->x, f->x, cur.x);
	else
		ratio = get_ratio(s->y, f->y, cur.y);
	red = process_lerp((f->clr >> 16) & 0xFF, (s->clr >> 16) & 0xFF, ratio);
	green = process_lerp((f->clr >> 8) & 0xFF, (s->clr >> 8) & 0xFF, ratio);
	blue = process_lerp(f->clr & 0xFF, s->clr & 0xFF, ratio);
	return ((red << 16) | (green << 8) | blue);
}

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

static void	ft_isometric(int *x, int *y, int z)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(PI / 6);
	*y = (prev_x + prev_y) * sin(PI / 6) - z;
}
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
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
			img[i] = CLR_SUB_SCRN_BG
		else
			img[i] = CLR_MAIN_SCRN_BG
	}
}

/*
** bits per pixel: 32(4 bytes; int)
** line_length: 4000
*/

void	draw(t_mlx *mlx, t_map *map)
{
	int	x;
	int	y;
	draw_background(mlx);
}