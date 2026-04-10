/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svpanfil <svpanfil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/17 13:46:33 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/03/19 21:12:19 by sveta         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	if (needle_len == 0 && haystack)
		return ((char *)haystack);
	while (*haystack && len >= needle_len)
	{
		if (!ft_strncmp(haystack, needle, needle_len))
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
// #include <bsd/string.h>
// int main(void)
// {
// 	char *s = "jdskjn";
// 	char *to_find = "sk";
// 	size_t len = 10;
// 	//printf("ft_strnstr=%s\n", ft_strnstr(((void*)0), to_find, len));
// 	printf("strnstr=%s\n", strnstr(((void*)0), to_find, len));
// 	return(0);
// }