/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:35:33 by afretta-          #+#    #+#             */
/*   Updated: 2026/01/20 16:46:23 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_abs(int cost);
static int	total_cost(t_stack_node *b);
static int	ps_max(int cost_a, int cost_b);

void	set_cost_move(t_stack_node *stack)
{
	size_t	len;
	int		medium;

	len = stack_len(stack);
	medium = len / 2;
	while (stack)
	{
		if (stack->index <= medium)
			stack->cost = stack->index;
		else
			stack->cost = stack->index - (int)len;

		stack = stack->next;
	}
}

void	set_cheapest_node(t_stack_node *stack)
{
	t_stack_node	*lower_cost_node;
	int				cost;
	int				lower_cost;

	lower_cost_node = NULL;
	lower_cost = INT_MAX;
	while (stack)
	{
		stack->cheapest = false;
		if(stack->allowed)
		{
			cost = ps_abs(stack->cost);
			if (cost < lower_cost)
			{
				lower_cost = cost;
				lower_cost_node = stack;
			}
		}
		stack = stack->next;
	}
	lower_cost_node->cheapest = true;
}

static int	ps_abs(int cost)
{
	if(cost < 0)
		cost = -cost;
	return(cost);
}

void	set_cheapest_move(t_stack_node *b)
{
	int push_cost;
	int	lowest_cost;
	t_stack_node *cheapet_node;

	lowest_cost = INT_MAX;
	cheapet_node = NULL;
	while (b)
	{
		b->cheapest = false;
		if(b->allowed)
		{
			push_cost = total_cost(b);
			if(push_cost < lowest_cost)
			{
				cheapet_node = b;
				lowest_cost = push_cost;
			}
			b = b->next;
		}
	}
	cheapet_node->cheapest = true;	
}

static int total_cost(t_stack_node *b)
{
	int	total_cost;
	
	if((b->target_node->cost > 0 && b->cost >0) ||
		(b->target_node->cost < 0 && b->cost < 0))
		total_cost = ps_max(ps_abs(b->target_node->cost), ps_abs(b->cost));
	else
		total_cost = ps_abs(b->target_node->cost) + ps_abs(b->cost);
	return(total_cost);
}

static int	ps_max(int cost_a, int cost_b)
{
	if(cost_a > cost_b)
		return(cost_a);
	return (cost_b);
}
