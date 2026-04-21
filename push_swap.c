/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yelkorni <yelkorni@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/03 14:52:12 by yelkorni      #+#    #+#                 */
/*   Updated: 2026/04/21 12:36:48 by svpanfil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	main(int argc, char **argv)
{
	t_Stack	stack_a;
	t_Stack	stack_b;
	t_Info	info;

	info = parse_input(argc, argv);
	if (info.error)
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	if (fill_stack_from_args(argc, argv, &stack_a))
		return (1);
	info.disorder = compute_disorder(&stack_a);
	if (is_sorted(&stack_a))
	{
		if (info.benchmark == 1)
			write_bench_info(info);
		free_stack(&stack_a);
		return (0);
	}
	init_stack(&stack_b);
	sort_stack(&stack_a, &stack_b, &info);
	if (info.benchmark == 1)
		write_bench_info(info);
	return (free_two_stacks(&stack_a, &stack_b));
}
