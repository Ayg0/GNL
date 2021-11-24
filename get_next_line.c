/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ted-dafi <ted-dafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:40:24 by ted-dafi          #+#    #+#             */
/*   Updated: 2021/11/24 22:10:53 by ted-dafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*ft_substr(char *fr, char *start, size_t len)
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

	line = ft_strjoin(line, *b);
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
		f = ft_substr(line, line, ft_strchr(line, '\n') - line + 1);
		ft_strlcpy(*b, i + 1,  ft_strchr(*b, '\0') - i);
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
	char		*m;
	char		*n;
	char		*f;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!line)
		return  (NULL);	
	re = read(fd, line, BUFFER_SIZE);
	line = ft_strjoin(b, line);
	while (re || *b)
	{
		if (b)
			m = ft_strchr(b, '\n');
		if(m)
		{
			f = ft_substr(line, line, ft_strchr(line, '\n') - line + 1);
			b = ft_substr(b, b, ft_strchr(line, '\0') - ft_strchr(line, '\n') + 1);
		}
		else
		{
			re = read(fd, line, BUFFER_SIZE);
			line = ft_strjoin(b, line);
		}
	}
	return (f);
}
#include <stdio.h>
#include <string.h>
int	main()
{
	int fd = open("foo.txt", O_CREAT);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}