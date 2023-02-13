/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:34:32 by junyojeo          #+#    #+#             */
/*   Updated: 2023/02/13 17:34:38 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int	esc_key(t_data *data, int key, void *param)
{
	ft_puchar("X");
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, );
	return (0);
}

void	ctrl_map(t_data *data)
{
	mlx_key_hook(data->win_ptr, esc_key, (void *)0);
	mlx_key_hook(data->win_ptr, up_key_hook, (void *)0);
	mlx_key_hook(data->win_ptr, down_key_hook, (void *)0);
	mlx_key_hook(data->win_ptr, left_key_hook, (void *)0);
	mlx_key_hook(data->win_ptr, right_key_hook, (void *)0);
}
