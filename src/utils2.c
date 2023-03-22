/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 23:59:39 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/23 00:50:26 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
