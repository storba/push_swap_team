/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_simple.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svpanfil <svpanfil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/09 15:48:31 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/04/09 19:08:50 by sveta         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
/*
** Bubble sort adaptation - O(n^2)
**
** Each pass bubbles the largest unsorted element to the bottom of the
** unsorted portion.  We scan through n-sorted-1 adjacent pairs using ra,
** swap out-of-order neighbours with sa, then undo all rotations with rra.
** After each pass one more element is sorted at the tail.
*/

void	sort_simple(t_Stack *stack_a, t_Stack *stack_b, t_Info *info)
{
	int	sorted;
	int	i;
	int	n;
	int	swapped;

	(void)stack_b;
	n = stack_a->size;
	sorted = 0;
	while (!is_sorted(stack_a))
	{
		i = 0;
		swapped = 0;
		while (i < n - sorted - 1)
		{
			if (stack_a->head->value > stack_a->head->next->value)
			{
				do_sa(stack_a, info);
				swapped = 1;
			}
			do_ra(stack_a, info);
			i++;
		}
		i = 0;
		while (i < n - sorted - 1)
		{
			do_rra(stack_a, info);
			i++;
		}
		if (!swapped)
			break ;
		sorted++;
	}
}
