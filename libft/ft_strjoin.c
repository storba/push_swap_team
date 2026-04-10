/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svpanfil <svpanfil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/10 14:02:49 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/03/10 14:02:50 by svpanfil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*join_str;
	int		i;
	int		j;

	len = ft_strlen(s1) + ft_strlen(s2);
	join_str = (char *) malloc (sizeof(char) * (len + 1));
	if (join_str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		join_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		join_str[i] = s2[j];
		i++;
		j++;
	}
	join_str[i] = '\0';
	return (join_str);
}
