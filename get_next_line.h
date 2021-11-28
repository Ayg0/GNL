#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
char	*ft_strjoin(char **s1, char *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int		ft_newlchr(const char *s);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*my_free(char **buff);
#endif

