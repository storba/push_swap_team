/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_complex.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: svpanfil <svpanfil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/09 15:48:31 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/04/09 19:00:04 by sveta         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	push_min(t_Stack *stack_a, t_Stack *stack_b, t_Info *info)
{
	if (stack_a->head->value > stack_a->head->next->value)
		do_sa(stack_a, info);
	else if (stack_a->head->value > stack_a->tail->value)
		do_ra(stack_a, info);
	do_pb(stack_a, stack_b, info);
}

// static void	push_elem(t_Stack *stack_a, t_Stack *stack_b, t_Info *info)
// {
// 	int		max_a;
// 	int		min_a;
// 	int		i;
// 	t_Node	*current_a;
// 	int		val;

// 	i = 0;
// 	val = stack_b->head->value;
// 	max_a = get_max_value(stack_a);
// 	min_a = get_min_value(stack_a);
// 	i = count_i(val, stack_a, min_a, max_a);
// 	rotate_to_i_stack_a(i, stack_a);
// 	do_pa(stack_a, stack_b, info);
// }

void	sort_complex(t_Stack *stack_a, t_Stack *stack_b, t_Info *info)
{
	(void)stack_a;
	(void)stack_b;
	(void)info;
// 	int	i;

// 	i = 0;
// 	while (i < 2)
// 	{
// 		push_min(stack_a, stack_b);
// 		i++;
// 	}
// 	if (stack_a->size == 4)
// 		sort_4(stack_a, stack_b, info);
// 	else
// 	{
// 		while (stack_a->size > 5)
// 		{
// 			i = count_min_cost(stack_a, stack_b);
// 			push_el(i, stack_a, stack_b, info);
// 		}
// 		sort_5(stack_a, stack_b, info);
// 	}
// 	sort_shiftb_sorted(stack_b, info);
// 	push_from_s_b(stack_a, stack_b);
// 	sort_shifta_sorted(stack_a, info);
}
