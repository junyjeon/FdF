/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:49:48 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/23 01:05:38 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_dot_color(t_point *dot, char **split, int i)
{
	int		j;
	char	*color;

	j = -1;
	while (split[++j])
	{
		dot[j].x = j;
		dot[j].y = i;
		dot[j].z = ft_atoi(split[j]);
		color = ft_strchr(split[j], ',');
		if (color)
			dot[j].color = ft_atoi_base(color + 3);
		else
			dot[j].color = 0x00FFFFFF;
		free(split[j]);
	}
	free(split[j]);
}

static void	set_map(t_map *map, int fd)
{
	int		i;
	int		j;
	char	**split;
	char	*line;

	map->dot = (t_point **)malloc(sizeof(t_point *) * map->height);
	if (!map->dot)
		ft_puterror("Error: map->dot mallocte fail");
	i = -1;
	while (++i < map->height)
	{
		line = get_next_line(fd);
		split = ft_split(line, ' ');
		if (!split)
			ft_puterror("Error: split mallocate fail");
		j = 0;
		while (split[j])
			j++;
		map->width = j;
		map->dot[i] = (t_point *)malloc(sizeof(t_point) * map->width);
		if (!map->dot[i])
			ft_puterror("Error: map->dot mallocte fail");
		set_dot_color(map->dot[i], split, i);
		free(line);
	}
}

static void	cal_map_size(t_map *map, char *argv)
{
	int		fd;
	char	*line;

	map->height = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_puterror("Error: file read fail");
	line = get_next_line(fd);
	while (line)
	{
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
}

static int	file_check(char *argv)
{
	int		fd;
	char	*str;

	str = ft_strrchr(argv, '.');
	if (ft_strncmp(str, ".fdf", 5) != 0)
		ft_puterror("Error: only '.fdf' file can open\n");
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_puterror("Failed to open file.\n");
	return (fd);
}

void	parse(t_map *map, char *argv)
{
	int		fd;

	fd = file_check(argv);
	cal_map_size(map, argv);
	set_map(map, fd);
	if (map->width == 0 || map->height == 0)
		ft_puterror("Error: map size zero");
	close(fd);
}
