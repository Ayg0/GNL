/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyseven <gyseven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:40:24 by ted-dafi          #+#    #+#             */
/*   Updated: 2021/11/23 10:52:30 by gyseven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*ft_substr(char *start, size_t len)
{
	char	*p;
	size_t	i;

	i = 0;
	p = (char *)malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (*start && len)
	{
		p[i] = *start;
		i++;
		start++;
		len--;
	}
	p[i] = '\0';
	return (p);
}
char *just_do_it(int fd, char **b, char *line, int re)
{
	char	*i;
	char	*f;

	i = ft_strchr(*b, '\n');
	if (i)
	{
		line = ft_strjoin(line, *b);
		*b = ft_substr(*b, i - *b);
		f = ft_substr(line, ft_strchr(line, '\n') - line);
		free(line);
		return (f);
	}
	else if (re)
		{
			re = read(fd, *b, BUFFER_SIZE);
			if(re)
				(*b)[re] = '\0';
			line = ft_strjoin(line, *b);
		}
}
char *get_next_line(int fd)
{
	static char	*b;
	char		*line;
	int			re;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if(!b)
	{
		b = (char *)malloc(sizeof(char) * (BUFFER_SIZE));
		if (!b)
			return (NULL);
		re = read(fd, b, BUFFER_SIZE);
		if (re)
			b[re] = '\0';
		else
			return (NULL);
	}
	line = ft_strdup("");
	return(just_do_it(fd, &b, line, re));
}
