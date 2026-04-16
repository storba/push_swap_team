/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_complex_rotate.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: svpanfil <svpanfil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/16 13:02:23 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/04/16 13:02:24 by svpanfil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	r_ij(t_ij ij, t_Stack *s_a, t_Stack *s_b, t_Info *info)
{
	while (ij.i > 0 && ij.j > 0)
	{
		do_rr(s_a, s_b, info);
		ij.j--;
		ij.i--;
	}
	while (ij.i-- > 0)
		do_ra(s_a, info);
	while (ij.j > 0)
	{
		do_rb(s_b, info);
		ij.j--;
	}
}

void	rr_ij(t_ij ij, t_Stack *s_a, t_Stack *s_b, t_Info *info)
{
	while (s_b->size - ij.j > 0 && s_a->size - ij.i > 0)
	{
		do_rrr(s_a, s_b, info);
		ij.i++;
		ij.j++;
	}
	while (s_b->size - ij.j > 0)
	{
		do_rrb(s_b, info);
		j++;
	}
	while (s_a->size - ij.i > 0)
	{
		do_rra(s_a, info);
		ij.i++;
	}
}