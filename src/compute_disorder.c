/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   compute_disorder.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: svpanfil <svpanfil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/09 15:50:04 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/04/10 11:21:56 by svpanfil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

float	compute_disorder(t_Stack *stack)
{
	int		mistakes;
	int		total_pairs;
	t_Node	*current_i;
	t_Node	*current_j;

	mistakes = 0;
	total_pairs = 0;
	current_i = stack->head;
	while (current_i)
	{
		current_j = current_i->next;
		while (current_j)
		{
			total_pairs += 1;
			if (current_i->value > current_j->value)
				mistakes += 1;
			current_j = current_j->next;
		}
		current_i = current_i->next;
	}
	if (total_pairs == 0)
		return (0);
	return ((float)mistakes / total_pairs);
}

int	is_sorted(t_Stack *stack)
{
	t_Node	*current;

	if (stack->size < 2)
		return (1);
	current = stack->head;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	is_reverse_sorted(t_Stack *stack)
{
	t_Node	*current;

	if (stack->size < 2)
		return (1);
	current = stack->head;
	while (current->next)
	{
		if (current->value < current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	is_sorted_with_shift(t_Stack *stack)
{
	int		min_value;
	t_Node	*current;

	if (stack->size < 2 || is_sorted(stack))
		return (1);
	min_value = get_min_value(stack);
	current = stack->head;
	while (current->next && current->next->value != min_value)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	current = current->next;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	if (stack->head->value < stack->tail->value)
		if (stack->head->value != min_value)
			return (0);
	return (1);
}
