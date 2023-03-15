/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:34:27 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/15 12:02:30 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

void	init(t_mlx *mlx, t_map *map, t_camera *camera)
{
	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (mlx)
		ft_puterror("Error: mlx mallocate fail");
	map = (t_map *)malloc(sizeof(t_map));
	if (map)
		ft_puterror("Error: map mallocate fail");
	camera = (t_camera *)malloc(sizeof(t_camera));
	if (camera == NULL)
		ft_puterror("Error: camera mallocate fail");
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, SCRN_WIDTH, SCRN_HEIGHT, "mlx 42");
	mlx->img = mlx_new_image(mlx->mlx, SCRN_WIDTH, SCRN_HEIGHT);
	mlx->addr = (int *)mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, \
	&mlx->line_length, &mlx->endian);
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	camera->x_offset = 0;
	camera->y_offset = 0;//A < B ? A : B
	camera->zoom = get_min((SCRN_WIDTH - SUB_SCRN_WIDTH) / map->width / 2, \
	SCRN_HEIGHT / map->length / 2);
	camera->z_divisor = 1;
}
