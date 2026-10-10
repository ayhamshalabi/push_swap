#include "push_swap.h"

/* Iterates CLI arguments, routes flags or number tokens, and validates that stack A is not empty */
void	parse_args(t_ps *ps, int num, char **arg)
{
	int	i;
	int	allow_flags;

	i = 1;
	allow_flags = 2;
	ps->strategy = ADAPTIVE;
	while (i < num)
	{
		if (arg[i][0] == '-' && arg[i][1] == '-')
			parse_flags(arg[i], ps, &allow_flags);
		else
		{
			allow_flags = 0;
			parse_number(arg[i], ps);
		}
		i++;
	}
	if (!ps->a)
		error(ps);
}
