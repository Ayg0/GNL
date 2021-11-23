/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ted-dafi <ted-dafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:40:24 by ted-dafi          #+#    #+#             */
/*   Updated: 2021/11/23 23:58:47 by ted-dafi         ###   ########.fr       */
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
char *just_do_it(int fd, char **b, char *line)
{
	char	*i;
	char	*f;
	int		re;

	re = read(fd, *b, BUFFER_SIZE);
	if (re)
		(*b)[re] = '\0';
	line = ft_strjoin(line, *b);
	i = ft_strchr(*b, '\n');
	while(re && !i)
	{
		re = read(fd, *b, BUFFER_SIZE);
		if (re)
			(*b)[re] = '\0';
		i = ft_strchr(*b, '\n');
		line = ft_strjoin(line, *b);
	}
	if(i)
	{
		f = ft_substr(line, ft_strchr(line, '\n') - line + 1);
		*b = i + 1;
		free(line);
		return (f);
	}
	else
		*b = NULL;
		return(line);
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
	}
	line = ft_strdup("");
	return(just_do_it(fd, &b, line));
}
#include <stdio.h>
#include <string.h>
int	main()
{
	int fd = open("foo.txt", O_CREAT);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}