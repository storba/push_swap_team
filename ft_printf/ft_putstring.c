/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstring.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: svpanfil <svpanfil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/24 14:56:26 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/04/09 18:50:39 by sveta         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstring(char *s, int *count, int fd)
{
	if (s == NULL)
		s = "(null)";
	while (*s)
		ft_putchar(*s++, count, fd);
}
