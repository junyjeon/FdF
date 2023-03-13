/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:04:01 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/14 08:28:08 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf(char **argv)
{
	t_mlx	mlx;
	t_map	map;

	init(&mlx, &map);
	parse(&map, argv[1]);
	iso_projection(&mlx, &map);
	//size_control(&mlx, &map);
	//draw(&mlx, );
	my_mlx_pixel_put(&mlx, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	//ft_free(mlx);
	//mlx_key_hook(mlx.win, key_control, &mlx);
	mlx_loop(mlx.mlx);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_puterror("Usage: ./fdf [filename.fdf]\n");
	fdf(argv);
	return (0);
}
