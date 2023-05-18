/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:34:32 by junyojeo          #+#    #+#             */
/*   Updated: 2023/05/19 02:12:18 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	key_press(int key, t_mlx *mlx)
{
	if (key == KEY_ESCAPE)
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

void	ft_hook(t_mlx *mlx)
{
	mlx_hook(mlx->win, 2, 0, key_press, mlx);
	mlx_hook(mlx->win, 17, 0, red_cross, mlx);
}
