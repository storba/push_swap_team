/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svpanfil <svpanfil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/17 12:08:47 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/03/17 12:08:48 by svpanfil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	str_len;
	char	*res;

	str_len = ft_strlen(s1);
	res = (char *)malloc(sizeof(char) * (str_len + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i <= str_len)
	{
		res[i] = s1[i];
		i++;
	}
	return (res);
}
