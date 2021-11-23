/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ted-dafi <ted-dafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:32:55 by ted-dafi          #+#    #+#             */
/*   Updated: 2021/11/23 23:55:22 by ted-dafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	size_t		i;
	char		*bo;

	i = ft_strlen(s1);
	bo = (char *)malloc((i + 1) * sizeof(char));
	if (bo == 0)
		return (0);
	i = 0;
	while (s1[i])
	{
		bo[i] = s1[i];
		i++;
	}
	bo[i] = '\0';
	return (bo);
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

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char		*s3;
	size_t		j;
	size_t		k;

	if(!s2)
		return (NULL);
	j = ft_strlen(s1);
	k = ft_strlen(s2);
	s3 = (char *)malloc(j + k + 1);
	if (!s3)
		return (NULL);
	ft_strlcpy(s3, s1, j + 1);
	free(s1);
	ft_strlcpy(s3 + j, s2, k + 1);
	return (s3);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}