/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:02:54 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/18 17:33:49 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "fdf.h"

//static double	get_ratio(int z)
//{
//	double	ratio;

//	if (s == f)
//		return (1.0);
//	ratio = (double)(cur - s) / (f - s);
//	return (ratio);
//}

//int	get_default_clr(int z, t_map *map)
//{
//	double	ratio;

//	ratio = get_ratio(map->z_min, map->z_max, z);
//	if (ratio < 0.2)
//		return (CLR_DISCO);
//	else if (ratio < 0.4)
//		return (CLR_BRICK_RED);
//	else if (ratio < 0.6)
//		return (CLR_FLAMINGO);
//	else if (ratio < 0.8)
//		return (CLR_JAFFA);
//	else
//		return (CLR_SAFFRON);
//}

//static int	do_lerp(int s, int f, double ratio)
//{
//	return ((int)((ratio) * s + (1 - ratio) * f));
//}

//int gradient()
//{
//	double	ratio;
//	int		red;
//	int		green;
//	int		blue;

//	ratio = get_ratio(s->x, f->x, cur.x);
//	red = process_lerp((f->color >> 16) & 0xFF, (s->color >> 16) & 0xFF, ratio);
//	green = process_lerp((f->color >> 8) & 0xFF, (s->color >> 8) & 0xFF, ratio);
//	blue = process_lerp(f->color & 0xFF, s->color & 0xFF, ratio);
//	return ((red << 16) | (green << 8) | blue);
//}

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
