/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:34:27 by junyojeo          #+#    #+#             */
/*   Updated: 2023/02/13 17:52:45 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_data	init_mlx(char **argv)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx, 500, 500, "mlx 42");
	data.img = mlx_new_image(data.mlx, 250, 250);
	data.addr = mlx_get_data_addr(data.img, data.bpp, data.size, data.endian);
	data.bpp = 0;
	data.size_line = 0;
	data.endian = 0;
	data.map = ;
	data.cam = ;
	data.handle = ;
	return (data);
}
