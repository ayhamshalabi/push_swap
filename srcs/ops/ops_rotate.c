#include "push_swap.h"

/* Increments rotate operation statistics and prints ra, rb, or rr */
static void	op_print(t_ps *ps, char op)
{
	if (op == 'a')
	{
		ps->count[RA]++;
		write(1, "ra\n", 3);
	}
	else if (op == 'b')
	{
		ps->count[RB]++;
		write(1, "rb\n", 3);
	}
	else if (op == 'r')
	{
		ps->count[RR]++;
		write(1, "rr\n", 3);
	}
}

/* Shifts up all elements of a stack by 1 so the top element becomes the last */
static void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = (*stack)->next;
	last->next = first;
	first->next = NULL;
}

/* Executes rotate on stack A, stack B, or both simultaneously */
void	op_rotate(t_ps *ps, char op)
{
	if (!ps)
		return ;
	if (op == 'a' && ps->a && ps->a->next)
	{
		rotate(&ps->a);
		op_print(ps, op);
	}
	else if (op == 'b' && ps->b && ps->b->next)
	{
		rotate(&ps->b);
		op_print(ps, op);
	}
	else if (op == 'r' && ps->a && ps->a->next && ps->b && ps->b->next)
	{
		rotate(&ps->a);
		rotate(&ps->b);
		op_print(ps, op);
	}
}
