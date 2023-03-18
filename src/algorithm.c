/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:21:18 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/18 21:47:00 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_vertical(t_mlx *mlx, t_point *start, t_point *end)
{
	int	i;

	if (end->y > start->y)
	{
		i = start->y - 1;
		while (++i < end->y && i < SCRN_HEIGHT && \
		(end->x >= 0 && end->x < SCRN_HEIGHT))
			if (i >= 0)
				pixel_put(mlx, init_point(start->x, i, 0), gradient(start, end, );
	}
	else
	{
		i = end->y - 1;
		while (++i < start->y && i < SCRN_HEIGHT && \
		(end->x >= 0 && end->x < SCRN_HEIGHT))
			if (i >= 0)
				pixel_put(mlx, init_point(start->x, i, 0));
	}
}

static void	draw_horizon(t_mlx *mlx, t_point *start, t_point *end)
{
	int	i;

	if (end->x > start->x)
	{
		i = start->x - 1;
		while (++i < end->x && i < SCRN_HEIGHT && \
		(end->y >= 0 && end->y < SCRN_HEIGHT))
			if (i >= 0)
				pixel_put(mlx, init_point(start->y, i, 0));
	}
	else
	{
		i = end->x - 1;
		while (++i < start->x && i < SCRN_HEIGHT && \
		(end->y >= 0 && end->y < SCRN_HEIGHT))
			if (i >= 0)
				pixel_put(mlx, init_point(start->y, i, 0));
	}
}

static void	less_one(t_mlx *mlx, t_point *start, t_point *end)
{
	int	p;
	int	inc_x;
	int	inc_y;

	inc_x = 1;
	inc_y = 1;
	if (start->x > end->x)
		inc_x = -1;
	if (start->y > end->y)
		inc_y = -1;
	p = 2 * abs(end->x - start->x) - abs(end->y - start->y);
	while (start->x != end->x && (start->x < SCRN_WIDTH && start->y < SCRN_HEIGHT))
	{
		if (start->x >= 0 && start->y >= 0)
			pixel_put(mlx, init_point(start->x, start->y, 0));
		start->x += inc_x;
		if (p < 0)
			p = p + 2 * abs(end->y - start->y);
		else
		{
			p = p + 2 * abs(end->y - start->y) - 2 * abs(end->x - start->x);
			start->y += inc_y;
		}
	}
}

static void	more_one(t_mlx *mlx, t_point *start, t_point *end)
{
	int	p;
	int	inc_x;
	int	inc_y;

	inc_x = 1;
	inc_y = 1;
	if (start->x > end->x)
		inc_x = -1;
	if (start->y > end->y)
		inc_y = -1;
	p = 2 * abs(end->y - start->y) - abs(end->x - start->x);
	while (start->y != end->y && (start->x < SCRN_WIDTH && start->y < SCRN_HEIGHT))
	{
		if (start->x >= 0 && start->y >= 0)
			pixel_put(mlx, init_point(start->x, start->y, 0));
		start->y += inc_y;
		if (p < 0)
			p = p + 2 * abs(end->x - start->x);
		else
		{
			p = p + 2 * abs(end->x - start->x) - 2 * abs(end->y - start->y);
			start->x += inc_x;
		}
	}
}

void	bresenham(t_mlx *mlx, t_point *start, t_point *end)
{
	int	i;

	start->color = 0x00FFFFFF;
	end->color = 0x00FFFFFF;
	if (end->x - start->x == 0)
		draw_vertical(mlx, start, end);
	else if (end->y - start->y == 0)
		draw_horizon(mlx, start, end);
	else if (abs(end->y - start->x) < abs(end->x - start->x))
		less_one(mlx, start, end);
	else
		more_one(mlx, start, end);
}
