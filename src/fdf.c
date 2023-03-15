/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:04:01 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/15 19:54:13 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf(char **argv)
{
	t_mlx		mlx;
	t_map		map;
	t_camera	camera;

	init(&mlx, &map, &camera);
	parse(&map, argv[1]);
	//iso_projection(&map, x, y, z);
	//size_control(&mlx, &map);
	draw(&mlx, &map);
	//my_mlx_pixel_put(&mlx, 5, 5, 0x00FF0000);
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
