/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ted-dafi <ted-dafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:40:24 by ted-dafi          #+#    #+#             */
/*   Updated: 2021/11/27 00:01:40 by ted-dafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char *final(int re, char *b, char *line, char *temp)
{
		if(re < 0 || (!re && !b))
			return (NULL);
		else
		{
			temp = ft_strchr(b, '\n');
			if (temp)
			{
				temp = ft_substr(temp + 1, (&b[ft_strlen(b)] - temp) + 1);
				line = ft_substr(b, temp - b + 2);
				free(b);
				b = temp;
				return (line);
			}
			else
				return (b);
		}
}

char	*get_next_line(int fd)
{
	static char	*b;
	char		*line;
	char		*temp;
	int			re;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = (char *)ft_calloc(BUFFER_SIZE, sizeof(char));
	if (!line)
		return (NULL);
	re = read(fd, line, BUFFER_SIZE);
	while(re)
	{
		if (!b)
			b = ft_strdup(line);
		else
		{
			temp = ft_strjoin(b, line);
			free(b);
			b = temp;
		}
		if(ft_strchr(b, '\n'))
			break;
	}
	return (final(re, b, line, temp));
}

int	main()
{
	int	fd = open("foo.txt", O_CREAT | O_RDONLY);
	printf("%s", get_next_line(fd));
}