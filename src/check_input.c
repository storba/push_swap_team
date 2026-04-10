/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelkorni <yelkorni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 14:06:44 by yelkorni          #+#    #+#             */
/*   Updated: 2026/04/07 14:06:50 by yelkorni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_isduplicate(int num, char **argv, int n)
{
	int	i;
	int	check_num;

	i = 0;
	while (i < n)
	{
		check_num = ft_atoi(argv[i]);
		if (check_num == num)
			return (0);
		i++;
	}
	return (1);
}

static void	free_args(int argc, char **args)
{
	if (argc == 2)
		clear_all(args);
}

/*
** Check that input are numbers and
there is no duplicate numbers
** and numbers not more than MAX_INT or less than MIN_INT
*/
int	check_input(char **args)
{
	int		i;
	int		num;
	char	*str;

	i = 0;
	while (args[i])
	{
		if (!ft_isnum(args[i]))
			return (1);
		num = ft_atoi(args[i]);
		str = ft_itoa(num);
		if (ft_strncmp(args[i], str, 11) != 0)
		{
			free(str);
			return (1);
		}
		if (!ft_isduplicate(num, args, i))
		{
			free(str);
			return (1);
		}
		free(str);
		i++;
	}
	return (0);
}
