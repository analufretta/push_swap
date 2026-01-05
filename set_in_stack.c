/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_in_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:13:58 by afretta-          #+#    #+#             */
/*   Updated: 2026/01/05 15:06:55 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	calc_total_cost(int cost_b, int cost_a);

void	set_current_position(t_stack_node *stack)
{
	size_t	index;

	index = 1;
	if (!stack)
		return ;
	while (stack)
	{
		stack->index = stack->index + index;
		index++;
		stack = stack->next;
	}
}

void	set_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			smallest_biggest;

	while (b)
	{
		current_a = a;
		smallest_biggest = LONG_MAX;
		target_node = NULL;
		while (current_a)
		{
			if (current_a->value > b->value
				&& current_a->value < smallest_biggest)
			{
				smallest_biggest = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (!target_node)
			b->target_node = find_lowest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	set_cost_move(t_stack_node *a, t_stack_node *b)
{
	size_t	len_a;
	size_t	len_b;
	size_t	medium_a;
	size_t	medium_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	medium_a = len_a / 2;
	medium_b = len_b / 2;
	while (b)
	{
		if (b->index <= medium_b)
			b->cost = b->index;
		else
			b->cost = b->index - (int)len_b;
		if (b->target_node->index <= medium_a)
			b->target_node->cost = b->target_node->index;
		else
			b->target_node->cost = b->target_node->index - (int)len_a;
		b = b->next;
	}
}

void	set_cheapest_move(t_stack_node *b)
{
	t_stack_node	*lower_cost_node;
	int				total_cost;
	int				lower_cost;

	lower_cost_node = NULL;
	lower_cost = INT_MAX;
	while (b)
	{
		b->cheapest = false;
		total_cost = calc_total_cost(b->cost, b->target_node->cost);
		if (total_cost < lower_cost)
		{
			lower_cost = total_cost;
			lower_cost_node = b;
		}
		b = b->next;
	}
	lower_cost_node->cheapest = true;
}

static int	calc_total_cost(int cost_b, int cost_a)
{
	if (cost_a < 0)
		cost_a = -cost_a;
	if (cost_b < 0)
		cost_b = -cost_b;
	return (cost_a + cost_b);
}
