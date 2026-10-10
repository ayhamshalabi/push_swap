#include "push_swap.h"

/* Allocates and initializes a new stack node with the given integer value */
t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->rank = 0;
	return (node);
}

/* Appends a node to the bottom (tail) of the stack */
void	stack_add_bottom(t_node **stack, t_node *node)
{
	t_node	*tmp;

	if (!stack || !node)
		return ;
	if (!*stack)
	{
		*stack = node;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

/* Deallocates every node in the stack and sets the stack head pointer to NULL */
void	free_stack(t_node **stack)
{
	t_node	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

/* Counts and returns the total number of nodes in the stack */
int	stack_size(t_node *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

/* Normalizes node values into 0-indexed ranks based on relative order */
void	initialize_ranks(t_node *stack)
{
	t_node	*curr;
	t_node	*compare;
	int		count;

	curr = stack;
	while (curr)
	{
		count = 0;
		compare = stack;
		while (compare)
		{
			if (compare->value < curr->value)
				count++;
			compare = compare->next;
		}
		curr->rank = count;
		curr = curr->next;
	}
}
