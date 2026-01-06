/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_rotatios.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:43:56 by afretta-          #+#    #+#             */
/*   Updated: 2026/01/06 12:52:23 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	special_rotate(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rotate_both(a, b);
}

void	special_rev_rotate(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rev_rotate_both(a, b);
}

void	final_rotations(t_stack_node **stack, t_stack_node *cheapest_node,
		char stack_name)
{
	if (stack_name == 'a')
	{
		while (*stack != cheapest_node->target_node)
		{
			if (cheapest_node->target_node->cost >= 0)
				rotate_a(stack);
			else
				rev_rotate_a(stack);
		}
	}
	else if (stack_name == 'b')
	{
		while (*stack != cheapest_node)
		{
			if (cheapest_node->cost >= 0)
				rotate_b(stack);
			else
				rev_rotate_b(stack);
		}
	}
}
