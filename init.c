/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:34:27 by junyojeo          #+#    #+#             */
/*   Updated: 2023/05/19 02:12:28 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_view(t_mlx *mlx)
{
	mlx->zoom = 1;
	mlx->offset_x = 0;
	mlx->offset_y = 0;
	mlx->alpha = 0;
	mlx->beta = 0;
	mlx->gamma = 0;
	mlx->projection = ISO;
}

void	init(t_mlx *mlx, char *argv)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		ft_puterror("Error: mlx init fail");
	mlx->win = mlx_new_window(mlx->mlx, SCRN_WIDTH, SCRN_HEIGHT, argv);
	if (!mlx->win)
		ft_puterror("Error: mlx win fail");
	mlx->img = mlx_new_image(mlx->mlx, SCRN_WIDTH, SCRN_HEIGHT);
	if (!mlx->img)
		ft_puterror("Error: mlx img fail");
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, \
	&mlx->line_length, &mlx->endian);
	if (!mlx->addr)
		ft_puterror("Error: mlx addr fail");
	init_view(mlx);
}
