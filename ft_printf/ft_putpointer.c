/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putpointer.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: svpanfil <svpanfil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/24 14:56:26 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/04/09 18:50:32 by sveta         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putintptr_base(uintptr_t n, char *base, int *count, int fd)
{
	if (n >= 16)
		ft_putintptr_base(n / 16, base, count, fd);
	ft_putchar(base[n % 16], count, fd);
}

void	ft_putpointer(uintptr_t p, int *count, int fd)
{
	if (p == 0)
	{
		*count += write(fd, "(nil)", 5);
	}
	else
	{
		ft_putstring("0x", count, fd);
		ft_putintptr_base(p, "0123456789abcdef", count, fd);
	}
}
