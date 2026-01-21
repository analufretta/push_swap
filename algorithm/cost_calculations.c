/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:35:33 by afretta-          #+#    #+#             */
/*   Updated: 2026/01/21 17:11:24 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (stack->allowed == true)
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

void	set_cheapest_move(t_stack_node *b)
{
	int				push_cost;
	int				lowest_cost;
	t_stack_node	*cheapet_node;

	lowest_cost = INT_MAX;
	cheapet_node = NULL;
	while (b)
	{
		b->cheapest = false;
		push_cost = total_cost(b);
		if (push_cost < lowest_cost)
		{
			cheapet_node = b;
			lowest_cost = push_cost;
		}
		b = b->next;
	}
	cheapet_node->cheapest = true;
}
