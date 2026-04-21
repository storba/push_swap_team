/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_stack.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: yelkorni <yelkorni@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/09 15:48:37 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/04/21 12:23:06 by svpanfil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_adaptive(t_Stack *stack_a, t_Stack *stack_b, t_Info *info)
{
	float	d;

	d = compute_disorder(stack_a);
	if (d < 0.2)
		sort_simple_min_max(stack_a, stack_b, info);
	else if (d < 0.5 && stack_a->size >= 10)
		sort_medium_chunk(stack_a, stack_b, info);
	else
		sort_complex(stack_a, stack_b, info);
}

void	sort_stack(t_Stack *stack_a, t_Stack *stack_b, t_Info *info)
{
	if (info->strategy == 0)
		sort_simple_min_max (stack_a, stack_b, info);
	if (info->strategy == 1)
		sort_medium_chunk (stack_a, stack_b, info);
	if (info->strategy == 2)
		sort_complex (stack_a, stack_b, info);
	if (info->strategy == 3)
		sort_adaptive (stack_a, stack_b, info);
}
