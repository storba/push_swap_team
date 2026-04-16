/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_complex_cost.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: svpanfil <svpanfil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/16 13:01:56 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/04/16 13:06:46 by svpanfil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	count_cost(int i, int j, int size_a, int size_b)
{
	int	cost;

	cost = 0;
	if (j <= size_b / 2)
	{
		if (i <= size_a / 2)
			cost += (j - i) * (j > i);
		else
			cost += j;
	}
	else
	{
		if (i > size_a / 2)
			cost += (size_b - j - size_a + i) * (size_b - j > size_a - i);
		else
			cost += size_b - j;
	}
	return (cost);
}

int	count_cost_b(int value_a, int i, int size_a, t_Stack *stack_b)
{
	int		cost;
	int		j;
	int		max_b;
	int		min_b;

	max_b = get_max_value(stack_b);
	min_b = get_min_value(stack_b);
	cost = 0;
	j = count_j(value_a, stack_b, min_b, max_b);
	cost = count_cost(i, j, size_a, stack_b->size);
	return (cost);
}

int	count_min_cost(t_Stack *stack_a, t_Stack *stack_b)
{
	int		i;
	int		min_cost;
	int		min_i;
	t_Node	*current;
	int		cost;

	i = 0;
	current = stack_a->head;
	min_i = i;
	min_cost = count_cost_b(current->value, i, stack_a->size, stack_b) + 1;
	while (++i < stack_a->size)
	{
		current = current->next;
		if (i <= stack_a->size / 2)
			cost = i;
		else
			cost = stack_a->size - i;
		cost += count_cost_b(current->value, i, stack_a->size, stack_b) + 1;
		if (cost < min_cost)
		{
			min_cost = cost;
			min_i = i;
		}
	}
	return (min_i);
}
