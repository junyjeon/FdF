/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:49:48 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/27 08:12:07 by junyojeo         ###   ########.fr       */
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
			dot[j].color = CLR_DEFAULT;
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
		if (i != 0 && map->width != j)
			ft_puterror("Error: improper formatted.");
		map->width = j;
		map->dot[i] = ft_calloc(map->width, sizeof(t_point));
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
	if (fd < 0)
		ft_puterror("Error: file read fail");
	line = get_next_line(fd);
	while (line)
	{
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	parse(t_map *map, char *argv)
{
	int		fd;

	cal_map_size(map, argv);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_puterror("Failed to open file.\n");
	map->dot = ft_calloc(map->height, sizeof(t_point *));
	if (!map->dot)
		ft_puterror("Error: map->dot mallocte fail");
	set_map(map, fd);
	close(fd);
	if (map->width == 0 || map->height == 0)
		ft_puterror("Error: map size zero");
}
