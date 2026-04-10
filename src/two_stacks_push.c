/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_stacks_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelkorni <yelkorni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 13:27:05 by yelkorni          #+#    #+#             */
/*   Updated: 2026/04/09 13:27:35 by yelkorni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	do_pa(t_Stack *stack_a, t_Stack *stack_b, t_Info *info)
{
	t_Node	*node;

	node = pop_front(stack_b);
	push_front_node(stack_a, node);
	ft_printf(1, "pa\n");
	info->pa++;
	info->total_ops++;
}

void	do_pb(t_Stack *stack_a, t_Stack *stack_b, t_Info *info)
{
	t_Node	*node;

	node = pop_front(stack_a);
	push_front_node(stack_b, node);
	ft_printf(1, "pb\n");
	info->pb++;
	info->total_ops++;
}
