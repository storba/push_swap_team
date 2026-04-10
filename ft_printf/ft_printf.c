/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svpanfil <svpanfil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/24 14:56:26 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/04/09 18:49:02 by sveta         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_switch(va_list *args, char *str, int *count, int fd)
{
	if (*str == 'd')
		ft_putint(va_arg(*args, int), count, fd);
	else if (*str == 'i')
		ft_putint(va_arg(*args, int), count, fd);
	else if (*str == 'c')
		ft_putchar (va_arg(*args, int), count, fd);
	else if (*str == 's')
		ft_putstring (va_arg(*args, char *), count, fd);
	else if (*str == '%')
		ft_putchar('%', count, fd);
	else if (*str == 'p')
		ft_putpointer(va_arg(*args, uintptr_t), count, fd);
	else if (*str == 'u')
		ft_putunint(va_arg(*args, unsigned int), count, fd);
	else if (*str == 'x')
		ft_puthexlow(va_arg(*args, unsigned int), count, fd);
	else if (*str == 'X')
		ft_puthexupp(va_arg(*args, unsigned int), count, fd);
	else if (*str == 'f')
		ft_putfloat((float)va_arg(*args, double), count, fd);
	else
		*count = -1;
}

int	ft_printf(int fd, const char *str, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str != '%')
			count += write (fd, str, 1);
		else
		{
			str++;
			ft_switch(&args, (char *)str, &count, fd);
		}
		if (count == -1)
			return (-1);
		str++;
	}
	va_end(args);
	return (count);
}

// int	main(void)
// {
// 	// int count1;
// 	// int count2;
// 	int				n;
// 	// unsigned int	un;
// 	// unsigned int	hexlo;
// 	// unsigned int	hexup;
// 	int				*p;
// 	// char			c;
// 	// char str[] = "string";
// 	//  n = -12345;
// 	// un = 48373868;
// 	// hexlo = 11;
// 	// hexup = 483733368;
// 	p = &n;
// 	//c = 'f';
// 	ft_printf("write %p\n", p);
// 	printf("write %p\n", p);
// 	// ft_printf("write %s %c %i %d  different\n", str, c, n, un);
// 	// ft_printf("write %x %X %p different %% \n", hexlo, hexup, p);
// 	// ft_printf("%p", 0);
// 	// ft_printf("\n%p %p\n", 0, 0);
// 	//count1 = ft_printf("\nwrite% write\n");
// 	//count2 = printf("%13.6d\n", n);
// 	//printf("\n%d %d\n", count1, count2);
// 	//printf("-------------------\n");
// 	//count1 = ft_printf("\nWrite% bla-bla-bla");
// 	//count2 = printf("%+015.10d\n", un);
// 	//printf("\n%d %d\n", count1, count2);
// 	return(0);
// }