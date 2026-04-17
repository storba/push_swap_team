/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelkorni <yelkorni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 15:50:22 by svpanfil      #+  #+#    #+#             */
/*   Updated: 2026/04/17 11:30:08 by yelkorni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_info(t_Info *info)
{
	info->strategy = 3;
	info->benchmark = 0;
	info->error = 0;
	info->disorder = 0;
	info->total_ops = 0;
	info->pa = 0;
	info->pb = 0;
	info->sa = 0;
	info->sb = 0;
	info->ss = 0;
	info->ra = 0;
	info->rb = 0;
	info->rr = 0;
	info->rra = 0;
	info->rrb = 0;
	info->rrr = 0;
}
static void change_strategy(int str,t_Info *info, int *count_strategy)
{
	info->strategy = str;
	(*count_strategy)++;
}
void	check_one_arg(char *arg, t_Info *info, int *count_strategy, int *count_benchmark)
{
	if (ft_strncmp(arg, "--simple", 9) == 0)
		change_strategy(0, info, count_strategy);
	else if (ft_strncmp(arg, "--medium", 9) == 0)
		change_strategy(1, info, count_strategy);
	else if (ft_strncmp(arg, "--complex", 10) == 0)
		change_strategy(2, info, count_strategy);
	else if (ft_strncmp(arg, "--adaptive", 11) == 0)
		change_strategy(3, info, count_strategy);
	else if (ft_strncmp(arg, "--bench", 8) == 0)
	{
		info->benchmark = 1;
		(*count_benchmark)++;
	}
	else if (ft_strncmp(arg, "--", 2) == 0)
		info->error = 1;
}

t_Info	parse_input(int argc, char **argv)
{
	t_Info	info;
	int		i;
	int		count_strategy;
	int		count_benchmark;

	i = 1;
	count_strategy = 0;
	count_benchmark = 0;
	init_info(&info);
	while (i < argc)
	{
		check_one_arg(argv[i], &info, &count_strategy, &count_benchmark);
		i++;
	}
	if (count_strategy > 1 || count_benchmark > 1)
		info.error = 1;
	return (info);
}
