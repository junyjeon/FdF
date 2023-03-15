/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:34:27 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/15 20:14:57 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_camera(t_camera *camera)
{
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	camera->x_offset = 0;
	camera->y_offset = 0;
	camera->z_divisor = 1;
}

t_point	*init_point(int x, int y, t_map *map, int index)
{
	t_point	*point;
	int		i;

	point = (t_point *)malloc(sizeof(t_point));
	if (point == NULL)
		ft_puterror("Error: point mallocate fail");
	point->x = x;
	point->y = y;
	i = y * map->width + x;
	point->z = map->map[index][i];
	return (point);
}

void	init(t_mlx *mlx, t_map *map, t_camera *camera)
{
	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (mlx == NULL)
		ft_puterror("Error: mlx mallocate fail");
	map = (t_map *)malloc(sizeof(t_map));
	if (map == NULL)
		ft_puterror("Error: map mallocate fail");
	camera = (t_camera *)malloc(sizeof(t_camera));
	if (camera == NULL)
		ft_puterror("Error: camera mallocate fail");
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, SCRN_WIDTH, SCRN_HEIGHT, "mlx 42");
	mlx->img = mlx_new_image(mlx->mlx, SCRN_WIDTH, SCRN_HEIGHT);
	mlx->addr = (int *)mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, \
	&mlx->line_length, &mlx->endian);
}
