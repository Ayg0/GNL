/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ted-dafi <ted-dafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:40:24 by ted-dafi          #+#    #+#             */
/*   Updated: 2021/11/23 00:03:09 by ted-dafi         ###   ########.fr       */
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
	int	re;
	re = read(fd, *b, BUFFER_SIZE);
	
}
char *get_next_line(int fd)
{
	static char	*b;
	char		*line;
	if(!b)
	{
		b = (char *)malloc(sizeof(char) * (BUFFER_SIZE));
		if (!b)
			return (NULL);
	}
	line = ft_strdup("");
	return(just_do_it(fd, &b, line));
}
