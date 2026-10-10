#include "ft_printf.h"

/* Writes a single character to the target file descriptor */
static int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

/* Writes a long integer to the target file descriptor */
static int	ft_putnbr_long(long n, int fd)
{
	char	c;
	int		len;

	len = 0;
	if (n < 0)
	{
		len += write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		len += ft_putnbr_long(n / 10, fd);
	c = (n % 10) + '0';
	len += write(fd, &c, 1);
	return (len);
}

/* Formats and prints a double-precision floating-point number with 2 decimal places */
int	ft_printf_double(double nb, int fd)
{
	long	int_part;
	int		len;
	int		i;

	len = 0;
	if (nb < 0)
	{
		len += ft_putchar_fd('-', fd);
		nb = -nb;
	}
	nb += 0.005;
	int_part = (long)nb;
	len += ft_putnbr_long(int_part, fd);
	len += ft_putchar_fd('.', fd);
	nb = nb - int_part;
	i = 2;
	while (i--)
	{
		nb = nb * 10;
		len += ft_putchar_fd((int)nb + '0', fd);
		nb = nb - (int)nb;
	}
	return (len);
}