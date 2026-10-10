#include "ft_printf.h"

/* Dispatches argument formatting based on conversion specifier to the specified fd */
static int	ft_format(char specifier, va_list args, int fd)
{
	if (specifier == 'c' || specifier == 's' || specifier == '%')
		return (ft_printf_char(specifier, args, fd));
	if (specifier == 'd' || specifier == 'i' || specifier == 'u')
		return (ft_printf_nbr(specifier, args, fd));
	if (specifier == 'x' || specifier == 'X' || specifier == 'p')
		return (ft_printf_hex(specifier, args, fd));
	if (specifier == 'f')
		return (ft_printf_double(va_arg(args, double), fd));
	write(fd, "%", 1);
	write(fd, &specifier, 1);
	return (2);
}

/* Formatted output conversion writing to any specified file descriptor */
int	ft_printf(int fd, const char *format, ...)
{
	va_list	args;
	int		len;
	int		i;

	if (!format)
		return (-1);
	va_start(args, format);
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			len += ft_format(format[++i], args, fd);
		else if (format[i] != '%')
			len += write(fd, &format[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
