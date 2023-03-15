/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:49:48 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/15 21:29:31 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_map(t_map *map, t_list *lst)
{
	int		i;
	int		j;
	char	**split;

	map->map = (int **)malloc(sizeof(int *) * map->height);
	i = 0;
	while (lst)
	{
		map->map[i] = (int *)malloc(sizeof(int) * map->width);
		split = ft_split(lst->content, ' ');
		j = -1;
		while (split[++j])
		{
			map->map[i][j] = ft_atoi(split[j]);
			if (split[j])
				free(split[j]);
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
	lst = (t_list **)malloc(sizeof(t_list *));
	while (line)
	{
		ft_lstadd_back(lst, ft_lstnew((void *)line));
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

	