#include "push_swap.h"

/* Computes the ratio of inverted pairs over total pairs (disorder score between 0.0 and 1.0) */
double	compute_disorder(t_node *stack)
{
	t_node	*i;
	t_node	*j;
	double	mistakes;
	double	total_pairs;
	long	size;

	size = stack_size(stack);
	if (size < 2)
		return (0.0);
	mistakes = 0;
	i = stack;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	total_pairs = (size * (size - 1)) / 2;
	return (mistakes / total_pairs);
}
