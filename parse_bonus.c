/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:49:48 by junyojeo          #+#    #+#             */
/*   Updated: 2023/05/19 01:08:22 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	set_dot_color(t_point *dot_arr, char **split, int h)
{
	int		idx;
	char	*color;

	idx = -1;
	while (split[++idx])
	{
		dot_arr[idx].x = idx;
		dot_arr[idx].y = h;
		dot_arr[idx].z = ft_atoi(split[idx]);
		color = ft_strchr(split[idx], ',');
		if (color)
			dot_arr[idx].color = ft_atoi_base(color + 3);
		else
			dot_arr[idx].color = CLR_DEFAULT;
		free(split[idx]);
	}
	free(split);
}

static void	set_map(t_map *map, int fd)
{
	int		h;
	int		w;
	char	**split;
	char	*line;

	h = -1;
	while (++h < map->height)
	{
		line = get_next_line(fd);
		split = ft_split(line, ' ');
		if (!split)
			ft_puterror("Error: split mallocate fail");
		w = 0;
		while (split[w])
			w++;
		if (h != 0 && map->width != w)
			ft_puterror("Error: improper formatted.");
		map->width = w;
		map->dot[h] = ft_calloc(map->width, sizeof(t_point));
		if (!map->dot[h])
			ft_puterror("Error: map->dot mallocte fail");
		set_dot_color(map->dot[h], split, h);
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
