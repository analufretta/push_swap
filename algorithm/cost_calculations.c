/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:35:33 by afretta-          #+#    #+#             */
/*   Updated: 2026/01/09 14:38:05 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_max(int x, int y);
static int	calc_total_cost(int cost_b, int cost_a);

void	set_cost_move(t_stack_node *src, t_stack_node *dst)
{
	size_t	len_src;
	size_t	len_dst;
	int		medium_src;
	int		medium_dst;

	len_src = stack_len(src);
	len_dst = stack_len(dst);
	medium_src = len_src / 2;
	medium_dst = len_dst / 2;
	while (src)
	{
		if (src->index <= medium_src)
			src->cost = src->index;
		else
			src->cost = src->index - (int)len_src;
		if (src->target_node->index <= medium_dst)
			src->target_node->cost = src->target_node->index;
		else
			src->target_node->cost = src->target_node->index - (int)len_dst;
		src = src->next;
	}
}

void	set_cheapest_move(t_stack_node *stack)
{
	t_stack_node	*lower_cost_node;
	int				total_cost;
	int				lower_cost;

	lower_cost_node = NULL;
	lower_cost = INT_MAX;
	while (stack)
	{
		stack->cheapest = false;
		total_cost = calc_total_cost(stack->cost, stack->target_node->cost);
		if (total_cost < lower_cost)
		{
			lower_cost = total_cost;
			lower_cost_node = stack;
		}
		stack = stack->next;
	}
	lower_cost_node->cheapest = true;
}

static int	calc_total_cost(int cost_node, int cost_target)
{
	int	total_cost;

	if (cost_node < 0 && cost_target < 0)
	{
		cost_node = -cost_node;
		cost_target = -cost_target;
		total_cost = ps_max(cost_node, cost_target);
	}
	else if (cost_node >= 0 && cost_target >= 0)
		total_cost = ps_max(cost_node, cost_target);
	else
	{
		if (cost_node < 0)
			cost_node = -cost_node;
		if (cost_target < 0)
			cost_target = -cost_target;
		total_cost = cost_node + cost_target;
	}
	return (total_cost);
}

static int	ps_max(int x, int y)
{
	int	max;

	if (x >= y)
		max = x;
	else
		max = y;
	return (max);
}

//calc_target_move();
