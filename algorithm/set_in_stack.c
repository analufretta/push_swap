/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_in_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:13:58 by afretta-          #+#    #+#             */
/*   Updated: 2026/01/21 17:46:23 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	set_current_position(t_stack_node *stack)
{
	size_t	index;

	index = 0;
	if (!stack)
		return ;
	while (stack)
	{
		stack->index = index;
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
