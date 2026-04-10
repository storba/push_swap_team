/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_free.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svpanfil <svpanfil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/09 15:48:31 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/04/09 15:48:32 by svpanfil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_stack(t_Stack *stack)
{
	t_Node	*current;
	t_Node	*temp;

	current = stack->head;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
}
