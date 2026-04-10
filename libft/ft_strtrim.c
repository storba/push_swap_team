/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svpanfil <svpanfil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/17 13:46:43 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/03/17 16:08:29 by svpanfil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_in_set(char c, char const *set)
{
	size_t	i;
	size_t	set_len;

	set_len = ft_strlen(set);
	i = 0;
	while (i < set_len)
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	str_len;
	size_t	start;
	size_t	end;
	char	*res;

	if (s1 == NULL || set == NULL)
		return (NULL);
	str_len = ft_strlen(s1);
	start = 0;
	end = str_len - 1;
	while (start < str_len && char_in_set(s1[start], set))
		start++;
	while (end > start && char_in_set(s1[end], set))
		end--;
	res = (char *)malloc (sizeof(char) * (end - start + 2));
	if (res == NULL)
		return (NULL);
	i = -1;
	while (++i < end - start + 1)
		res[i] = s1[start + i];
	res[i] = '\0';
	return (res);
}
/* int main()
{
	char *s1 = "ab cd  f ";
	char *set = " ";
	char *s = ft_strtrim(s1, set);
	printf("<%s>",s);
	free (s);
	return(0);

} */