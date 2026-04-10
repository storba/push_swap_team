/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   two_stacks_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: yelkorni <yelkorni@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/09 15:48:37 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/04/09 19:02:10 by sveta         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	do_pa_bon(t_Stack *stack_a, t_Stack *stack_b)
{
	t_Node	*node;

	if (stack_b->size > 0)
	{
		node = pop_front(stack_b);
		push_front_node(stack_a, node);
	}
}

void	do_pb_bon(t_Stack *stack_a, t_Stack *stack_b)
{
	t_Node	*node;

	if (stack_a->size > 0)
	{
		node = pop_front(stack_a);
		push_front_node(stack_b, node);
	}
}

void	do_ss_bon(t_Stack *stack_a, t_Stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

void	do_rr_bon(t_Stack *stack_a, t_Stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

void	do_rrr_bon(t_Stack *stack_a, t_Stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
