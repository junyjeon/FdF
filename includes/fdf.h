/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:20:14 by junyojeo          #+#    #+#             */
/*   Updated: 2023/02/13 17:45:11 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "keysymdef.h"

typedef struct s_camera
{

}		t_camera;

typedef struct s_map
{
	int x;
	int y;
	int z;
}		t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endn;
	t_map	*map;
	t_camera	*cam;
	t_handle	*handle;
}		t_data;

//# define WIDTH 256
//# define HEIGHT 256

//typedef struct mlx_instance
//{
//	int32_t	x;
//	int32_t	y;
//	int32_t	z;
//	bool	enabled;
//}	mlx_instance_t;

//typedef struct mlx
//{
//	void*	window;
//	void*	context;
//	int		width;
//	int		height;
//	double	delta_time;
//}	mlx_t;

//typedef struct mlx_key_data
//{
//	keys_t		key;
//	action_t	action;
//	int32_t		os_key;
//	modifier_key_t	modifier;
//}	mlx_key_data_t;

//typedef struct mlx_image
//{
//	const uint32_t	width;
//	const uint32_t	height;
//	uint8_t*		pixels;
//	mlx_instance_t*	instances;
//	int32_t			count;
//	bool			enabled;
//	void*			context;
//}	mlx_image_t;

#endif
