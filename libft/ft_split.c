/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: svpanfil <svpanfil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/10 14:02:43 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/04/05 10:09:24 by sveta         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	is_word;
	int	i;
	int	n_words;

	is_word = 0;
	i = 0;
	n_words = 0;
	while (s[i])
	{
		if (is_word == 0 && s[i] != c)
		{
			is_word = 1;
			n_words++;
		}
		else if (s[i] == c)
			is_word = 0;
		i++;
	}
	return (n_words);
}

static char	*add_word(char const *s, int len, int n)
{
	char	*word;
	int		i;

	word = (char *)malloc(sizeof(char) * (len + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[n + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

void	*clear_all(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free (arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
	return (NULL);
}

static char	**fill_arr(char const *s, char c, char **res)
{
	int		i;
	int		len;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			len = 0;
			while (s[i] && s[i] != c)
			{
				len++;
				i++;
			}
			res[j] = add_word(s, len, i - len);
			if (res[j] == NULL)
				return (clear_all(res));
			j++;
		}
		else
			i++;
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		n_words;

	if (!s)
		return (NULL);
	n_words = count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (n_words + 1));
	if (res == NULL)
		return (NULL);
	res[n_words] = NULL;
	return (fill_arr(s, c, res));
}

// int main(void)
// {
// 	char  s[] = "word1 word2 word3";
// 	char c = ' ';
// 	int i = 0;
// 	char **res = ft_split(s, c);
// 	while (res[i])
// 	{
// 		printf("%s\n", res[i]);
// 		i++;
// 	}
// 	clear_all(res);
// }