/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svpanfil <svpanfil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/10 14:02:54 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/03/15 17:19:27 by sveta         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size <= len_dst)
		return (size + len_src);
	i = 0;
	while (i < size - len_dst - 1 && src[i])
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}
// #include <string.h>
// int	main(void)
// {
// 	char src[] = "lala";
// 	char dst1[15]= "aaa";
// 	char dst2[15]= "aaa";
// 	int n = 2;
// 	int n1 = ft_strlcat(dst1, src, n);
// 	int n2 = strlcat(dst2, src, n);
// 	printf("ft_strlcpy dst=%s, n=%d\n", dst1, n1);
// 	printf("strlcpy dst=%s, n=%d\n", dst2, n2);
// }