/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yelkorni <yelkorni@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/03 14:52:18 by yelkorni      #+#    #+#                 */
/*   Updated: 2026/04/13 18:30:20 by sveta         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

typedef struct Node
{
	int			value;
	int			index;
	struct Node	*prev;
	struct Node	*next;
}	t_Node;

typedef struct Stack
{
	t_Node	*head;
	t_Node	*tail;
	int		size;
}	t_Stack;

// strategy
// --simple 0, --medium 1,--complex 2, --adaptive 3(by default)
// benchmark
// 0 - off 1 - on
// error
// 0 - no error 1 - error	
typedef struct Info
{
	int		strategy;
	int		benchmark;
	int		error;
	float	disorder;
	int		total_ops;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}	t_Info;

// work with input
int		check_input(char **args);
int		fill_stack_from_args(int argc, char **argv, t_Stack *stack);
t_Info	parse_input(int argc, char **argv);

// stack functions
t_Node	*create_node(int value);
void	init_stack(t_Stack *stack);
void	free_stack(t_Stack *stack);
void	free_two_stacks(t_Stack *stack_a, t_Stack *stack_b);
void	print_stack(t_Stack *stack);
void	push_front_node(t_Stack *stack, t_Node *new_node);
int		push_front(t_Stack *stack, int value);
int		push_back(t_Stack *stack, int value);
t_Node	*pop_front(t_Stack *stack);
int		pop_back(t_Stack *stack);
void	swap(t_Stack *stack);
void	rotate(t_Stack *stack);
void	reverse_rotate(t_Stack *stack);

//two stacks operations
void	do_pa(t_Stack *stack_a, t_Stack *stack_b, t_Info *info);
void	do_pb(t_Stack *stack_a, t_Stack *stack_b, t_Info *info);
void	do_sa(t_Stack *stack_a, t_Info *info);
void	do_sb(t_Stack *stack_b, t_Info *info);
void	do_ss(t_Stack *stack_a, t_Stack *stack_b, t_Info *info);
void	do_ra(t_Stack *stack_a, t_Info *info);
void	do_rb(t_Stack *stack_b, t_Info *info);
void	do_rr(t_Stack *stack_a, t_Stack *stack_b, t_Info *info);
void	do_rra(t_Stack *stack_a, t_Info *info);
void	do_rrb(t_Stack *stack_b, t_Info *info);
void	do_rrr(t_Stack *stack_a, t_Stack *stack_b, t_Info *info);

// two stacks operations bonus
void	do_pa_bon(t_Stack *stack_a, t_Stack *stack_b);
void	do_pb_bon(t_Stack *stack_a, t_Stack *stack_b);
void	do_ss_bon(t_Stack *stack_a, t_Stack *stack_b);
void	do_rr_bon(t_Stack *stack_a, t_Stack *stack_b);
void	do_rrr_bon(t_Stack *stack_a, t_Stack *stack_b);
void	free_two_stacks(t_Stack *stack_a, t_Stack *stack_b);

// sorting strategies
void	sort_simple(t_Stack *stack_a, t_Stack *stack_b, t_Info *info);
void	sort_medium(t_Stack *stack_a, t_Stack *stack_b, t_Info *info);
void	sort_medium_chunk(t_Stack *stack_a, t_Stack *stack_b, t_Info *info);
//complex
void	sort_complex(t_Stack *stack_a, t_Stack *stack_b, t_Info *info);
int	get_value_by_ind(int i, t_Stack *stack);
void	rotate_to_val_stack_a(int i, t_Stack *stack_a, t_Info *info);
void	rotate_to_i_stack_a(int j, t_Stack *stack_a, t_Info *info);
void	rotate_to_j_stack_b(int j, t_Stack *stack_b, t_Info *info);
void	push_el(int i, t_Stack *stack_a, t_Stack *stack_b, t_Info *info);
void	r_ij(int i, int j, t_Stack *s_a, t_Stack *s_b, t_Info *info);
void	rr_ij(int i, int j, t_Stack *s_a, t_Stack *s_b, t_Info *info);
int		count_min_cost(t_Stack *stack_a, t_Stack *stack_b);
int		count_j(int val, t_Stack *stack_b, int min_b, int max_b);
int		count_i(int val, t_Stack *stack_a, int min_a, int max_a);
//adaptive
void	sort_adaptive(t_Stack *stack_a, t_Stack *stack_b, t_Info *info);
void	sort_stack(t_Stack *stack_a, t_Stack *stack_b, t_Info *input);
void	sort_shifta_sorted(t_Stack *stack, t_Info *info);
void	sort_shiftb_sorted(t_Stack *stack, t_Info *info);
void	sort_2(t_Stack *stack_a, t_Info *info);
void	sort_3(t_Stack *stack_a, t_Info *info);
void	sort_4(t_Stack *stack_a, t_Stack *stack_b, t_Info *info);
void	sort_5(t_Stack *stack_a, t_Stack *stack_b, t_Info *info);
void	sort_simple_min_max(t_Stack *a, t_Stack *b, t_Info *info);

// stack analysis
float	compute_disorder(t_Stack *stack);
int		is_sorted(t_Stack *stack);
int		is_reverse_sorted(t_Stack *stack);
int		is_sorted_with_shift(t_Stack *stack);
int		get_min_value(t_Stack *stack);
int		get_max_value(t_Stack *stack);

// write benchmark info
void	write_bench_info(t_Info input);	

#endif