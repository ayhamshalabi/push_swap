/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@student.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 21:33:44 by hal-omar          #+#    #+#             */
/*   Updated: 2026/10/03 21:33:45 by hal-omar         ###   ########.fr       */
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








#include "push_swap.h"

/* Calculates the number of operations to bring a position to the top */
static int	get_cost(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (size - pos);
}

static void	bring_to_top_a(t_ps *ps, int target_rank)
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
}

static void	push_dual_min(t_ps *ps, int min1, int min2)
{
	int	cost1;
	int	cost2;
	int	size;

	size = stack_size(ps->a);
	cost1 = get_cost(get_rank_pos(ps->a, min1), size);
	cost2 = get_cost(get_rank_pos(ps->a, min2), size);
	if (cost1 <= cost2)
	{
		bring_to_top_a(ps, min1);
		op_push(ps, 'b');
		bring_to_top_a(ps, min2);
		op_push(ps, 'b');
	}
	else
	{
		bring_to_top_a(ps, min2);
		op_push(ps, 'b');
		bring_to_top_a(ps, min1);
		op_push(ps, 'b');
	}
	if (ps->b && ps->b->next && ps->b->rank < ps->b->next->rank)
		op_swap(ps, 'b');
}

void	sort_simple_dual(t_ps *ps)
{
	int	cur_min;

	cur_min = 0;
	while (stack_size(ps->a) > 4)
	{
		push_dual_min(ps, cur_min, cur_min + 1);
		cur_min += 2;
	}
	while (stack_size(ps->a) > 3)
	{
		bring_to_top_a(ps, cur_min);
		op_push(ps, 'b');
		cur_min++;
	}
	sort_three(ps);
	while (ps->b)
		op_push(ps, 'a');
}