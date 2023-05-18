/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 00:56:37 by junyojeo          #+#    #+#             */
/*   Updated: 2023/05/19 00:58:52 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	projection_key(t_mlx *mlx)
{
	int	num;

	num = mlx->projection + 1;
	mlx->projection = num % 2;
	draw(mlx);
}

static void	zoom_key(int key, t_mlx *mlx)
{
	if (key == KEY_EQUAL)
	{
		if (mlx->zoom == INT_MAX)
			return ;
		mlx->zoom++;
	}
	else if (key == KEY_MINUS)
	{
		if (mlx->zoom == 1)
			return ;
		mlx->zoom--;
	}
	draw(mlx);
}

static void	rotate_key(int key, t_mlx *mlx)
{
	if (key == KEY_U)
		mlx->alpha += 0.05;
	else if (key == KEY_J)
		mlx->alpha -= 0.05;
	else if (key == KEY_I)
		mlx->beta += 0.05;
	else if (key == KEY_K)
		mlx->beta -= 0.05;
	else if (key == KEY_O)
		mlx->gamma += 0.05;
	else if (key == KEY_L)
		mlx->gamma -= 0.05;
	draw(mlx);
}

static void	move_key(int key, t_mlx *mlx)
{
	if (key == KEY_W)
		mlx->offset_y -= 10;
	else if (key == KEY_S)
		mlx->offset_y += 10;
	else if (key == KEY_A)
		mlx->offset_x -= 10;
	else if (key == KEY_D)
		mlx->offset_x += 10;
	draw(mlx);
}

int	my_key_hook(int key, t_mlx *mlx)
{
	if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
		move_key(key, mlx);
	else if (key == KEY_U || key == KEY_J || key == KEY_I || \
	key == KEY_K || key == KEY_O || key == KEY_L)
		rotate_key(key, mlx);
	else if (key == KEY_EQUAL || key == KEY_MINUS)
		zoom_key(key, mlx);
	else if (key == KEY_SPACE)
		projection_key(mlx);
	return (0);
}
