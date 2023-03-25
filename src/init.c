/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:34:27 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/26 00:03:24 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
}
