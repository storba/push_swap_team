/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_pop.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svpanfil <svpanfil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/09 15:48:43 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/04/11 19:11:11 by sveta         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_Node	*pop_front(t_Stack *stack)
{
	//int		value;
	t_Node	*temp;

	if (!stack->head)
		return (NULL);
	//value = stack->head->value;
	temp = stack->head;
	stack->head = stack->head->next;
	if (stack->head)
		stack->head->prev = NULL;
	else
		stack->tail = NULL;
	temp->next = NULL;
	stack->size--;
	return (temp);
}

int	pop_back(t_Stack *stack)
{
	int		value;
	t_Node	*temp;

	if (!stack->tail)
		return (-1);
	value = stack->tail->value;
	temp = stack->tail;
	stack->tail = stack->tail->prev;
	if (stack->tail)
		stack->tail->next = NULL;
	else
		stack->head = NULL;
	free(temp);
	stack->size--;
	return (value);
}
