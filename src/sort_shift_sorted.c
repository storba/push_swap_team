/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_shift_sorted.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: svpanfil <svpanfil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/09 15:48:31 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/04/09 18:59:34 by sveta         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_shifta_sorted(t_Stack *stack, t_Info *info)
{
	int		min_value;
	int		i;
	t_Node	*current;

	if (is_sorted(stack))
		return ;
	i = 0;
	min_value = get_min_value(stack);
	current = stack->head;
	while (current->next && current->value != min_value)
	{
		current = current->next;
		i++;
	}
	if (i + 1 <= stack->size / 2)
	{
		while (stack->head->value != min_value)
			do_ra(stack, info);
	}
	else
		while (stack->head->value != min_value)
			do_rra(stack, info);
}

void	sort_shiftb_sorted(t_Stack *stack, t_Info *info)
{
	int		min_value;
	int		i;
	t_Node	*current;

	if (is_reverse_sorted(stack))
		return ;
	i = 0;
	min_value = get_min_value(stack);
	current = stack->head;
	while (current->next && current->value != min_value)
	{
		current = current->next;
		i++;
	}
	if (i < stack->size / 2)
	{
		while (stack->tail->value != min_value)
			do_rb(stack, info);
	}
	else
		while (stack->tail->value != min_value)
			do_rrb(stack, info);
}
