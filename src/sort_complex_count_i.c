/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_complex_count_i.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: svpanfil <svpanfil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/16 13:02:08 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/04/16 13:02:09 by svpanfil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	count_i_min(int min_a, t_Stack *stack_a)
{
	int		i;
	t_Node	*current_a;

	i = 0;
	current_a = stack_a->head;
	while (current_a->next && current_a->value != min_a)
	{
		current_a = current_a->next;
		i++;
	}
	if (i == stack_a->size)
		i = 0;
	return (i);
}

static int	count_i_max(int max_a, t_Stack *stack_a)
{
	int		i;
	t_Node	*current_a;

	i = 0;
	current_a = stack_a->head;
	current_a = stack_a->head;
	while (current_a->next && current_a->value != max_a)
	{
		current_a = current_a->next;
		i++;
	}
	i++;
	if (i == stack_a->size)
		i = 0;
	return (i);
}

int	count_i(int val, t_Stack *stack_a, int min_a, int max_a)
{
	int		i;
	t_Node	*current_a;

	i = 0;
	if (val < min_a)
	{
		i = count_i_min(min_a, stack_a);
	}
	else if (val > max_a)
	{
		i = count_i_max(max_a, stack_a);
	}
	else if (val < stack_a->head->value && val > stack_a->tail->value)
		i = 0;
	else
	{
		current_a = stack_a->head;
		while (!(current_a->value < val && current_a->next->value > val))
		{
			i++;
			current_a = current_a->next;
		}
		i++;
	}
	return (i);
}
