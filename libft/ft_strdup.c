#include "libft.h"

/* Allocates sufficient memory for a copy of the string s1 and returns it */
char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*dst;
	char	*dst_start;

	len = ft_strlen(s1);
	dst = malloc(len + 1);
	if (!dst)
		return (NULL);
	dst_start = dst;
	while (*s1)
		*dst++ = *s1++;
	*dst = '\0';
	return (dst_start);
}
