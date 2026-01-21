/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_rotations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:43:56 by afretta-          #+#    #+#             */
/*   Updated: 2026/01/21 17:42:19 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_nodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = NULL;
	cheapest_node = find_cheapest_node(*b);
	if (cheapest_node->cost > 0 && cheapest_node->target_node->cost > 0)
		while (*a != cheapest_node->target_node && *b != cheapest_node)
			rotate_both(a, b);
	else if (cheapest_node->cost < 0 && cheapest_node->target_node->cost < 0)
		while (*a != cheapest_node->target_node && *b != cheapest_node)
			rev_rotate_both(a, b);
	while (*a != cheapest_node->target_node)
	{
		if (cheapest_node->target_node->cost > 0)
			rotate_a(a);
		else if (cheapest_node->target_node->cost < 0)
			rev_rotate_a(a);
	}
	while (*b != cheapest_node)
	{
		if (cheapest_node->cost > 0)
			rotate_b(b);
		else if (cheapest_node->cost < 0)
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
