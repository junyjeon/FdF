/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:50:18 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/24 17:43:12 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(int *y, int *z, double alpha)
{
	int	prev_y;

	prev_y = *y;
	*y = prev_y * cos(alpha) + (*z) * sin(alpha);
	*z = -prev_y * sin(alpha) + (*z) * cos(alpha);
}

void	rotate_y(int *x, int *z, double beta)
{
	int	prev_x;

	prev_x = *x;
	*x = prev_x * cos(beta) + (*z) * sin(beta);
	*z = -prev_x * sin(beta) + (*z) * cos(beta);
}

void	rotate_z(int *x, int *y, double gamma)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(gamma) - prev_y * sin(gamma);
	*y = prev_x * sin(gamma) + prev_y * cos(gamma);
}

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
