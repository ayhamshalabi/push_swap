#include "push_swap.h"

/* Sums the execution counts across all individual push_swap operations */
static int	total_ops(t_ps *ps)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (i < TOTAL_OPS)
	{
		total += ps->count[i];
		i++;
	}
	return (total);
}

/* Converts the strategy enum identifier into a human-readable string */
static char	*strategy_name(t_strategy strategy)
{
	if (strategy == SIMPLE)
		return ("Simple");
	if (strategy == MEDIUM)
		return ("Medium");
	if (strategy == COMPLEX)
		return ("Complex");
	return ("Adaptive");
}

/* Outputs comprehensive benchmark statistics and operation counts to stderr */
void	bench_print(t_ps *ps)
{
	ft_printf(2, "[bench] disorder: %f%%\n", ps->disorder * 100);
	ft_printf(2, "[bench] strategy: %s / %s\n",
		strategy_name(ps->strategy), ps->strategy_chosen);
	ft_printf(2, "[bench] total_ops: %d\n", total_ops(ps));
	ft_printf(2, "[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
		ps->count[SA], ps->count[SB], ps->count[SS],
		ps->count[PA], ps->count[PB]);
	ft_printf(2, "[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		ps->count[RA], ps->count[RB], ps->count[RR],
		ps->count[RRA], ps->count[RRB], ps->count[RRR]);
}
