/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_stacks_rev_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelkorni <yelkorni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 13:27:19 by yelkorni          #+#    #+#             */
/*   Updated: 2026/04/09 13:27:33 by yelkorni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	do_rra(t_Stack *stack_a, t_Info *info)
{
	reverse_rotate(stack_a);
	ft_printf(1, "rra\n");
	info->rra++;
	info->total_ops++;
}

void	do_rrb(t_Stack *stack_b, t_Info *info)
{
	reverse_rotate(stack_b);
	ft_printf(1, "rrb\n");
	info->rrb++;
	info->total_ops++;
}

void	do_rrr(t_Stack *stack_a, t_Stack *stack_b, t_Info *info)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf(1, "rrr\n");
	info->rrr++;
	info->total_ops++;
}
