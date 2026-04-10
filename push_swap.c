/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yelkorni <yelkorni@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/03 14:52:12 by yelkorni      #+#    #+#                 */
/*   Updated: 2026/04/09 18:43:48 by sveta         ########   odam.nl         */
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
		free_stack(&stack_a);
		return (0);
	}
	init_stack(&stack_b);
	sort_stack(&stack_a, &stack_b, &info);
	if (info.benchmark == 1)
		write_bench_info(info);
	free_two_stacks(&stack_a, &stack_b);
	return (0);
}
