/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_print.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svpanfil <svpanfil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/09 15:48:48 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/04/09 15:48:49 by svpanfil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_stack(t_Stack *stack)
{
	t_Node	*current;

	current = stack->head;
	while (current)
	{
		ft_printf(1, "%d", current->value);
		if (current->next)
		{
			ft_printf(1, "\n");
		}
		current = current->next;
	}
	ft_printf(1, "\n");
}
