/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:04:01 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/03 18:50:56 by junyojeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_puterror(char *str)
{
	ft_putstr_fd(str + '\n', 1);
	exit(1);
}

void	fdf(char **argv)
{
	t_mlx	mlx;
	t_map	map;

	init(&mlx);
	parse_map(&map, argv[1]);
	// draw_map(&mlx);
	// ctrl_map(&mlx);
	mlx_loop(&mlx);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_puterror("Usage: ./fdf [filename.fdf]\n");
	fdf(argv);
	return (0);
}
