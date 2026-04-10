/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: svpanfil <svpanfil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/27 14:08:14 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/04/05 20:47:17 by sveta         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_clean(char **line)
{
	if (*line != NULL)
	{
		free(*line);
		*line = NULL;
	}
	return (NULL);
}

static int	ft_append(char **line, size_t *line_len,
		const char *src, size_t src_len)
{
	char	*temp;
	size_t	i;

	temp = malloc(*line_len + src_len + 1);
	if (!temp)
		return (1);
	i = 0;
	while (i < *line_len)
	{
		temp[i] = (*line)[i];
		i++;
	}
	i = 0;
	while (i < src_len)
	{
		temp[*line_len + i] = src[i];
		i++;
	}
	temp[*line_len + src_len] = '\0';
	free(*line);
	*line = temp;
	*line_len += src_len;
	return (0);
}

//find \n in buffer and add part or whole buffer to line
static int	ft_use_buffer(char *buffer, char **line, size_t *line_len)
{
	size_t	buf_len;
	size_t	nl_pos;

	buf_len = ft_strlen(buffer);
	nl_pos = 0;
	while (nl_pos < buf_len && buffer[nl_pos] != '\n')
		nl_pos++;
	if (nl_pos < buf_len)
	{
		if (ft_append(line, line_len, buffer, nl_pos + 1))
			return (1);
		ft_strlcpy(buffer, buffer + nl_pos + 1, buf_len - nl_pos);
		return (2);
	}
	if (ft_append(line, line_len, buffer, buf_len))
		return (1);
	buffer[0] = '\0';
	return (0);
}

//ft_fill_line handles one iteration of the loop — fills the buffer if empty 
//(returning -1 for EOF, -2 for error) 
//and then calls ft_use_buffer 
//(returning -2 on malloc failure, 0 to continue, 2 when \n found).
static int	ft_fill_line(int fd, char *buffer, char **line, size_t *line_len)
{
	int	ret;

	if (buffer[0] == '\0')
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == 0)
			return (-1);
		if (ret < 0)
			return (-2);
		buffer[ret] = '\0';
	}
	ret = ft_use_buffer(buffer, line, line_len);
	if (ret == 1)
		return (-2);
	return (ret);
}

//ret:
// -1 for EOF
//-2 error of reading or malloc failure
//2 \n founded
//0 continue read 
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = {0};
	char		*line;
	size_t		line_len;
	int			ret;

	line = NULL;
	line_len = 0;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	while (1)
	{
		ret = ft_fill_line(fd, buffer, &line, &line_len);
		if (ret == -1)
			break ;
		if (ret == -2)
			return (ft_clean(&line));
		if (ret == 2)
			return (line);
	}
	return (line);
}
