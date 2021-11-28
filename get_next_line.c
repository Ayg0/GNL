/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ted-dafi <ted-dafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:40:24 by ted-dafi          #+#    #+#             */
/*   Updated: 2021/11/28 18:58:44 by ted-dafi         ###   ########.fr       */
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
char	*my_free(char **buff)
{
	free(*buff);
	*buff = NULL;
	return(NULL);
}

void	final(char **line, char **buff)
{
	char	*temp;
	int		i;

	i = ft_newlchr(*buff);
	if (i >= 0)
	{
		*line = ft_substr(*buff, 0, i + 1);
		temp = *buff;
		*buff = ft_substr(*buff, i + 1, ft_strlen(*buff));
		my_free(&temp);
	}
	else
	{
		*line = ft_strdup(*buff);
		my_free(buff);	
	}
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		temp[BUFFER_SIZE + 1];
	char		*line;
	int			re;

	re = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buff)
		buff = ft_strdup("");
	while(re > 0 && ft_newlchr(buff) < 0)
	{
		re = read(fd, temp, BUFFER_SIZE);
		if (re < 0)
			return (my_free(&buff));
		temp[re] = '\0';
		buff = ft_strjoin(&buff, temp);
	}
	final(&line, &buff);
	if (ft_strlen(line) == 0)
		my_free(&line);
	return (line);
}
