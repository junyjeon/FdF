/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:34:30 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/20 08:22:55 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_put(t_mlx *mlx, t_point *p)
{
	char	*dst;

	dst = mlx->addr + (p->y * mlx->line_length) + p->x * 4;
	*(unsigned int *)dst = p->color;
}
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
static t_point	*isometric(t_point *dot)
{
	int		prev_x;
	int		prev_y;

	prev_x = dot->x;
	prev_y = dot->y;
	dot->x = (prev_x - prev_y) * cos(PI_DIVIDE_6);
	dot->y = (prev_x + prev_y) * sin(PI_DIVIDE_6) - dot->z;
	return (dot);
}

static void	draw_background(t_mlx *mlx, t_map *map)
{
	int		i;
	int		j;

	j = -1;
	while (++j < SCRN_HEIGHT)
	{
		i = -1;
		while (++i < SCRN_WIDTH)
			pixel_put(mlx, init_point(i, j, 0x00FFFFFF));
	}
}

void	draw(t_mlx *mlx, t_map *map)
{
	int	i;
	int	j;

	draw_background(mlx, map);
	j = -1;
	while (++j < map->height)
	{
		i = -1;
		while (++i < map->width)
		{
			if (i < map->width - 1)
				bresenham(mlx, map->dot[(map->width * j) + i], map->dot[(map->width * j) + i + 1]);
			if (j < map->height - 1)
				bresenham(mlx, map->dot[(map->width * j) + i], map->dot[(map->width * (j + 1)) + i]);
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
