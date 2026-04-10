/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_swap.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svpanfil <svpanfil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/09 15:49:04 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/04/09 15:49:05 by svpanfil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_Stack *stack)
{
	int	temp;

	if (stack->size < 2)
		return ;
	temp = stack->head->value;
	stack->head->value = stack->head->next->value;
	stack->head->next->value = temp;
}
