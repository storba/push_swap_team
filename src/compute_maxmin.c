/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   compute_maxmin.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: svpanfil <svpanfil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/09 15:50:11 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/04/09 15:50:12 by svpanfil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_min_value(t_Stack *stack)
{
	t_Node	*current;
	int		min_value;

	current = stack->head;
	min_value = current->value;
	while (current)
	{
		if (current->value < min_value)
			min_value = current->value;
		current = current->next;
	}
	return (min_value);
}

int	get_max_value(t_Stack *stack)
{
	t_Node	*current;
	int		max_value;

	current = stack->head;
	max_value = current->value;
	while (current)
	{
		if (current->value > max_value)
			max_value = current->value;
		current = current->next;
	}
	return (max_value);
}
