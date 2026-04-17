/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelkorni <yelkorni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:00:35 by svpanfil      #+  #+#    #+#             */
/*   Updated: 2026/04/16 12:08:07 by yelkorni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\r'
		|| c == '\f' || c == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	res = 0;
	while (str[i] && str[i] <= '9' && str[i] >= '0')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	res *= sign;
	return (res);
}
