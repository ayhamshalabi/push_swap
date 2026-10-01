#include "push_swap.h"

static void	op_print(t_ps *ps, char op)
{	
	if (++ps->count[PA] && ++ps->count[TOTAL_OPS])
		write(1, "pa\n", 3);
	if (++ps->count[PB] && ++ps->count[TOTAL_OPS])
		write(1, "pb\n", 3);
}

void	op_push(t_ps *ps, char op)
{
	t_node	*tmp;

	if (op == 'a' && ps->b)
	{
		tmp = ps->b;
		ps->b = ps->b->next;
		tmp->next = ps->a;
		ps->a = tmp;
		op_print(ps, op);
	}
	else if (op == 'b' && ps->a)
	{
		tmp = ps->a;
		ps->a = ps->a->next;
		tmp->next = ps->b;
		ps->b = tmp;
		op_print(ps, op);
	}
}
