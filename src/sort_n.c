/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_n.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: svpanfil <svpanfil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/09 15:48:31 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/04/09 18:59:41 by sveta         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_2(t_Stack *stack_a, t_Info *info)
{
	if (stack_a->head->value > stack_a->head->next->value)
		do_sa(stack_a, info);
}

void	sort_3(t_Stack *stack_a, t_Info *info)
{
	int	min;

	if (is_sorted(stack_a))
		return ;
	min = get_min_value(stack_a);
	if (is_reverse_sorted(stack_a))
	{
		do_sa(stack_a, info);
		do_rra(stack_a, info);
	}
	else if (stack_a->head->value == min)
	{
		do_rra(stack_a, info);
		do_sa(stack_a, info);
	}
	else if (stack_a->tail->value == min)
		do_rra(stack_a, info);
	else if (stack_a->head->next->value == min)
	{
		if (stack_a->head->value < stack_a->tail->value)
			do_sa(stack_a, info);
		else
			do_ra(stack_a, info);
	}
}

void	sort_4(t_Stack *stack_a, t_Stack *stack_b, t_Info *info)
{
	int	min_a;

	min_a = get_min_value(stack_a);
	if (stack_a->head->next->value == min_a)
		do_sa(stack_a, info);
	else if (stack_a->tail->value == min_a)
		do_rra(stack_a, info);
	else if (stack_a->tail->prev->value == min_a)
	{
		do_rra(stack_a, info);
		do_rra(stack_a, info);
	}
	do_pb(stack_a, stack_b, info);
	sort_3(stack_a, info);
	do_pa(stack_a, stack_b, info);
}

void	sort_5(t_Stack *stack_a, t_Stack *stack_b, t_Info *info)
{
	int	min_a;

	min_a = get_min_value(stack_a);
	if (stack_a->head->next->value == min_a)
		do_sa(stack_a, info);
	else if (stack_a->tail->value == min_a)
		do_rra(stack_a, info);
	else if (stack_a->tail->prev->value == min_a)
	{
		do_rra(stack_a, info);
		do_rra(stack_a, info);
	}
	else if (stack_a->head->value != min_a)
	{
		do_ra(stack_a, info);
		do_ra(stack_a, info);
	}
	do_pb(stack_a, stack_b, info);
	sort_4(stack_a, stack_b, info);
	do_pa(stack_a, stack_b, info);
}
