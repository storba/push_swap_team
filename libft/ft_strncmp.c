/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svpanfil <svpanfil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/10 14:33:45 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/03/19 15:02:51 by svpanfil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/* #include <string.h>
int main(void)
{
	char s1[] = "test\200";
	char s2[] = "test\0";
	int n = 6;
	printf("ft_strncmp %d\n", ft_strncmp(s1, s2, n));
	printf("strncmp %d\n", strncmp(s1, s2, n));
	return (0);
} */