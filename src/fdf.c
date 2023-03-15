/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:04:01 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/15 15:02:40 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	draw(t_mlx *mlx, t_map *map)
// {
// 	int	i = 0;
// 	while (i < HEIGHT)
// 	{
// 		int	j = 0;
// 		while (j < WIDTH / 2)
// 		{
// 			if ()
// 		}
// 	}
// }

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

void	fdf(char **argv)
{
	t_mlx		mlx;
	t_map		map;
	t_camera	camera;

	init(&mlx, &map, &camera);
	parse(&map, argv[1]);
	//iso_projection(&map, x, y, z);
	//size_control(&mlx, &map);
	draw(&mlx, &map, &camera);
	my_mlx_pixel_put(&mlx, 5, 5, 0x00FF0000);
	//ft_free(mlx);
	//mlx_key_hook(mlx.win, key_control, &mlx);
	// mlx_hook(mlx.win, X_EVENT_KEY_PRESS, 0, &key_press, &mlx);
	mlx_loop(mlx.mlx);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_puterror("Usage: ./fdf [filename.fdf]\n");
	fdf(argv);
	return (0);
}
