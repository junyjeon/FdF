/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:21:18 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/15 20:52:22 by junyojeo         ###   ########.fr       */
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

void	isometric(int *x, int *y, int z)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(0.5236);
	*y = (prev_x + prev_y) * sin(0.5236) - z;
}

t_point	*point(t_map *map, t_camera *camera, t_point *p)
{
	p->x *= camera->zoom;
	p->y *= camera->zoom;
	p->y *= camera->zoom / camera->z_divisor;
	p->x -= (map->width * camera->zoom) / 2;
	p->y -= (map->height * camera->zoom) / 2;
	rotate_x(&p->y, &p->z, camera->alpha);
	rotate_y(&p->x, &p->z, camera->beta);
	rotate_x(&p->x, &p->y, camera->gamma);
	if (camera->projection == ISOMETRIC)
		isometric(&p->x, &p->y, &p->z);
	p->x += (SCRN_WIDTH - SUB_SCRN_WIDTH) \
	/ 2 + SUB_SCRN_WIDTH + camera->x_offset;
	p->y += SCRN_HEIGHT / 2 + camera->y_offset;
	p->y += map->height * camera->zoom * 2 / 5;
	return (p);
}
