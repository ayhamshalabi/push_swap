#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
} t_list;

typedef struct s_ps
{
    t_list      *a;
    t_list      *b;
    int         bench;
    double      disorder;
    char        *strategy_str;
    int         total_ops;
    int         cnt_sa;
    int         cnt_sb;
    int         cnt_ss;
    int         cnt_pa;
    int         cnt_pb;
    int         cnt_ra;
    int         cnt_rb;
    int         cnt_rr;
    int         cnt_rra;
    int         cnt_rrb;
    int         cnt_rrr;
}   t_ps;