/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_stacks_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelkorni <yelkorni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 13:27:44 by yelkorni          #+#    #+#             */
/*   Updated: 2026/04/17 09:50:10 by yelkorni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	do_sa(t_Stack *stack_a, t_Info *info)
{
	swap(stack_a);
	ft_printf(1, "sa\n");
	info->sa++;
	info->total_ops++;
}

void	do_sb(t_Stack *stack_b, t_Info *info)
{
	swap(stack_b);
	ft_printf(1, "sb\n");
	info->sb++;
	info->total_ops++;
}

void	do_ss(t_Stack *stack_a, t_Stack *stack_b, t_Info *info)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf(1, "ss\n");
	info->ss++;
	info->total_ops++;
}
