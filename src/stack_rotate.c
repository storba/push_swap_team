/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_rotate.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: svpanfil <svpanfil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/09 15:49:00 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/04/09 15:49:00 by svpanfil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate(t_Stack *stack)
{
	t_Node	*old_head;
	t_Node	*new_head;

	if (stack->size < 2)
		return ;
	old_head = stack->head;
	new_head = stack->head->next;
	old_head->next = NULL;
	old_head->prev = stack->tail;
	new_head->prev = NULL;
	stack->tail->next = old_head;
	stack->tail = old_head;
	stack->head = new_head;
}

void	reverse_rotate(t_Stack *stack)
{
	t_Node	*old_tail;
	t_Node	*new_tail;

	if (stack->size < 2)
		return ;
	old_tail = stack->tail;
	new_tail = stack->tail->prev;
	new_tail->next = NULL;
	old_tail->next = stack->head;
	old_tail->prev = NULL;
	stack->head->prev = old_tail;
	stack->head = old_tail;
	stack->tail = new_tail;
}
