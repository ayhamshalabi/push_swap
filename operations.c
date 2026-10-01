#include "push_swap.h"
 
void	op_swap(t_ps *ps, char op)
{
	t_list	*tmp;
	int		s;

	s = 0;
	if ((op == 'a' || op == 's') && ps->a && ps->a->next && ++s)
	{
		tmp = ps->a->next;
		ps->a->next = tmp->next;
		tmp->next = ps->a;
		ps->a = tmp;
		if (op == 'a' && ++ps->cnt_sa && ++ps->total_ops)
			write(1, "sa\n", 3);
	}
	if ((op == 'b' || op == 's') && ps->b && ps->b->next && ++s)
	{
		tmp = ps->b->next;
		ps->b->next = tmp->next;
		tmp->next = ps->b;
		ps->b = tmp;
		if (op == 'b' && ++ps->cnt_sb && ++ps->total_ops)
			write(1, "sb\n", 3);
	}
	if (op == 's' && s && ++ps->cnt_ss && ++ps->total_ops)
		write(1, "ss\n", 3);
}

void	op_push(t_ps *ps, char op)
{
	t_list	*tmp;

	if (op == 'a' && ps->b)
	{
		tmp = ps->b;
		ps->b = ps->b->next;
		tmp->next = ps->a;
		ps->a = tmp;
		if (++ps->cnt_pa && ++ps->total_ops)
			write(1, "pa\n", 3);
	}
	else if (op == 'b' && ps->a)
	{
		tmp = ps->a;
		ps->a = ps->a->next;
		tmp->next = ps->b;
		ps->b = tmp;
		if (++ps->cnt_pb && ++ps->total_ops)
			write(1, "pb\n", 3);
	}
}

void	op_rotate(t_ps *ps, char op)
{
	t_list	**s;
	t_list	*last;
	int		r;

	r = 0;
	s = &ps->a;
	while (r++ < 2)
	{
		if ((op == 'r' || op == 'a' + r - 1) && *s && (*s)->next)
		{
			last = *s;
			while (last->next)
				last = last->next;
			last->next = *s;
			*s = (*s)->next;
			last->next->next = NULL;
			if (op == 'a' && ++ps->cnt_ra && ++ps->total_ops)
				write(1, "ra\n", 3);
			if (op == 'b' && ++ps->cnt_rb && ++ps->total_ops)
				write(1, "rb\n", 3);
		}
		s = &ps->b;
	}
	if (op == 'r' && (ps->a || ps->b) && ++ps->cnt_rr && ++ps->total_ops)
		write(1, "rr\n", 3);
}