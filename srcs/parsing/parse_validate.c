#include "push_swap.h"

/* Checks if a string contains only an optional sign followed by digits */
int	is_valid_syntax(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/* Checks if an integer value already exists in the stack */
int	is_duplicate(t_node *stack, int val)
{
	while (stack)
	{
		if (stack->value == val)
			return (1);
		stack = stack->next;
	}
	return (0);
}

/* Converts a string to long and flags an error on 32-bit integer overflow */
long	parse_atol(char *str, int *err)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		res = res * 10 + (str[i] - '0');
		if ((sign == 1 && res > 2147483647L)
			|| (sign == -1 && res > 2147483648L))
		{
			*err = 1;
			return (0);
		}
		i++;
	}
	return (res * sign);
}
