/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:49:48 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/13 21:20:28 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	is_width(char *line, int width, int height)
{
	int		i;
	char	**split;

	split = ft_split(line, ' ');
	i = 0;
	while (split[i])
		i++;
	free(split);
	if (0 < height && width != i)
		ft_puterror("Error: Invalid map");
	return (i);
}

static void	get_map_size(t_map *map, int fd)
{
	int		height;
	int		width;
	char	*line;

	width = 0;
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		width = is_width(line, width, height);
		height++;
	}
	map->width = width;
	map->height = height;
}

static int	file_check(char *filename)
{
	int		fd;
	char	*str;

	str = ft_strrchr(filename, '.');
	if (ft_strncmp(str, ".fdf", 5) != 0)
		ft_puterror("Error: only '.fdf' file can open\n");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_puterror("Failed to open file.\n");
	return (fd);
}

void	parse(t_map *map, char *filename)
{
	int		fd;

	fd = file_check(filename);
	get_map_size(map, fd);
	if (map->width == 0 || map->height == 0)
		ft_puterror("Error: map size <= 0");
	close(fd);
}
