/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ted-dafi <ted-dafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:32:55 by ted-dafi          #+#    #+#             */
/*   Updated: 2021/11/27 00:00:25 by ted-dafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*b;
	int		i;

	i = count * size;
	b = malloc(i);
	if (b == 0)
		return (0);
	while(i)
		((char *)b)[i--] = 0;
	return (b);
}

char	*ft_substr(char const *s, size_t len)
{
	char	*p;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	p = (char *)ft_calloc((len + 1), sizeof(char));
	if (!p)
		return (NULL);
	while (*s && len)
	{
		p[i] = *s;
		i++;
		s++;
		len--;
	}
	return (p);
}

char	*ft_strdup(const char *s1)
{
	size_t		i;
	char		*bo;

	i = ft_strlen(s1);
	bo = (char *)ft_calloc(i + 1, sizeof(char));
	if (bo == 0)
		return (0);
	i = 0;
	while (s1[i])
	{
		bo[i] = s1[i];
		i++;
	}
	return (bo);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*s3;
	size_t		i;
	size_t		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j  =0;
	s3 = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!s3)
		return (NULL);
	while(s1[i])
		s3[j++] = s1[i++];
	i = 0;
	while(s2[i])
		s3[j++] = s2[i++];
	return (s3);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char )c)
			return ((char *)s);
		s++;
	}
	if ((char )c == '\0')
		return ((char *)s);
	return (0);
}