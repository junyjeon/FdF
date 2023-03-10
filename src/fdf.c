/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:04:01 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/11 04:43:18 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_puterror(char *str)
{
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
	exit(1);
}

void	fdf(char **argv)
{
	t_mlx	mlx;
	t_map	map;

	init(&mlx);
	parse_map(&map, argv[1]);
	my_mlx_pixel_put(&mlx, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	mlx_loop(&mlx);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_puterror("Usage: ./fdf [filename.fdf]\n");
	fdf(argv);
	return (0);
}
