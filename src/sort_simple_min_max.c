/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple_min_max.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelkorni <yelkorni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 12:42:02 by yelkorni          #+#    #+#             */
/*   Updated: 2026/04/10 10:58:39 by yelkorni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	get_min_position(t_Stack *a)
{
	int		min;
	int		i;
	t_Node	*current;

	current = a->head;
	min = get_min_value(a);
	i = 1;
	while (current->value != min)
	{
		i++;
		current = current->next;
	}
	return (i);
}

static void	move_min_to_top(t_Stack *a, int min_position, t_Info *info)
{
	int	j;

	if (min_position <= a->size / 2)
	{
		j = 0;
		while (j < min_position - 1)
		{
			do_ra(a, info);
			j++;
		}
	}
	else
	{
		j = 0;
		while (j < a->size - min_position + 1)
		{
			do_rra(a, info);
			j++;
		}
	}
}

void	sort_simple_min_max(t_Stack *a, t_Stack *b, t_Info *info)
{
	int	min_position;

	if (is_sorted(a))
		return ;
	while (a->size > 1)
	{
		min_position = get_min_position(a);
		move_min_to_top(a, min_position, info);
		if (!(is_sorted(a)))
			do_pb(a, b, info);
		else
			break ;
	}
	while (b->size > 0)
		do_pa(a, b, info);
}
