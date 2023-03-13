/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:34:30 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/14 08:34:26 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//float lerp(float p1, float p2, float d1)
//{
//	return ((1 - d1) * p1 + d1 * p2);
//}

//static void rotate_x(int *y, int *z, double alpha)
//{
//	int	prev_y;

//	prev_y = *y;
//	*y = prev_y * cos(alpha) + (*z) * sin(alpha);
//	*z = -prev_y * sin(alpha) + (*z) * cos(alpha);
//}

//static void rotate_y(int *x, int *z, double beta)
//{
//	int	prev_x;

//	prev_x = *x;
//	*x = prev_x * cos(beta) + (*z) * sin(beta);
//	*z = -prev_x * sin(beta) + (*z) * cos(beta);
//}

//static void rotate_z(int *x, int *y, double gamma)
//{
//	int	prev_x;
//	int	prev_y;

//	prev_x = *x;
//	prev_y = *y;
//	*x = prev_x * cos(gamma) - prev_y * sin(gamma);
//	*y = -prev_x * sin(gamma) + prev_y * cos(gamma);
//}

// int	create_argb(int a, int r, int g, int b)
// {
// 	return (a << 24 | r << 16 | g << 8 | b);
// }

void	iso_projection(t_mlx *mlx, double *x, double *y, double *z)
{
	*z *= mlx->gap? * 0.125 * map->length; 
}


void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

