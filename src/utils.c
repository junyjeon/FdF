/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:50:18 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/25 23:58:22 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_puterror(char *str)
{
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
	exit(1);
}

int	ft_atoi_base(char *str)
{
	long long	res;

	if (*str == '\0')
		return (0);
	res = 0;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	while (*str)
	{
		if ('0' <= *str && *str <= '9')
			res = res * 16 + (*str - '0');
		if ('A' <= *str && *str <= 'F')
			res = res * 16 + (*str - 55);
		if ('a' <= *str && *str <= 'f')
			res = res * 16 + (*str - 87);
		str++;
	}
	return (res);
}
