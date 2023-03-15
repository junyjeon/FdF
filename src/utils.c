/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:50:18 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/15 18:45:52 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_puterror(char *str)
{
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
	exit(1);
}

int	get_abs(int a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

int	get_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
