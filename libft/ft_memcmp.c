/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svpanfil <svpanfil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/17 12:08:06 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/03/19 15:44:50 by svpanfil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*char_s1;
	unsigned char	*char_s2;

	char_s1 = (unsigned char *)s1;
	char_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (*char_s1 != *char_s2)
		{
			return (*char_s1 - *char_s2);
		}
		char_s1++;
		char_s2++;
		i++;
	}
	return (0);
}
/*  #include <string.h>
int main(void)
{
	char *s1 = "abc";
	char *s2 = "abc";
	size_t n = 9;

	printf("ft_memcmp=%d\n", ft_memcmp(s1,s2,n));
	printf("memcmp=%d\n", memcmp(s1,s2,n));
} */