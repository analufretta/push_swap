/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_in_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:13:58 by afretta-          #+#    #+#             */
/*   Updated: 2026/01/19 16:29:49 by afretta-         ###   ########.fr       */
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

void	set_allowed_nodes(t_stack_node *a, int chunks)
{
	int	current_chunk;
	t_stack_node *current;

	current_chunk = 1;
	while(current_chunk <= chunks)
	{
		current = a;
		while(current && current->chunk != current_chunk)
			current = current->next;
		if(current)
			break;
		current_chunk++;
	}
	while(a)
	{
		a->allowed = (a->chunk == current_chunk);
		a = a->next;
	}
}

void	set_allowed_nodes_back(t_stack_node *a, int chunks)
{
	int	current_chunk;
	t_stack_node *current;

	current_chunk = chunks;
	while(current_chunk >= 1)
	{
		current = a;
		while(current && current->chunk != current_chunk)
			current = current->next;
		if(current)
			break;
		current_chunk--;
	}
	while(a)
	{
		a->allowed = (a->chunk == current_chunk);
		a = a->next;
	}
}

void	set_target_node_a(t_stack_node *target, t_stack_node *a)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node_a;
	long			smallest_biggest;

	current_a = a;
	smallest_biggest = LONG_MAX;
	target_node_a = NULL;
	while (current_a)
	{
		if (current_a->value > target->value
			&& current_a->value < smallest_biggest)
		{
			smallest_biggest = current_a->value;
			target_node_a = current_a;
		}
		current_a = current_a->next;
	}
	if (!target_node_a)
		target->target_node = find_lowest(a);
	else
		target->target_node = target_node_a;
}
