/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@student.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 20:56:10 by hal-omar          #+#    #+#             */
/*   Updated: 2026/10/02 22:09:31 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"
/* Checks that str is not empty and contains only digits with an optional sign */
int	is_valid_syntax(char *str)
{
	int	i;
	i = 0;
	if (!str || !str[0])
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
/* Converts string to long and flags *err = 1 if it overflows 32-bit int */
long	parse_atol(const char *str, int *err)
{
	int		sign;
	long	res;
	int		i;
	sign = 1;
	res = 0;
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
/* Returns 1 if val already exists in stack, 0 otherwise */
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