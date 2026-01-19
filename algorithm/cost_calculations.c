/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:35:33 by afretta-          #+#    #+#             */
/*   Updated: 2026/01/19 16:45:07 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_max(int x, int y);
static int	calc_total_cost(int cost_b, int cost_a);
static int	ps_abs(int cost);

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

void	set_cheapest_move(t_stack_node *stack)
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

void	calc_target_move(t_stack_node *a, t_stack_node *b, t_stack_node *target)
{
	size_t len_b;
	size_t medium_b;

	len_b = stack_len(b);
	medium_b = len_b / 2;

	if(target->index <= medium_b)
		target->cost = target->index;
	else
		target->cost = target->index - (int)len_b;
}

