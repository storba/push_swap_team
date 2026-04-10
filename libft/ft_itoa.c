/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svpanfil <svpanfil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/10 14:02:19 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/03/10 14:02:21 by svpanfil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_len(int num)
{
	int	len;

	len = 1;
	while (num / 10 != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

static void	fill_positive_num(char *str, int len, unsigned int num)
{
	int	i;

	i = len - 1;
	if (num == 0)
		str[i] = '0';
	else
	{
		while (num > 0)
		{
			str[i] = num % 10 + '0';
			num = num / 10;
			i--;
		}
	}
}

char	*ft_itoa(int n)
{
	unsigned int	num;
	char			*res;
	int				len;

	if (n >= 0)
		num = n;
	else
		num = -n;
	len = count_len(num);
	if (n < 0)
		len++;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	res[len] = '\0';
	if (n < 0)
		res[0] = '-';
	fill_positive_num(res, len, num);
	return (res);
}

// int main()
// {
// 	char *str;
// 	int n = -102590;
// 	str = ft_itoa(n);
// 	printf("%s\n", str);
// 	free(str);
// 	return (0);
// }