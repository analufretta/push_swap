/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_rotations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:43:56 by afretta-          #+#    #+#             */
/*   Updated: 2026/01/08 15:46:00 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	special_rotate(t_stack_node **src, t_stack_node **dst,
		t_stack_node *cheapest_node)
{
	if (!cheapest_node || !cheapest_node->target_node)
		return ;
	while (*src != cheapest_node->target_node && *dst != cheapest_node)
		rotate_both(src, dst);
}

void	special_rev_rotate(t_stack_node **src, t_stack_node **dst,
		t_stack_node *cheapest_node)
{
	if (!cheapest_node || !cheapest_node->target_node)
		return ;
	while (*src != cheapest_node->target_node && *dst != cheapest_node)
		rev_rotate_both(src, dst);
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
