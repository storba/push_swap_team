/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_medium_fill_ind.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yelyzavetakorniienko <yelyzavetakorniie      +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/12 18:56:47 by yelyzavetak   #+#    #+#                 */
/*   Updated: 2026/04/16 13:40:28 by svpanfil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	fill_index_node(t_Stack *stack, int value)
{
	t_Node	*current;
	int		index;

	current = stack->head;
	index = 0;
	while (current)
	{
		if (value > current->value)
			index++;
		current = current->next;
	}
	return (index);
}

void	fill_index(t_Stack *stack)
{
	t_Node	*current;

	current = stack->head;
	while (current)
	{
		current->index = fill_index_node(stack, current->value);
		current = current->next;
	}
}
