/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_in_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:13:58 by afretta-          #+#    #+#             */
/*   Updated: 2026/01/20 15:41:02 by afretta-         ###   ########.fr       */
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
