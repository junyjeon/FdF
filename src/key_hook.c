/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:34:32 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/16 16:55:04 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//int	esc_key(t_mlx *mlx, int key, void *param)
//{
//	ft_puchar("X");
//	mlx_pixel_put(mlx->mlx_p, mlx->win, );
//	return (0);
//}

// int	key_press(int key, t_mlx *mlx)
// {
// 	if (key == KEY_W)
// 	{
// 		if ()
// 			mlx->playerPositionX += mlx->directionVectorX * info->moveSpeed;
// 		if ()
// 			mlx->playerPositionY += mlx->directionVectorY * info->moveSpeed;
// 	}
// 	if (key == KEY_S)
// 	{
// 		if ()
// 			mlx->playerPositionX -= mlx->directionVectorX * info->moveSpeed;
// 		if ()
// 			mlx->playerPositionY -= mlx->directionVectorY * info->moveSpeed;
// 	}
// 	if (key == KEY_A)
// 	{
// 		double oldDirectionX = info->directionVectorX;
// 		info->directionVectorX = info->directionVectorX * cos(info->rotSpeed) - info->directionVectorY * sin(info->rotSpeed);
// 		info->directionVectorY = oldDirectionX * sin(info->rotSpeed) + info->directionVectorY * cos(info->rotSpeed);
// 		double oldPlaneX = info->planeX;
// 		info->planeX = info->planeX * cos(info->rotSpeed) - info->planeY * sin(info->rotSpeed);
// 		info->planeY = oldPlaneX * sin(info->rotSpeed) + info->planeY * cos(info->rotSpeed);
// 	}

// 	// https://github.com/ChoiKanghun/images/blob/master/1024_1.jpg?raw=true
// 	// 위 이미지를 브라우저에 검색하자. 핵심이 되는 공식이다. 이 공식에 대한 자세한 설명은
// 	// https://github.com/minckim0/cub3d_lect 해당 깃 레포 내 pdf 62~66 페이지 참고.
// 	if (key == KEY_D)
// 	{
// 		double oldDirectionX = info->directionVectorX;
// 		info->directionVectorX = info->directionVectorX * cos(-info->rotSpeed) - info->directionVectorY * sin(-info->rotSpeed);
// 		info->directionVectorY = oldDirectionX * sin(-info->rotSpeed) + info->directionVectorY * cos(-info->rotSpeed);
// 		double oldPlaneX = info->planeX;
// 		info->planeX = info->planeX * cos(-info->rotSpeed) - info->planeY * sin(-info->rotSpeed);
// 		info->planeY = oldPlaneX * sin(-info->rotSpeed) + info->planeY * cos(-info->rotSpeed);
// 	}
// 	if (key == K_ESC)
// 		exit(0);
// 	return (0);
// }

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESCAPE)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	return (0);
}