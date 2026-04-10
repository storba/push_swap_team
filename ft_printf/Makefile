NAME = libftprintf.a
CC = cc

CFLAG = -Wextra -Werror -Wall
AR = ar rcs

SRCS = ft_printf.c \
		ft_putchar.c ft_putstring.c \
		ft_putfloat.c \
		ft_putint.c \
		ft_putnbr_base.c \
		ft_putpointer.c \
		ft_puthexlow.c \
		ft_puthexupp.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	@$(CC) $(CFLAG) -c $< -o $@
	
clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re