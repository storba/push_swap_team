/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svpanfil <svpanfil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/24 14:20:33 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/04/06 11:14:53 by sveta         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(int fd, const char *str, ...);
void	ft_putnbr_base(unsigned int n, char *base, int *count, int fd);
void	ft_putchar(char c, int *count, int fd);
void	ft_putstring(char *s, int *count, int fd);
void	ft_putint(int i, int *count, int fd);
void	ft_putunint(unsigned int i, int *count, int fd);
void	ft_putpointer(uintptr_t p, int *count, int fd);
void	ft_puthexlow(unsigned int i, int *count, int fd);
void	ft_puthexupp(unsigned int i, int *count, int fd);
void	ft_putfloat(float f, int *count, int fd);

#endif