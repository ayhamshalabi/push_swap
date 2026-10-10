#include "libft.h"

/* Tests whether a character is an ASCII decimal digit ('0' through '9') */
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
