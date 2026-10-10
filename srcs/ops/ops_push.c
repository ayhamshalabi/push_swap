#include "push_swap.h"

/* Increments push operation statistics and prints pa or pb */
static void	op_print(t_ps *ps, char op)
{
	if (op == 'a')
	{
		ps->count[PA]++;
		write(1, "pa\n", 3);
	}
	else if (op == 'b')
	{
		ps->count[PB]++;
		write(1, "pb\n", 3);
	}
}

/* Moves the top element from the source stack to the top of the destination stack */
static void	push(t_node **from_stack, t_node **to_stack)
{
	t_node	*tmp;

	tmp = *from_stack;
	*from_stack = (*from_stack)->next;
	tmp->next = *to_stack;
	*to_stack = tmp;
}

/* Executes push onto stack A (pa) or stack B (pb) */
void	op_push(t_ps *ps, char op)
{
	if (op == 'a' && ps->b)
	{
		push(&ps->b, &ps->a);
		op_print(ps, op);
	}
	else if (op == 'b' && ps->a)
	{
		push(&ps->a, &ps->b);
		op_print(ps, op);
	}
}
