/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_init.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svpanfil <svpanfil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/09 15:48:37 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/04/10 15:26:41 by svpanfil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_Node	*create_node(int value)
{
	t_Node	*new_node;

	new_node = (t_Node *)malloc(sizeof(t_Node));
	if (new_node == NULL)
		return (NULL);
	new_node->value = value;
	new_node->index = -1;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	init_stack(t_Stack *stack)
{
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
}
