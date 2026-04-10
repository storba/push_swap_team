/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svpanfil <svpanfil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/10 15:11:28 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/03/13 10:10:12 by sveta         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0 && s[i] != (unsigned char)c)
	{
		i--;
	}
	if (i < 0)
		return (NULL);
	return ((char *)s + i);
}
