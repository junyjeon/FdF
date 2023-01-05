/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_file_type.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 21:03:08 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/04 21:16:25 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_valid_file_type(char *ar)
{
	char	*path_divided;
	int		size;
	int		ans;

	size = 0;
	path_divided = ft_split(ar, '.');
	if (!path_divided)
		perror("malloc error");
	while (path_divided[size] != 0)
		size++;
	if (ft_strncmp(path_divided[size - 1], "fdf", 4) == 0)
		ans = 1;
	free(path_divided);
	return (ans);
}
