/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svpanfil <svpanfil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/17 12:08:01 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/03/17 12:08:02 by svpanfil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*res;

	i = 0;
	res = (unsigned char *)s;
	while (i < n && *res != (unsigned char)c)
	{
		i++;
		res++;
	}
	if (i == n)
		return (NULL);
	else
		return (res);
}
