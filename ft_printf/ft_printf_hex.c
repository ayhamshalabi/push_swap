#include "ft_printf.h"

/* Writes an unsigned number in lowercase ('x') or uppercase ('X') hexadecimal */
static int	ft_puthex(char specifier, unsigned long n, int fd)
{
	char	*base;
	int		len;

	if (specifier == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	len = 0;
	if (n >= 16)
		len += ft_puthex(specifier, n / 16, fd);
	len += write(fd, &base[n % 16], 1);
	return (len);
}

/* Formats and prints a memory address pointer in hexadecimal prefixed with 0x */
static int	ft_putptr(void *ptr, int fd)
{
	unsigned long	addr;
	int				len;

	if (!ptr)
		return (write(fd, "(nil)", 5));
	len = write(fd, "0x", 2);
	addr = (unsigned long)ptr;
	len += ft_puthex('x', addr, fd);
	return (len);
}

/* Handles hexadecimal and pointer conversion specifiers ('x', 'X', 'p') */
int	ft_printf_hex(char specifier, va_list args, int fd)
{
	if (specifier == 'x' || specifier == 'X')
		return (ft_puthex(specifier, va_arg(args, unsigned int), fd));
	if (specifier == 'p')
		return (ft_putptr(va_arg(args, void *), fd));
	return (0);
}
