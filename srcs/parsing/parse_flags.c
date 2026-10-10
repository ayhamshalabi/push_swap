#include "push_swap.h"

/* Parses and validates optional CLI flags (--bench, --simple, --medium, --complex, --adaptive) */
void	parse_flags(char *flag, t_ps *ps, int *allowed_flags)
{
	flag += 2;
	if (*allowed_flags == 0)
		error(ps);
	else if (!ft_strncmp(flag, "bench", 6) && !ps->bench)
		ps->bench = 1;
	else if (ps->strategy_set)
		error(ps);
	else if (!ft_strncmp(flag, "adaptive", 9) && ++ps->strategy_set)
		ps->strategy = ADAPTIVE;
	else if (!ft_strncmp(flag, "simple", 7) && ++ps->strategy_set)
		ps->strategy = SIMPLE;
	else if (!ft_strncmp(flag, "medium", 7) && ++ps->strategy_set)
		ps->strategy = MEDIUM;
	else if (!ft_strncmp(flag, "complex", 8) && ++ps->strategy_set)
		ps->strategy = COMPLEX;
	else
		error(ps);
	(*allowed_flags)--;
}
