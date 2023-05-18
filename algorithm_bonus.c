/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:21:18 by junyojeo          #+#    #+#             */
/*   Updated: 2023/05/19 01:41:13 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	set_sign(t_point *sign, t_point start, t_point end)
{
	if (start.x < end.x)
		sign->x = 1;
	else
		sign->x = -1;
	if (start.y < end.y)
		sign->y = 1;
	else
		sign->y = -1;
}

static void	set_delta(t_point *delta, t_point start, t_point end)
{
	delta->x = (int)fabs((double)(end.x - start.x));
	delta->y = (int)fabs((double)(end.y - start.y));
}

static void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, unsigned int color)
{
	int	i;

	if (0 <= x && x < SCRN_WIDTH && y >= 0 && y < SCRN_HEIGHT)
	{
		i = (x * mlx->bits_per_pixel / 8) + (y * mlx->line_length);
		mlx->addr[i] = color;
		mlx->addr[++i] = color >> 8;
		mlx->addr[++i] = color >> 16;
	}
}

void	bresenham(t_mlx *mlx, t_point start, t_point end)
{
	t_point		delta;
	t_point		sign;
	t_point		cur;
	int			error[2];

	set_delta(&delta, start, end);
	set_sign(&sign, start, end);
	error[0] = delta.x - delta.y;
	cur = start;
	while (cur.x != end.x || cur.y != end.y)
	{
		my_mlx_pixel_put(mlx, cur.x, cur.y, cur.color);
		error[1] = error[0] * 2;
		if (error[1] > -delta.y)
		{
			error[0] -= delta.y;
			cur.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			cur.y += sign.y;
		}
	}
}
