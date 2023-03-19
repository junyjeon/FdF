/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:34:27 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/20 05:45:42 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// t_point	*init_point(t_map *map, int x, int y)
// {
// 	t_point	*point;

// 	rotate_x(&y, &map->map[x][y], PI_DIVIDE_6);
// 	rotate_y(&x, &map->map[x][y], PI_DIVIDE_6);
// 	rotate_z(&x, &y, PI_DIVIDE_6);
// 	point = (t_point *)malloc(sizeof(t_point));
// 	point->x = x;
// 	point->y = y;
// 	point->z = map->map[x][y];
// 	point->color = get_default_color(map, map->map[x][y]);
// 	return (point);
// }

void	init(t_mlx *mlx, char *argv)
{
	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, SCRN_WIDTH, SCRN_HEIGHT, argv);
	mlx->img = mlx_new_image(mlx->mlx, SCRN_WIDTH, SCRN_HEIGHT);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, \
	&mlx->line_length, &mlx->endian);
}
