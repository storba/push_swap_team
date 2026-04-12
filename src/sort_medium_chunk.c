/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_chunk.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelyzavetakorniienko <yelyzavetakorniienko +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 18:56:47 by yelyzavetakornii  #+#    #+#             */
/*   Updated: 2026/04/12 20:02:21 by yelyzavetakornii ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/push_swap.h"

static int fill_index_Node(t_Stack *stack, int value)
{
	t_Node *current;
	int index;

	current = stack->head;
	index = 0;
	while(current)
	{
		if(value > current->value)
			index++;
		current = current->next;
	}
	return (index);
}

static void fill_index(t_Stack *stack)
{
	t_Node *current;

	current = stack->head;
	while (current)
	{
		current->index = fill_index_Node(stack, current->value);
		current = current->next;
	}
}

static int  get_sqrt(int n)
{
	int i;

	i = 1;
	while (i * i <= n)
		i++;
	if (n - i * i > (i + 1) * (i + 1) - n)
		return (i + 1);
	return (i);
}

static void push_chunk(t_Stack *stack_a, t_Stack *stack_b, t_Info *info, int chunk_size)
{
	int pushed;

	pushed = 0;
	while (stack_a->size > 0)
	{
		if (stack_a->head->index <= pushed)
		{
			do_pb(stack_a, stack_b, info);
			do_rb(stack_b, info);
			pushed++;
		}
		else if (stack_a->head->index <= pushed + chunk_size)
		{
			do_pb(stack_a, stack_b, info);
			pushed++;
		}
		else
			do_ra(stack_a, info);
	}
}

static int	get_max_position(t_Stack *b)
{
	int		max;
	int		i;
	t_Node	*current;

	current = b->head;
	max = get_max_value(b);
	i = 1;
	while (current->value != max)
	{
		i++;
		current = current->next;
	}
	return (i);
}

static void	move_max_to_top(t_Stack *b, int max_position, t_Info *info)
{
	int	j;

	if (max_position <= b->size / 2)
	{
		j = 0;
		while (j < max_position - 1)
		{
			do_rb(b, info);
			j++;
		}
	}
	else
	{
		j = 0;
		while (j < b->size - max_position + 1)
		{
			do_rrb(b, info);
			j++;
		}
	}
}

void	sort_medium_chunk(t_Stack *stack_a, t_Stack *stack_b, t_Info *info)
{
	int chunk_size;
	int	max_position;

	if (is_sorted(stack_a))
		return ;
	fill_index(stack_a);
	chunk_size = get_sqrt(stack_a->size);
	push_chunk(stack_a, stack_b, info, chunk_size);
	while (stack_b->size > 0)
	{
		max_position = get_max_position(stack_b);
		move_max_to_top(stack_b, max_position, info);
		do_pa(stack_a, stack_b, info);
	}
}
