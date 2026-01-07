/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_rotations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:43:56 by afretta-          #+#    #+#             */
/*   Updated: 2026/01/07 18:38:26 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	special_rotate(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node)
{
	if (!cheapest_node || !cheapest_node->target_node)
		return ;
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rotate_both(a, b);
}

void	special_rev_rotate(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node)
{
	if (!cheapest_node || !cheapest_node->target_node)
		return ;
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rev_rotate_both(a, b);
}

void	final_rotations(t_stack_node **stack, t_stack_node *expected)
{
	while (*stack != expected)
	{
		if (expected->cost >= 0)
			rotate_b(stack);
		else
			rev_rotate_b(stack);
	}
}
