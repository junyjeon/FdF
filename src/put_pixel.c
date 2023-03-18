/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:02:54 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/18 18:43:32 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	mag(int start, int end, int x)
{
	if (start == end)
		return (1.0);
	return ((double)(x - start) / (end - start));
}

int	get_default_clr(t_map *map, int i, int j)
{
	double	ratio;

	ratio = mag(map->z_min, map->z_max, map->map[i][j]);
	if (ratio < 0.2)
		return (CLR_DISCO);
	else if (ratio < 0.4)
		return (CLR_BRICK_RED);
	else if (ratio < 0.6)
		return (CLR_FLAMINGO);
	else if (ratio < 0.8)
		return (CLR_JAFFA);
	else
		return (CLR_SAFFRON);
}

static int	lerp(int s, int f, double ratio)
{
	return ((int)((ratio) * s + (1 - ratio) * f));
}

int	gradient(t_point start, t_point end, t_point x)
{
	double	ratio;
	int		red;
	int		green;
	int		blue;

	if (x.color == end.color)
		return (x.color);
	ratio = mag(start.x, end.x, x.x);
	red = lerp((end.color >> 16) & 0xFF, (start.color >> 16) & 0xFF, ratio);
	green = lerp((end.color >> 8) & 0xFF, (start.color >> 8) & 0xFF, ratio);
	blue = lerp(end.color & 0xFF, start.color & 0xFF, ratio);
	return ((red << 16) | (green << 8) | blue);
}

// int create_trgb(int t, int r, int g, int b)
// {
// 	return (t << 24 | r << 16 | g << 8 | b);
// }

// int	get_t(int trgb)
// {
// 	return (trgb & (0xFF << 24));
// }

// int	get_r(int trgb)
// {
// 	return (trgb & (0xFF << 16));
// }

// int	get_g(int trgb)
// {
// 	return (trgb & (0xFF << 8));
// }

// int	get_b(int trgb)
// {
// 	return (trgb & 0xFF);
// }

// get_color(CLR_TEXT);
