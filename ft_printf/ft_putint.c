/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putint.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svpanfil <svpanfil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/24 14:56:26 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/04/09 18:50:06 by sveta         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putint(int i, int *count, int fd)
{
	unsigned int	long_n;

	if (i < 0)
	{
		long_n = -i;
		*count += write(1, "-", 1);
	}
	else
		long_n = i;
	if (long_n > 9)
		ft_putint(long_n / 10, count, fd);
	ft_putchar(long_n % 10 + '0', count, fd);
}

void	ft_putunint(unsigned int i, int *count, int fd)
{
	if (i > 9)
		ft_putint(i / 10, count, fd);
	ft_putchar(i % 10 + '0', count, fd);
}
