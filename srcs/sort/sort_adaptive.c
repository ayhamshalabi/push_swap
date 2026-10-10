#include "push_swap.h"

/* Selects the sorting strategy based on manual CLI flags or the stack disorder ratio */
static t_strategy	pick_sort(t_ps *ps)
{
	if (ps->strategy != ADAPTIVE)
		return (ps->strategy);
	if (ps->disorder < 0.2)
		return (SIMPLE);
	if (ps->disorder < 0.5)
		return (MEDIUM);
	return (COMPLEX);
}

/* Records strategy name, skips if already sorted, and triggers the selected sorting algorithm */
void	sort_adaptive(t_ps *ps)
{
	t_strategy	sort;

	sort = pick_sort(ps);
	if (sort == SIMPLE)
		ps->strategy_chosen = "O(n²)";
	else if (sort == MEDIUM)
		ps->strategy_chosen = "O(n√n)";
	else
		ps->strategy_chosen = "O(n log n)";
	if (ps->disorder == 0.0)
		return ;
	if (sort == SIMPLE)
		sort_simple(ps);
	else if (sort == MEDIUM)
		sort_medium(ps);
	else
		sort_complex(ps);
}
