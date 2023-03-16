/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:04:01 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/16 17:04:47 by junyojeo         ###   ########.fr       */
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
	init_camera(&camera);
	draw(&mlx, &map);
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_loop(mlx.mlx);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_puterror("Usage: ./fdf [filename.fdf]\n");
	fdf(argv);
	return (0);
}
