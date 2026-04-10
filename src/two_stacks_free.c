/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_stacks_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelkorni <yelkorni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 13:26:52 by yelkorni          #+#    #+#             */
/*   Updated: 2026/04/09 13:27:36 by yelkorni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_two_stacks(t_Stack *stack_a, t_Stack *stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
}
