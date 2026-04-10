/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: svpanfil <svpanfil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/10 14:01:10 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/03/10 14:50:36 by svpanfil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = s;
	if (n == 0)
		return ;
	while (n > 0)
	{
		*str = '\0';
		str++;
		n--;
	}
}
