/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:34:27 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/08 12:35:25 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	file_check(char *filename)
{
	int		fd;
	char	*str;

	str = ft_strrchr(filename, '.');
	if (ft_strncmp(str, ".fdf", 5) != 0)
		ft_puterror("Error: only '.fdf' file can open\n");
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_puterror("Failed to open file.\n");
	return (fd);
}

void	parse_map(t_map *map, char *filename)
{
	int		fd;
	int		i;
	int		j;
	char	*line;
	char	**split;

	fd = file_check(filename);
	if (fd == -1)
		ft_puterror("Failed to open file.");
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		split = ft_split(line, ' ');
		j = -1;
		while (split[++j])
			map->line[i][j] = ft_atoi(split[j]);
		i++;
	}
	if (map->line[0])
		map->width = ft_strlen(map->line[0]);
	map->height = i;
	if (map->width <= 0 || map->height <= 0)
		ft_puterror("Error: map size <= 0");
	close(fd);
}

void	init(t_mlx *mlx)
{
	mlx->mlx_p = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_p, 500, 500, "mlx 42");
	mlx->img = mlx_new_image(mlx->mlx_p, 250, 250);
}

// int bpp;
// int sizeline;
// int endian;
// bpp = 0;
// endian = 0;
// sizeline = 0;
// mlx.addr = mlx_get_data_addr(mlx.img, bpp, sizeline, endian);
// mlx.cam = ;
// mlx.handle = ;
