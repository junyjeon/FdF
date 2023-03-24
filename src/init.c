/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:34:27 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/23 02:18:18 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init(t_mlx *mlx, char *argv)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, SCRN_WIDTH, SCRN_HEIGHT, argv);
	mlx->img = mlx_new_image(mlx->mlx, SCRN_WIDTH, SCRN_HEIGHT);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, \
	&mlx->line_length, &mlx->endian);
}
