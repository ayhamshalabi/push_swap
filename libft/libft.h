#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isdigit(int c);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(const char *s1);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);


#endif
