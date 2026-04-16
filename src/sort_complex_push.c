/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_complex_push.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: sveta <svpanfil@student.codam.nl>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/16 19:35:15 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/04/14 20:43:30 by sveta         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_value_by_ind(int i, t_Stack *stack)
{
	int		j;
	t_Node	*current;

	current = stack->head;
	j = 0;
	while (j < i)
	{
		current = current->next;
		j++;
	}
	return (current->value);
}

void	rotate_to_val_stack_a(int i, t_Stack *stack_a, t_Info *info)
{
	int	val;

	val = get_value_by_ind(i, stack_a);
	if (i == 1)
	{
		if (stack_a->head->value > stack_a->tail->value)
			do_sa(stack_a, info);
		else
			do_ra(stack_a, info);
	}
	else if (i <= stack_a->size / 2)
	{
		while (stack_a->head->value != val)
			do_ra(stack_a, info);
	}
	else
		while (stack_a->head->value != val)
			do_rra(stack_a, info);
}

void	rotate_to_i_stack_a(int j, t_Stack *stack_a, t_Info *info)
{
	int	i;

	i = 0;
	if (j <= stack_a->size / 2)
	{
		while (i < j)
		{
			do_ra(stack_a, info);
			i++;
		}
	}
	else
	{
		while (stack_a->size - j - i > 0)
		{
			do_rra(stack_a, info);
			i++;
		}
	}
}

void	rotate_to_j_stack_b(int j, t_Stack *stack_b, t_Info *info)
{
	int	i;

	i = 0;
	if (j <= stack_b->size / 2)
	{
		while (i < j)
		{
			do_rb(stack_b, info);
			i++;
		}
	}
	else
	{
		while (stack_b->size - j - i > 0)
		{
			do_rrb(stack_b, info);
			i++;
		}
	}
}

void	push_elem_i_to_b(int i, t_Stack *stack_a, t_Stack *stack_b, t_Info *info)
{
	int		val;
	int		j;
	//t_Node	*current_b;
	int		max_b;
	int		min_b;

	max_b = get_max_value(stack_b);
	min_b = get_min_value(stack_b);
	val = get_value_by_ind(i, stack_a);
	j = count_j(val, stack_b, min_b, max_b);
	if (i <= stack_a->size / 2 && j <= stack_b->size / 2)
	{
		r_ij(i, j, stack_a, stack_b, info);
	}
	else if (i > stack_a->size / 2 && j > stack_b->size / 2)
	{
		rr_ij(i, j, stack_a, stack_b, info);
	}
	else
	{
		rotate_to_val_stack_a(i, stack_a, info);
		rotate_to_j_stack_b(j, stack_b, info);
	}
	do_pb(stack_a, stack_b, info);
}
