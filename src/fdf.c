/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:04:01 by junyojeo          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/03/18 17:38:49 by junyojeo         ###   ########.fr       */
=======
/*   Updated: 2023/03/18 10:56:39 by junyojeo         ###   ########.fr       */
>>>>>>> 70d53e4b429eb9cfce89b9e16edb985f7456d229
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf(char **argv)
{
	t_mlx		mlx;
	t_map		map;

	init(&mlx);
	parse(&map, argv[1]);
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
