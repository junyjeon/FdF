/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:49:48 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/12 15:50:36 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	mapset(t_map *map, int fd)
{
	int i;
	int j;
	char	*line;
	char	**split;

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