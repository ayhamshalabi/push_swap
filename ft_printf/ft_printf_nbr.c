#include "ft_printf.h"

/* Writes a signed 32-bit integer to the specified file descriptor */
static int	ft_putnbr(int n, int fd)
{
	char	c;
	long	nb;
	int		len;

	nb = n;
	len = 0;
	if (nb < 0)
	{
		len += write(fd, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		len += ft_putnbr(nb / 10, fd);
	c = (nb % 10) + '0';
	len += write(fd, &c, 1);
	return (len);
}

/* Writes an unsigned 32-bit integer to the specified file descriptor */
static int	ft_putunsigned(unsigned int n, int fd)
{
	char	c;
	int		len;

	len = 0;
	if (n >= 10)
		len += ft_putunsigned(n / 10, fd);
	c = (n % 10) + '0';
	len += write(fd, &c, 1);
	return (len);
}

/* Handles integer conversion specifiers ('d', 'i', 'u') */
int	ft_printf_nbr(char specifier, va_list args, int fd)
{
	if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr(va_arg(args, int), fd));
	if (specifier == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int), fd));
	return (0);
}
