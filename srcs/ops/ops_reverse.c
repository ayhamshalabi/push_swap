#include "push_swap.h"

/* Increments reverse rotate operation statistics and prints rra, rrb, or rrr */
static void	op_print(t_ps *ps, char op)
{
	if (op == 'a')
	{
		ps->count[RRA]++;
		write(1, "rra\n", 4);
	}
	else if (op == 'b')
	{
		ps->count[RRB]++;
		write(1, "rrb\n", 4);
	}
	else if (op == 'r')
	{
		ps->count[RRR]++;
		write(1, "rrr\n", 4);
	}
}

/* Shifts down all elements of a stack by 1 so the last element becomes the first */
static void	reverse(t_node **stack)
{
	t_node	*prev;
	t_node	*last;

	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

/* Executes reverse rotate on stack A, stack B, or both simultaneously */
void	op_reverse(t_ps *ps, char op)
{
	if (!ps)
		return ;
	if (op == 'a' && ps->a && ps->a->next)
	{
		reverse(&ps->a);
		op_print(ps, op);
	}
	else if (op == 'b' && ps->b && ps->b->next)
	{
		reverse(&ps->b);
		op_print(ps, op);
	}
	else if (op == 'r' && ps->a && ps->a->next && ps->b && ps->b->next)
	{
		reverse(&ps->a);
		reverse(&ps->b);
		op_print(ps, op);
	}
}
