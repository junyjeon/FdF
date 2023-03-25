/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:34:32 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/26 02:55:57 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_press(t_mlx *mlx, int keycode)
{
	(void)mlx;
	if (keycode == KEY_ESCAPE || keycode == KEY_RED_CROSS)
	{
		exit(0);
	}
	return (0);
}

int	red_cross(t_mlx *mlx)
{
	free(mlx->mlx);
	if (mlx->mlx && mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
	return (0);
}
