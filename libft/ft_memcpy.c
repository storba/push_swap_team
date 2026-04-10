/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svpanfil <svpanfil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/10 14:02:26 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/03/15 17:21:06 by sveta         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;

	if (dst == NULL && src == NULL)
		return (NULL);
	d = (char *)dst;
	s = (char *)src;
	while (n--)
	{
		*d++ = *s++;
	}
	return (dst);
}
