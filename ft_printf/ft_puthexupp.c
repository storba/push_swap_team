/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_puthexupp.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: svpanfil <svpanfil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/24 14:56:26 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/04/09 18:49:57 by sveta         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexupp(unsigned int i, int *count, int fd)
{
	char	*base;

	base = "0123456789ABCDEF";
	ft_putnbr_base(i, base, count, fd);
}
