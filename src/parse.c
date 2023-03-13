/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:49:48 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/14 05:11:17 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_map2(t_map *map, t_list *lst)
{
	int		i;
	int		j;
	char	**split;

	map->map = (char **)malloc(sizeof(char *) * map->height);
	i = 0;
	while (lst)
	{
		split = ft_split(lst->content, ' ');
		j = -1;
		while (++j < map->width)
			map->map[i][j] = ft_atoi(split[i]);
		lst = lst->next;
		i++;
	}
}

static void	set_map(t_map *map, int fd)
{
	char	*line;
	t_list	*lst;

	line = get_next_line(fd);
	while (line)
	{
		ft_lstadd_back(&lst, ft_lstnew(line));
		line = get_next_line(fd);
	}
	map->width = ft_strlen(lst->content);
	map->height = ft_lstsize(lst);
	set_map2(map, lst);
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
	set_map(map, fd);
	if (map->width == 0 || map->height == 0)
		ft_puterror("Error: map size zero");
	close(fd);
}
