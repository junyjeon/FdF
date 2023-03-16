/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:34:27 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/16 14:42:50 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		isometric(&p->x, &p->y, p->z);
	p->x += (SCRN_WIDTH - SUB_SCRN_WIDTH) \
	/ 2 + SUB_SCRN_WIDTH + camera->x_offset;
	p->y += SCRN_HEIGHT / 2 + camera->y_offset;
	p->y += map->height * camera->zoom * 2 / 5;
	return (p);
}

t_point	*init_point(t_map *map, int x, int y)
{
	t_point	*point;
	int		i;

	point = (t_point *)malloc(sizeof(t_point));
	if (point == NULL)
		ft_puterror("Error: point mallocate fail");
	point->x = x;
	point->y = y;
	i = y * map->width + x;
	point->z = (map->arr_z)[i];
	if ((map->arr_color)[i] == -1)
		point->color = get_default_color(point->z, map);
	else
		point->color = map->arr_color[i];
	return (point);
}

void	init_camera(t_map *map, t_camera *camera)
{
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	camera->x_offset = 0;
	camera->y_offset = 0;
	camera->z_divisor = 1;
	camera->zoom = get_less((SCRN_WIDTH - SUB_SCRN_WIDTH) / map->width / 2, \
	SCRN_HEIGHT / map->height / 2);
}

void	init(t_mlx *mlx, t_map *map, t_camera *camera)
{
	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (mlx == NULL)
		ft_puterror("Error: mlx mallocate fail");
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, SCRN_WIDTH, SCRN_HEIGHT, "mlx 42");
	mlx->img = mlx_new_image(mlx->mlx, SCRN_WIDTH, SCRN_HEIGHT);
	mlx->addr = (int *)mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, \
	&mlx->line_length, &mlx->endian);
	map = (t_map *)malloc(sizeof(t_map));
	if (map == NULL)
		ft_puterror("Error: map mallocate fail");
	map->arr_color = (int *)malloc(map->width * map->height * sizeof(int));
	if (map->arr_color == NULL)
		ft_puterror("Error: arr_color mallocate fail");
	map->arr_z = (int *)malloc(map->width * map->height * sizeof(int));
	if (map->arr_z == NULL)
		ft_puterror("Error: arr_z mallocate fail");
	camera = (t_camera *)malloc(sizeof(t_camera));
	if (camera == NULL)
		ft_puterror("Error: camera mallocate fail");
}
