/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 11:31:37 by afretta-          #+#    #+#             */
/*   Updated: 2026/01/02 18:15:59 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stack_node	*find_highest(t_stack_node *stack)
{
	t_stack_node	*highest_node;
	int				highest;

	if (!stack)
		return (NULL);
	highest = stack->value;
	highest_node = stack;
	while (stack)
	{
		if (stack->value > highest)
		{
			highest = stack->value;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

t_stack_node	*find_lowest(t_stack_node *stack)
{
	t_stack_node	*lowest_node;
	int				lowest;

	if (!stack)
		return (NULL);
	lowest = stack->value;
	lowest_node = stack;
	while (stack)
	{
		if (stack->value < lowest)
		{
			lowest = stack->value;
			lowest_node = stack;
		}
		stack = stack->next;
	}
	return (lowest_node);
}

void	set_current_position(t_stack_node *stack)
{
	size_t index;

	index = 1;
	if(!stack)
		return ;
	while (stack)
	{
		stack->index = stack->index + index;
		index ++;
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
			if (current_a->value > b->value &&
				current_a->value < smallest_biggest)
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

void set_cost_move(t_stack_node*a, t_stack_node *b) // todo
