/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:20:14 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/03 19:56:33 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../lib/mlx/mlx.h"
# include "../lib/libft/libft.h"
# include "../lib/get_next_line/get_next_line.h"
# include <unistd.h>
# include <fcntl.h>

# define WIDTH 256
# define HEIGHT 256

typedef struct s_camera
{

}		t_camera;

typedef struct s_map
{
	int		width;
	int		height;
	char	**line;
}		t_map;

typedef struct s_handle
{

}		t_handle;

typedef struct s_mlx
{
	void		*mlx_p;
	void		*win;
	void		*img;
	t_map		*map;
	t_camera	*cam;
	t_handle	*handle;
	char		*addr;
}		t_mlx;


int		main(int argc, char **argv);
void	fdf(char **argv);
t_map	*read_file(char **argv);
void	ft_error(char *str);
t_mlx	init_mlx(char **argv);
void	draw_map(t_mlx *mlx);
int		create_argb(int a, int r, int g, int b);
void	ctrl_map(t_mlx *data);
int		esc_key(t_mlx *data, int key, void *param);


#endif
