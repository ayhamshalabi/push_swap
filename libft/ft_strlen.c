#include "libft.h"

/* Computes and returns the length of string s excluding the terminating NUL byte */
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}
