/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_base.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: svpanfil <svpanfil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/24 14:56:26 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/04/09 18:50:24 by sveta         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned int n, char *base, int *count, int fd)
{
	if (n >= (unsigned int)16)
		ft_putnbr_base(n / 16, base, count, fd);
	ft_putchar(base[n % 16], count, fd);
}
