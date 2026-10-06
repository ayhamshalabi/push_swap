/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhshala <ayham.shalabi@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 21:33:44 by hal-omar          #+#    #+#             */
/*   Updated: 2026/10/06 15:10:07 by ayhshala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 1. Finds the index (0 to size - 1) of the target rank in stack a */
static int	get_rank_pos(t_node *stack, int target_rank)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->rank == target_rank)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

/* 2. Rotates stack a via the shortest path to bring target_rank to the top */
static void	push_min_to_b(t_ps *ps, int target_rank)
{
	int	pos;
	int	size;

	pos = get_rank_pos(ps->a, target_rank);
	size = stack_size(ps->a);
	if (pos <= size / 2)
	{
		while (ps->a->rank != target_rank)
			op_rotate(ps, 'a');
	}
	else
	{
		while (ps->a->rank != target_rank)
			op_reverse(ps, 'a');
	}
	op_push(ps, 'b');
}

/* 3. Strategy 1: O(n^2) Selection Sort */
void	sort_simple(t_ps *ps)
{
	int	target_min;

	target_min = 0;
	while (stack_size(ps->a) > 3)
	{
		push_min_to_b(ps, target_min);
		target_min++;
	}
	sort_three(ps);
	while (ps->b)
		op_push(ps, 'a');
}