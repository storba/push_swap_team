/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svpanfil <svpanfil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/10 14:02:38 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/03/10 14:52:01 by svpanfil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = b;
	while (i < len)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
// int main(void)
// {
// 	return (0);
// }