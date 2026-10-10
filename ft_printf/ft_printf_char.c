#include "ft_printf.h"

/* Writes a single character to the specified file descriptor */
static int	ft_putchar(char c, int fd)
{
	return (write(fd, &c, 1));
}

/* Writes a null-terminated string (or "(null)") to the specified file descriptor */
static int	ft_putstr(char *s, int fd)
{
	int	i;

	if (!s)
		return (write(fd, "(null)", 6));
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}

/* Handles character and string conversion specifiers ('c', 's', '%') */
int	ft_printf_char(char specifier, va_list args, int fd)
{
	if (specifier == 'c')
		return (ft_putchar(va_arg(args, int), fd));
	else if (specifier == 's')
		return (ft_putstr(va_arg(args, char *), fd));
	else if (specifier == '%')
		return (ft_putchar('%', fd));
	return (0);
}
