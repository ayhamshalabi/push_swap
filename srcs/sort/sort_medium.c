#include "push_swap.h"

/* Computes integer square root of n using linear search */
static int	int_sqrt(int n)
{
	int	sq_rt;

	sq_rt = 0;
	while ((sq_rt + 1) * (sq_rt + 1) <= n)
		sq_rt++;
	return (sq_rt);
}

/* Finds the 0-indexed position of the node with the highest rank in the stack */
static int	max_pos(t_node *stack)
{
	int	pos;
	int	best_pos;
	int	max;

	pos = 0;
	best_pos = 0;
	max = stack->rank;
	while (stack)
	{
		if (stack->rank > max)
		{
			max = stack->rank;
			best_pos = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (best_pos);
}

/* Pushes elements into stack B in an hourglass layout using a sliding window */
static void	push_chunks(t_ps *ps, int chunk)
{
	int	pushed;

	pushed = 0;
	while (ps->a)
	{
		if (ps->a->rank <= pushed)
		{
			op_push(ps, 'b');
			if (ps->b->next)
				op_rotate(ps, 'b');
			pushed++;
		}
		else if (ps->a->rank <= pushed + chunk)
		{
			op_push(ps, 'b');
			pushed++;
		}
		else
			op_rotate(ps, 'a');
	}
}

/* Extracts maximum ranks from stack B back into stack A via the shortest rotation path */
static void	pull_back(t_ps *ps, int size_b)
{
	int	pos;

	while (size_b > 0)
	{
		pos = max_pos(ps->b);
		if (pos <= size_b / 2)
		{
			while (pos-- > 0)
				op_rotate(ps, 'b');
		}
		else
		{
			while (pos++ < size_b)
				op_reverse(ps, 'b');
		}
		op_push(ps, 'a');
		size_b--;
	}
}

/* Orchestrates O(n√n) chunk/butterfly sort using dynamic window scaling */
void	sort_medium(t_ps *ps)
{
	int	size;
	int	chunk;

	size = stack_size(ps->a);
	chunk = int_sqrt(size) * 1.4;
	push_chunks(ps, chunk);
	pull_back(ps, size);
}
