/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_push.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svpanfil <svpanfil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/09 15:48:54 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/04/09 15:48:54 by svpanfil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_front_node(t_Stack *stack, t_Node *new_node)
{
	if (!stack->head)
	{
		stack->head = new_node;
		stack->tail = new_node;
	}
	else
	{
		new_node->next = stack->head;
		stack->head->prev = new_node;
		stack->head = new_node;
	}
	stack->size++;
}

int	push_front(t_Stack *stack, int value)
{
	t_Node	*new_node;

	new_node = create_node(value);
	if (new_node == NULL)
	{
		return (0);
	}
	if (!stack->head)
	{
		stack->head = new_node;
		stack->tail = new_node;
	}
	else
	{
		new_node->next = stack->head;
		stack->head->prev = new_node;
		stack->head = new_node;
	}
	stack->size++;
	return (1);
}

int	push_back(t_Stack *stack, int value)
{
	t_Node	*new_node;

	new_node = create_node(value);
	if (new_node == NULL)
	{
		return (0);
	}
	if (!stack->tail)
	{
		stack->head = new_node;
		stack->tail = new_node;
	}
	else
	{
		new_node->prev = stack->tail;
		stack->tail->next = new_node;
		stack->tail = new_node;
	}
	stack->size++;
	return (1);
}
