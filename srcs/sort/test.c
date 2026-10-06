#include "push_swap.h"

static int	grt_rank_pos(t_node *stack, int target)
{
	int	pos;

	pos= 0;
	while (stack)
	{
		if (stack->rank == target)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

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

void	sort_simple(t_ps *ps)
{
	int	target;

	target = 0;
	while (stack_stack(ps->a) > 3)
	{
		push_min_to_b(ps, target);
		target++;
	}
	sort_three(ps->a);
	while (ps->b)
		op_push(ps, 'a');
}