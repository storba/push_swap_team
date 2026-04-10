/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_input.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svpanfil <svpanfil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/09 15:50:22 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/04/09 15:50:23 by svpanfil      ########   odam.nl         */
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

void	check_one_arg(char *arg, t_Info *info, int *count_strategy)
{
	if (ft_strncmp(arg, "--simple", 9) == 0)
	{
		info->strategy = 0;
		count_strategy ++;
	}
	else if (ft_strncmp(arg, "--medium", 9) == 0)
	{
		info->strategy = 1;
		count_strategy++;
	}
	else if (ft_strncmp(arg, "--complex", 10) == 0)
	{
		info->strategy = 2;
		count_strategy++;
	}
	else if (ft_strncmp(arg, "--adaptive", 11) == 0)
	{
		info->strategy = 3;
		count_strategy++;
	}
	else if (ft_strncmp(arg, "--bench", 8) == 0)
		info->benchmark = 1;
	else if (ft_strncmp(arg, "--", 2) == 0)
		info->error = 1;
}

t_Info	parse_input(int argc, char **argv)
{
	t_Info	info;
	int		i;
	int		count_strategy;

	i = 1;
	count_strategy = 0;
	init_info(&info);
	while (i < argc)
	{
		check_one_arg(argv[i], &info, &count_strategy);
		i++;
	}
	if (count_strategy > 1)
		info.error = 1;
	return (info);
}
