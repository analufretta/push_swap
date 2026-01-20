/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_rotations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:43:56 by afretta-          #+#    #+#             */
/*   Updated: 2026/01/20 14:14:27 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_cheapest_a(t_stack_node **a)
{
	t_stack_node *cheapest_node;

	cheapest_node = *a;
	while(cheapest_node)
	{
		if(cheapest_node->cheapest)
			break;
		cheapest_node = cheapest_node->next;
	}
	if(cheapest_node->cost > 0)
		while(*a != cheapest_node)
			rotate_a(a);
	else
		while(*a != cheapest_node)
			rev_rotate_a(a);
}

void	rotate_target_node(t_stack_node **a, t_stack_node **b, t_stack_node *target)
{
	if(target->cost > 0 && target->target_node->cost > 0)
		while(*a != target->target_node && *b != target)
			rotate_both(a, b);
	else if (target->cost < 0 && target->target_node < 0)
		while(*a != target->target_node && *b != target)
			rev_rotate_both(a, b);
	while(*a != target->target_node)
	{
		if(target->target_node->cost > 0)
			rotate_a(a);
		else if(target->target_node->cost < 0)
			rev_rotate_a(a);
	}
	while(*b != target)
	{
		if(target->cost > 0)
			rotate_b(b);
		else if(target->cost < 0)
			rev_rotate_b(b);
	}
}

void	final_sort_asc(t_stack_node **a)
{
	t_stack_node	*smallest_value;
	size_t			len;
	int				medium;

	if (!a || !*a)
		return ;
	smallest_value = find_lowest(*a);
	len = stack_len(*a);
	medium = len / 2;
	if (smallest_value->index >= medium)
		while (*a != smallest_value)
			rotate_a(a);
	else
		while (*a != smallest_value)
			rev_rotate_a(a);
}
