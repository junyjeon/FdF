/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:49:48 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/13 19:00:59 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	mapset(t_map *map, int fd)
{
	int		i;
	int		j;
	int		k;
	int		line_cnt;
	char	*line;

	line_cnt = 0;
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		j = -1;
		k = 0;
		while (line[++j])
			if (line[j] != ' ')
				k++;
		if (0 < i && line_cnt != k)
			ft_puterror("Error: Invalid map");
		else
			line_cnt = k;
		i++;
	}
	map->width = line_cnt;
	map->height = i;
	map->line = (char **)malloc(sizeof(char *) * map->height);
	i = -1;
	while (++i < map->height)
	{
		map->line[i] = ft_atoi(ft_split(line, ' '));
		free(line);
	}
	if (map->width <= 0 || map->height <= 0)
		ft_puterror("Error: map size <= 0");
}

static int	file_check(char *filename)
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

	fd = file_check(filename);
	if (fd == -1)
		ft_puterror("Failed to open file.");
	mapset(map, fd);
	close(fd);
}
