/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svpanfil <svpanfil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/09 15:48:43 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/04/14 21:51:20 by sveta         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	check_str(char *str)
{
	if (ft_strncmp(str, "pa\n", 3) == 0)
		return (1);
	if (ft_strncmp(str, "pb\n", 3) == 0)
		return (1);
	if (ft_strncmp(str, "sa\n", 3) == 0)
		return (1);
	if (ft_strncmp(str, "sb\n", 3) == 0)
		return (1);
	if (ft_strncmp(str, "ss\n", 3) == 0)
		return (1);
	if (ft_strncmp(str, "ra\n", 3) == 0)
		return (1);
	if (ft_strncmp(str, "rb\n", 3) == 0)
		return (1);
	if (ft_strncmp(str, "rr\n", 3) == 0)
		return (1);
	if (ft_strncmp(str, "rra\n", 4) == 0)
		return (1);
	if (ft_strncmp(str, "rrb\n", 4) == 0)
		return (1);
	if (ft_strncmp(str, "rrr\n", 4) == 0)
		return (1);
	return (0);
}

void	do_str(char *str, t_Stack *s_a, t_Stack	*s_b)
{
	if (ft_strncmp(str, "pa\n", 3) == 0 && s_b->size > 0)
		do_pa_bon(s_a, s_b);
	if (ft_strncmp(str, "pb\n", 3) == 0 && s_a->size > 0)
		do_pb_bon(s_a, s_b);
	if (ft_strncmp(str, "sa\n", 3) == 0)
		swap(s_a);
	if (ft_strncmp(str, "sb\n", 3) == 0)
		swap(s_b);
	if (ft_strncmp(str, "ss\n", 3) == 0)
		do_ss_bon(s_a, s_b);
	if (ft_strncmp(str, "ra\n", 3) == 0)
		rotate(s_a);
	if (ft_strncmp(str, "rb\n", 3) == 0)
		rotate(s_b);
	if (ft_strncmp(str, "rr\n", 3) == 0)
		do_rr_bon(s_a, s_b);
	if (ft_strncmp(str, "rra\n", 4) == 0)
		reverse_rotate(s_a);
	if (ft_strncmp(str, "rrb\n", 4) == 0)
		reverse_rotate(s_b);
	if (ft_strncmp(str, "rrr\n", 4) == 0)
		do_rrr_bon(s_a, s_b);
}

int	do_input(t_Stack *stack_a, t_Stack	*stack_b)
{
	char	*readed_line;

	readed_line = get_next_line(0);
	while (readed_line != NULL)
	{
		if (check_str(readed_line) == 0)
		{
			write(2, "Error\n", 6);
			free(readed_line);
			return (1);
		}
		do_str(readed_line, stack_a, stack_b);
		free(readed_line);
		readed_line = get_next_line(0);
	}
	free(readed_line);
	return (0);
}

int	main(int argc, char **argv)
{
	t_Stack	stack_a;
	t_Stack	stack_b;

	if (fill_stack_from_args(argc, argv, &stack_a))
		return (1);
	init_stack(&stack_b);
	if (do_input(&stack_a, &stack_b) == 1)
	{
		free_two_stacks(&stack_a, &stack_b);
		return (1);
	}
	if (is_sorted(&stack_a) && stack_b.size == 0)
		ft_printf(1, "OK\n");
	else
		ft_printf(1, "KO\n");
	free_two_stacks(&stack_a, &stack_b);
	return (0);
}
