/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_stack.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svpanfil <svpanfil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/09 15:50:32 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/04/10 16:46:05 by sveta         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	free_args(int flag_split, char **args)
{
	int	i;

	if (!flag_split)
		return ;
	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

static int	push_from_input(char **args, t_Stack *stack)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (!push_back(stack, ft_atoi(args[i])))
			return (0);
		i++;
	}
	return (1);
}

int	fill_stack_from_args(int argc, char **argv, t_Stack *stack)
{
	char	**args;
	int		start;
	int		flag_split;

	start = 1;
	flag_split = 0;
	if (argc <= 1)
		return (1);
	while (argv[start] && ft_strncmp(argv[start], "--", 2) == 0)
		start++;
	if (argv[start] == NULL)
		return (1);
	if (argv[start + 1] == NULL)
	{
		args = ft_split(argv[start], ' ');
		flag_split = 1;
	}
	else
		args = &argv[start];
	if (check_input(args))
	{
		ft_putendl_fd("Error", 2);
		free_args(flag_split, args);
		return (1);
	}
	init_stack(stack);
	if (!push_from_input(args, stack))
	{
		ft_putendl_fd("Error with malloc memory", 2);
		free_stack(stack);
		free_args(flag_split, args);
		return (1);
	}
	free_args(flag_split, args);
	return (0);
}
