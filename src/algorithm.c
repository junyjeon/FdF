/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:21:18 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/16 17:27:42 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	int	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	bresenham(t_mlx *mlx, int x1, int y1, int x2, int y2)
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	f;

	x = x1;
	y = y1;
	dx = x2 - x1;
	dy = y2 - y1;
	f = 2 * dx - dy;
	while (x <= x2)
	{
		my_mlx_pixel_put(mlx, x, y, CLR_TEXT);
		++x;
		if (f < 0)
			f = f + 2 * dy;
		else
		{
			f = f + 2 * dy - 2 * dx;
			++y;
		}
	}
}

void	isometric(int *x, int *y, int z)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(0.5236);
	*y = (prev_x + prev_y) * sin(0.5236) - z;
}
