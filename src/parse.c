/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:49:48 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/23 00:28:22 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//static double	get_ratio(int s, int f, int cur)
//{
//	double	ratio;

//	if (s == f)
//		return (1.0);
//	ratio = (double)(cur - s) / (f - s);
//	return (ratio);
//}

//static int	get_default_clr(int z, t_map *map)
//{
//	double	ratio;

//	ratio = get_ratio(map->z_min, map->z_max, z);
//	if (ratio < 0.2)
//		return (CLR_DISCO);
//	else if (ratio < 0.4)
//		return (CLR_BRICK_RED);
//	else if (ratio < 0.6)
//		return (CLR_FLAMINGO);
//	else if (ratio < 0.8)
//		return (CLR_JAFFA);
//	else
//		return (CLR_SAFFRON);
//}

static void	set_dot_color(t_map *map, char **split, char *line, int i)
{
	int		j;
	char	*color;

	j = -1;
	while (split[++j])
	{
		map->dot[i][j].x = j;
		map->dot[i][j].y = i;
		map->dot[i][j].z = ft_atoi(split[j]);
		color = ft_strchr(split[j], ',');
		if (color)
			map->dot[i][j].color = ft_atoi_base(color, "0123456789ABCDEF", 16);
		else
			map->dot[i][j].color = 0x00FFFFFF;
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
		if (!map->dot)
			ft_puterror("Error: map->dot mallocte fail");
		set_dot_color(map, split, line, i);
		free(line);
	}
}

static void	cal_map_size(t_map *map, char *argv)
{
	int		i;
	int		fd;
	char	*line;
	char	**split;

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
