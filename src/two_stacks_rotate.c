/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_stacks_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelkorni <yelkorni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 13:27:29 by yelkorni          #+#    #+#             */
/*   Updated: 2026/04/09 13:27:38 by yelkorni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	do_ra(t_Stack *stack_a, t_Info *info)
{
	rotate(stack_a);
	ft_printf(1, "ra\n");
	info->ra++;
	info->total_ops++;
}

void	do_rb(t_Stack *stack_b, t_Info *info)
{
	rotate(stack_b);
	ft_printf(1, "rb\n");
	info->rb++;
	info->total_ops++;
}

void	do_rr(t_Stack *stack_a, t_Stack *stack_b, t_Info *info)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf(1, "rr\n");
	info->rr++;
	info->total_ops++;
}
