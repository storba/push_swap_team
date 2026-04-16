/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_complex_count_j.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: svpanfil <svpanfil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/16 13:02:15 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/04/16 13:06:55 by svpanfil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	count_j_min(int min_b, t_Stack *stack_b)
{
	int		j;
	t_Node	*current_b;

	j = 0;
	current_b = stack_b->head;
	while (current_b->next && current_b->value != min_b)
	{
		current_b = current_b->next;
		j++;
	}
	j++;
	if (j == stack_b->size)
		j = 0;
	return (j);
}

static int	count_j_max(int max_b, t_Stack *stack_b)
{
	int		j;
	t_Node	*current_b;

	j = 0;
	current_b = stack_b->head;
	current_b = stack_b->head;
	while (current_b->next && current_b->value != max_b)
	{
		current_b = current_b->next;
		j++;
	}
	return (j);
}

int	count_j(int val, t_Stack *stack_b, int min_b, int max_b)
{
	int		j;
	t_Node	*current_b;

	j = 0;
	if (val < min_b)
	{
		j = count_j_min(min_b, stack_b);
	}
	else if (val > max_b)
	{
		j = count_j_max(max_b, stack_b);
	}
	else if (val > stack_b->head->value && val < stack_b->tail->value)
		j = 0;
	else
	{
		current_b = stack_b->head;
		while (!(current_b->value > val && current_b->next->value < val))
		{
			j++;
			current_b = current_b->next;
		}
		j++;
	}
	return (j);
}
