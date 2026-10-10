#include "push_swap.h"

/* Frees a null-terminated array of strings allocated by ft_split */
static void	free_split(char **res)
{
	int	i;

	if (!res)
		return ;
	i = 0;
	while (res[i])
		free(res[i++]);
	free(res);
}

/* Validates, converts, and checks duplicate for a token before appending to stack A */
static void	add_number(char *str, char **res, t_ps *ps)
{
	int		err;
	long	num;
	t_node	*node;

	if (!is_valid_syntax(str))
	{
		free_split(res);
		error(ps);
	}
	err = 0;
	num = parse_atol(str, &err);
	if (err || is_duplicate(ps->a, (int)num))
	{
		free_split(res);
		error(ps);
	}
	node = new_node((int)num);
	if (!node)
	{
		free_split(res);
		error(ps);
	}
	stack_add_bottom(&ps->a, node);
}

/* Splits an argument string by spaces and passes each numeric token to add_number */
void	parse_number(char *arg, t_ps *ps)
{
	char	**res;
	int		i;

	res = ft_split(arg, ' ');
	if (!res || !res[0])
	{
		free_split(res);
		error(ps);
	}
	i = 0;
	while (res[i])
		add_number(res[i++], res, ps);
	free_split(res);
}
