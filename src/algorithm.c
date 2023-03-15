/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:21:18 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/15 21:54:51 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(int *x, int *y, int z)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(0.5236);
	*y = (prev_x + prev_y) * sin(0.5236) - z;
}

//void	bresenham(t_mlx *mlx, t_point *p1, t_point *p2)
//{
//	int	dx;
//	int	dy;
//	int	x;
//	int	y;
//	int	f;

//	x = p1->x;
//	y = p1->y;
//	dx = p2->x - p1->x;
//	dy = p2->y - p1->y;
//	f = 2 * dx - dy;
//	while (x <= p2->x)
//	{
//		put_pixel(x, y);
//		++x;
//		if (f < 0)
//			f = f + 2 * dy;
//		else
//		{
//			f = f + 2 * dy - 2 * dx;
//			++y;
//		}
//	}
//}
