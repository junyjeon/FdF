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

void	ft_error(char *str)
{
	write(2, str, ft_strlen(str) + 1);
	exit(1);
}

t_map	*read_file(char **argv)
{
	t_map	*map;
	int		fd;
	int		i;

	map = (t_map *)malloc(sizeof(t_map));
	fd = open(argv[1], O_RDONLY);
	i = 0;
	while (1)
	{
		map->line[i] = get_next_line(fd);
		if (map->line[i])
			continue ;
		else
			break ;
		i++;
	}
	if (map->line[0])
		map->width = ft_strlen(map->line[0]);
	map->height = i;
	if (map->width <= 0 || map->height <= 0)
		ft_error("Error: map size <= 0\n");
	close(fd);
	return (map);
}

void	fdf(char **argv)
{
	t_mlx	mlx;
	char	*str;

	str = ft_strrchr(argv[1], '.');
	if (ft_strncmp(str, ".fdf", 5) != 0)
		ft_error("Error: only '.fdf' file can open\n");
	mlx = init_mlx(argv);
	draw_map(&mlx);
	ctrl_map(&mlx);
	mlx_loop(&mlx);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_error("Argument\n");
	fdf(argv);
	return (0);
}
