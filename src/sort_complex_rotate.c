#include "../include/push_swap.h"

void	r_ij(int i, int j, t_Stack *s_a, t_Stack *s_b, t_Info *info)
{
	while (i > 0 && j > 0)
	{
		do_rr(s_a, s_b, info);
		j--;
		i--;
	}
	while (i-- > 0)
		do_ra(s_a, info);
	while (j > 0)
	{
		do_rb(s_b, info);
		j--;
	}
}

void	rr_ij(int i, int j, t_Stack *s_a, t_Stack *s_b, t_Info *info)
{
	while (s_b->size - j > 0 && s_a->size - i > 0)
	{
		do_rrr(s_a, s_b, info);
		i++;
		j++;
	}
	while (s_b->size - j > 0)
	{
		do_rrb(s_b, info);
		j++;
	}
	while (s_a->size - i > 0)
	{
		do_rra(s_a, info);
		i++;
	}
}