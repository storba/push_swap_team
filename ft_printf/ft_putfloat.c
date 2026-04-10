/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putfloat.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svpanfil <svpanfil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/24 14:56:26 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/04/09 18:49:41 by sveta         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putfloat(float f, int *count, int fd)
{
	int	scaled;
	int	whole;
	int	frac;

	if (f < 0.0f)
		f = 0.0f;
	if (f > 100.0f)
		f = 100.0f;
	scaled = (int)(f * 100.0f + 0.5f);
	if (scaled > 10000)
		scaled = 10000;
	if (scaled < 0)
		scaled = 0;
	whole = scaled / 100;
	frac = scaled % 100;
	ft_putint(whole, count, fd);
	ft_putchar('.', count, fd);
	ft_putchar(frac / 10 + '0', count, fd);
	ft_putchar(frac % 10 + '0', count, fd);
}
