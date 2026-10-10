#include "push_swap.h"

/* Frees both stacks, writes "Error\n" to stderr, and terminates the program with failure */
void	error(t_ps *ps)
{
	if (ps)
	{
		free_stack(&ps->a);
		free_stack(&ps->b);
	}
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
