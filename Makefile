#MAKEFLAGS += --no-print-directory
NAME = push_swap
CC = cc
CFLAGS = -Wextra -Werror -Wall -Iinclude 

SRCS = ./push_swap.c \
		src/check_input.c \
		src/compute_disorder.c \
		src/compute_maxmin.c \
		src/fill_input.c \
		src/fill_stack.c \
		src/stack_free.c \
		src/stack_init.c \
		src/stack_pop.c \
		src/stack_print.c \
		src/stack_push.c \
		src/stack_rotate.c \
		src/stack_swap.c \
		src/two_stacks_bonus.c \
		src/two_stacks_free.c \
		src/two_stacks_push.c \
		src/two_stacks_rev_rotate.c \
		src/two_stacks_rotate.c \
		src/two_stacks_swap.c \
		src/sort_stack.c \
		src/sort_simple.c \
		src/sort_complex.c \
		src/sort_complex_push.c src/sort_complex_rotate.c src/sort_complex_cost.c\
		src/sort_complex_count_i.c src/sort_complex_count_j.c\
		src/sort_shift_sorted.c \
		src/write_bench_info.c \
		src/sort_n.c \
		src/sort_simple_min_max.c \
		src/sort_medium_chunk.c \
		src/sort_medium_fill_ind.c 
		
OBJS = ${SRCS:.c=.o}

SRC_BONUS = ./checker.c \
		src/two_stacks_bonus.c src/fill_stack.c \
		src/check_input.c \
		src/two_stacks_free.c\
		src/compute_disorder.c src/compute_maxmin.c \
		src/stack_free.c src/stack_init.c src/stack_pop.c \
		src/stack_print.c src/stack_push.c src/stack_rotate.c \
		src/stack_swap.c


OBJ_BONUS = ${SRC_BONUS:.c=.o}

${NAME}: ${OBJS}
	make -C ./libft
	make -C ./ft_printf
	@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a ./ft_printf/libftprintf.a -o ${NAME}

all: $(NAME)

clean:
	rm -f src/*.o
	rm -f *.o
	rm -f libft/*.o
	rm -f ft_printf/*.o

fclean: clean
	rm -f $(NAME)
	rm -f checker
	rm -f libft/libft.a
	rm -f ft_printf/libftprintf.a

re: fclean all

bonus: ${OBJ_BONUS}
	make -C ./libft
	make -C ./ft_printf
	@${CC} ${CFLAGS} ${OBJ_BONUS} ./libft/libft.a ./ft_printf/libftprintf.a -o checker

.PHONY: all clean fclean re bonus