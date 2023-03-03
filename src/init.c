/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:34:27 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/03 16:45:45 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_mlx	init_mlx(char **argv)
{
	t_mlx	mlx;
	int		bpp;
	int		sizeline;
	int		endian;

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx, 500, 500, "mlx 42");
	mlx.img = mlx_new_image(mlx.mlx, 250, 250);
	bpp = 0;
	endian = 0;
	sizeline = 0;
	mlx.addr = mlx_get_data_addr(mlx.img, bpp, sizeline, endian);
	mlx.map = read_file(argv);
	mlx.cam = ;
	mlx.handle = ;
	return (mlx);
}
