/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_in_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:13:58 by afretta-          #+#    #+#             */
/*   Updated: 2026/01/09 15:27:59 by afretta-         ###   ########.fr       */
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

void	set_b_target_node(t_stack_node *a, t_stack_node *b)
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

void	set_a_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	long			biggest_smallest;

	while (a)
	{
		current_b = b;
		biggest_smallest = LONG_MIN;
		target_node = NULL;
		while (current_b)
		{
			if (current_b->value < a->value
				&& current_b->value > biggest_smallest)
			{
				biggest_smallest = current_b->value;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (!target_node)
			a->target_node = find_highest(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

void	set_allowed_nodes(t_stack_node *a, int chunk_size)
{
	while(a)
	{
		
	}
}
//set_target_node_ab
//set_target_node_ba
