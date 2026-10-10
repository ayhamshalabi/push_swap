#include "push_swap.h"

/* Finds the 0-indexed position of a target rank in the stack */
static int	get_rank_pos(t_node *stack, int target)
{
	int	pos;

	pos = 0;
	while (stack && stack->rank != target)
	{
		pos++;
		stack = stack->next;
	}
	return (pos);
}

/* Rotates stack A via the shortest path to bring the target rank to top, then pushes to B */
static void	push_min_to_b(t_ps *ps, int target)
{
	int	pos;
	int	size;

	pos = get_rank_pos(ps->a, target);
	size = stack_size(ps->a);
	if (pos <= size / 2)
	{
		while (ps->a->rank != target)
			op_rotate(ps, 'a');
	}
	else
	{
		while (ps->a->rank != target)
			op_reverse(ps, 'a');
	}
	op_push(ps, 'b');
}

/* Executes O(n^2) selection sort by repeatedly pushing minimum ranks to stack B */
void	sort_simple(t_ps *ps)
{
	int	target;

	target = 0;
	while (stack_size(ps->a) > 2)
	{
		push_min_to_b(ps, target);
		target++;
	}
	if (ps->a->rank > ps->a->next->rank)
		op_swap(ps, 'a');
	while (ps->b)
		op_push(ps, 'a');
}
