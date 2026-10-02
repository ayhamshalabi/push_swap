#include <unistd.h>
#include <stdlib.h>

typedef enum e_op
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	TOTAL_OPS
}	t_op;

typedef enum e_strategy
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}	t_strategy;

typedef struct s_node
{
	int				value;
	int				rank;
	struct s_node	*next;
}	t_node;

typedef struct s_ps
{
    t_node      *a;
    t_node      *b;
    int         bench;
    double      disorder;
	t_strategy	strategy;
    int         count[TOTAL_OPS];
}	t_ps;