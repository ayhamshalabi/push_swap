#include "push_swap.h"

/* Increments swap operation statistics and prints sa, sb, or ss */
static void	op_print(t_ps *ps, char op)
{
	if (op == 'a')
	{
		ps->count[SA]++;
		write(1, "sa\n", 3);
	}
	else if (op == 'b')
	{
		ps->count[SB]++;
		write(1, "sb\n", 3);
	}
	else if (op == 's')
	{
		ps->count[SS]++;
		write(1, "ss\n", 3);
	}
}

/* Swaps the top two elements of a stack */
static void	swap(t_node **stack)
{
	t_node	*tmp;

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
}

/* Executes swap on stack A, stack B, or both simultaneously */
void	op_swap(t_ps *ps, char op)
{
	if (!ps)
		return ;
	if (op == 'a' && ps->a && ps->a->next)
	{
		swap(&ps->a);
		op_print(ps, op);
	}
	else if (op == 'b' && ps->b && ps->b->next)
	{
		swap(&ps->b);
		op_print(ps, op);
	}
	else if (op == 's' && ps->a && ps->a->next && ps->b && ps->b->next)
	{
		swap(&ps->a);
		swap(&ps->b);
		op_print(ps, op);
	}
}
