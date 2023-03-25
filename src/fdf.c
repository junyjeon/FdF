/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:04:01 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/26 05:27:07 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf(char **argv)
{
	t_mlx	mlx;
	t_map	map;

	init(&mlx, argv[1]);
	parse(&map, argv[1]);
	draw(&mlx, &map);
	ft_free(&map);
	mlx_hook(mlx.win, 2, 0, key_press, &mlx);
	mlx_hook(mlx.win, 17, 0, red_cross, &mlx);
	mlx_loop(mlx.mlx);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_puterror("Usage: ./fdf [filename.fdf]\n");
	fdf(argv);
	return (0);
}
