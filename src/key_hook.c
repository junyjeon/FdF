/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:34:32 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/26 05:09:43 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_press(int key_symbol, t_mlx *mlx)
{
	if (key_symbol == KEY_ESCAPE)
	{
		if (mlx->mlx && mlx->win)
		{
			mlx_destroy_image(mlx->mlx, mlx->img);
			mlx_destroy_window(mlx->mlx, mlx->win);
		}
		exit(0);
	}
	return (0);
}

int	red_cross(t_mlx *mlx)
{
	if (mlx->mlx && mlx->win)
	{
		mlx_destroy_image(mlx->mlx, mlx->img);
		mlx_destroy_window(mlx->mlx, mlx->win);
	}
	exit(0);
	return (0);
}
