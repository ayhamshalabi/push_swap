#include "push_swap.h"

/* Program entry point: initializes state, parses args, ranks stack, and runs adaptive sort */
int	main(int argc, char **argv)
{
	t_ps	ps;

	if (argc < 2)
		return (0);
	ft_bzero(&ps, sizeof(t_ps));
	parse_args(&ps, argc, argv);
	initialize_ranks(ps.a);
	ps.disorder = compute_disorder(ps.a);
	sort_adaptive(&ps);
	if (ps.bench)
		bench_print(&ps);
	free_stack(&ps.a);
	free_stack(&ps.b);
	return (0);
}
