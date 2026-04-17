/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_bench_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelkorni <yelkorni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 13:27:44 by yelkorni      #+  #+#    #+#             */
/*   Updated: 2026/04/17 09:49:54 by yelkorni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	write_bench_info(t_Info info)
{
	const char	*strategy_names[4];

	strategy_names[0] = "Simple / O(n²)";
	strategy_names[1] = "Medium / O(n√n)";
	strategy_names[2] = "Complex / O(n log n)";
	if (info.disorder < 0.2)
		strategy_names[3] = "Adaptive O(n)";
	else if (info.disorder < 0.5)
		strategy_names[3] = "Adaptive O(n√n)";
	else
		strategy_names[3] = "Adaptive O(n log n)";
	ft_printf(2, "[bench] disorder:  %f%%\n", info.disorder * 100);
	ft_printf(2, "[bench] strategy: %s\n", strategy_names[info.strategy]);
	ft_printf(2, "[bench] total_ops: %d\n", info.total_ops);
	ft_printf(2, "[bench] sa: %d  sb: %d  ss: %d  pa: %d pb: %d\n",
		info.sa, info.sb, info.ss, info.pa, info.pb);
	ft_printf(2, "[bench] ra: %d  rb: %d  rr: %d  rra: %d rrb: %d rrr: %d\n",
		info.ra, info.rb, info.rr, info.rra, info.rrb, info.rrr);
}
