/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:34:30 by junyojeo          #+#    #+#             */
/*   Updated: 2023/05/19 02:12:04 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	clear_img(t_mlx *mlx)
{
	ft_bzero(mlx->addr, SCRN_WIDTH * SCRN_HEIGHT * \
		(mlx->bits_per_pixel / 8));
}

static void	iso(int *x, int *y, int z)
{
	int		prev_x;
	int		prev_y;
	double	thirty;

	prev_x = *x;
	prev_y = *y;
	thirty = 0.523599;
	*x = (prev_x - prev_y) * cos(thirty);
	*y = -z + (prev_x + prev_y) * sin(thirty);
}

t_point	project(t_point p, t_mlx *mlx)
{
	p.x *= mlx->zoom;
	p.y *= mlx->zoom;
	p.z *= mlx->zoom;
	p.x -= (mlx->map.width * mlx->zoom) / 2;
	p.y -= (mlx->map.height * mlx->zoom) / 2;
	rotate_x(&p.y, &p.z, mlx->alpha);
	rotate_y(&p.x, &p.z, mlx->beta);
	rotate_z(&p.x, &p.y, mlx->gamma);
	if (mlx->projection == ISO)
		iso(&p.x, &p.y, p.z);
	p.x += SCRN_WIDTH / 2 + mlx->offset_x;
	p.y += (SCRN_HEIGHT + mlx->map.height * mlx->zoom) / 2 + mlx->offset_y;
	return (p);
}

void	draw(t_mlx *mlx)
{
	int	w;
	int	h;

	clear_img(mlx);
	h = -1;
	while (++h < mlx->map.height)
	{
		w = -1;
		while (++w < mlx->map.width)
		{
			if (h + 1 < mlx->map.height)
				bresenham(mlx, project(mlx->map.dot[h][w], mlx), \
				project(mlx->map.dot[h + 1][w], mlx));
			if (w + 1 < mlx->map.width)
				bresenham(mlx, project(mlx->map.dot[h][w], mlx), \
				project(mlx->map.dot[h][w + 1], mlx));
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
