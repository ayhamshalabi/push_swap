#include "libft.h"

/* Fills the first n bytes of the memory area pointed to by s with zeros */
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
		*ptr++ = 0;
}
