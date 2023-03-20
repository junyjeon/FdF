/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:49:48 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/20 07:30:02 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_map_color_dot(t_map *map, char *line, int j)
{
	int		i;
	char	**split;
	char	*color;

	split = ft_split(line, ' ');
	if (!split)
		ft_puterror("Error: split mallocate fail");
	i = -1;
	while (split[++i])
	{
		color = ft_strchr(split[i], ',');
		if (color)
			map->dot[(map->width * j) + i]->color = (*color) + 1;
		else
			map->dot[(map->width * j) + i]->color = 0x00FFFFFF;
		map->dot[(map->width * j) + i]->x = i;
		map->dot[(map->width * j) + i]->y = j;
		map->dot[(map->width * j) + i]->z = ft_atoi(split[i]);
		free(split[i]);
	}
	free(split[i]);
}

static void	set_map(t_map *map, int fd)
{
	int		j;
	char	*line;

	map->dot = (t_point **)malloc(sizeof(t_point *) * map->height * map->width); 
	if (map->dot)
		ft_puterror("Error: map->map mallocte fail");
	j = -1;
	while (++j < map->height)
	{
		line = get_next_line(fd);
		set_map_color_dot(map, line, j);
		free(line);
	}
}

static void	cal_map_size(t_map *map, char *argv)
{
	int		fd;
	char	*line;

	map->height = 0;
	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	map->width = ft_strlen(line);
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