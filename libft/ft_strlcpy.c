/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svpanfil <svpanfil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/10 14:03:01 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/03/17 15:13:39 by svpanfil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_src;

	i = 0;
	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src);
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len_src);
}
// int	main(void)
// {
// 	char src[] = "lala";
// 	char dst1[15];
// 	char dst2[15];
// 	int n = 2;
// 	int n1 = ft_strlcpy(dst1, src, n);
// 	int n2 = strlcpy(dst2, src, n);
// 	printf("ft_strlcpy dst=%s, n=%d\n", dst1, n1);
// 	printf("strlcpy dst=%s, n=%d\n", dst2, n2);
// }