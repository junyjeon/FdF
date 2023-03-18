/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:49:48 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/18 11:47:55 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_map_z_min_max(t_map *map, int i, int j)
{
	if (map->z_max < map->map[i][j])
		map->z_max = map->map[i][j];
	if (map->map[i][j] < map->z_min)
		map->z_min = map->map[i][j];
}

static void	get_map(t_map *map, t_list *lst)
{
	int		i;
	int		j;
	char	**split;

	map->map = (int **)malloc(sizeof(int *) * map->height);
	if (map->map == NULL)
		ft_puterror("Error: map mallocate fail");
	i = 0;
	while (lst)
	{
		map->map[i] = (int *)malloc(sizeof(int) * map->width);
		if (map->map[i] == NULL)
			ft_puterror("Error: map[i] mallocate fail\n");
		split = ft_split(lst->content, ' ');
		j = -1;
		while (split[++j])
		{
			map->map[i][j] = ft_atoi(split[j]);
			if (split[j])
				free(split[j]);
			set_map_z_min_max(map, i, j);
		}
		lst = lst->next;
		free(split);
		i++;
	}
}

static void	set_map(t_map *map, int fd)
{
	t_list	**lst;
	char	*line;

	line = get_next_line(fd);
	lst = (t_list **)malloc(sizeof(t_list *)); // lst->next가  null인게 보장 안됨...
	(*lst)->next = NULL;
	while (line)
	{
		ft_lstadd_back(lst, ft_lstnew(line));
		line = get_next_line(fd);
	}
	map->width = ft_strlen((*lst)->content);
	map->height = ft_lstsize(*lst);
	get_map(map, *lst);
	ft_lstclear(lst, free);
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

	