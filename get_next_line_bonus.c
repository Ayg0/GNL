/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ted-dafi <ted-dafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 20:52:52 by ted-dafi          #+#    #+#             */
/*   Updated: 2021/11/29 13:20:23 by ted-dafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*my_free(char **buff, char **temp, int flag)
{
	if (flag == 0)
	{
		free(*buff);
		*buff = NULL;
	}
	else
	{
		if (ft_strlen(*buff) == 0)
			my_free(buff, NULL, 0);
	}
	if (temp)
	{
		free(*temp);
		*temp = NULL;
	}
	return (*buff);
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
		my_free(&temp, NULL, 0);
	}
	else
	{
		*line = ft_strdup(*buff);
		my_free(buff, NULL, 0);
	}
}

char	*get_next_line(int fd)
{
	static char	*buff[1024];
	char		*temp;
	char		*line;
	int			re;

	re = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp)
		return (NULL);
	if (!buff[fd])
		buff[fd] = ft_strdup("");
	while (re > 0 && ft_newlchr(buff[fd]) < 0)
	{
		re = read(fd, temp, BUFFER_SIZE);
		if (re < 0)
			return (my_free(&buff[fd], &temp, 0));
		temp[re] = '\0';
		buff[fd] = ft_strjoin(&buff[fd], temp);
	}
	final(&line, &buff[fd]);
	my_free(&line, &temp, 1);
	return (line);
}
