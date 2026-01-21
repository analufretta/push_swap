/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 09:34:52 by afretta-          #+#    #+#             */
/*   Updated: 2026/01/21 09:36:40 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_abs(int cost)
{
	if (cost < 0)
		cost = -cost;
	return (cost);
}

int	total_cost(t_stack_node *b)
{
	int	total_cost;

	if ((b->target_node->cost > 0 && b->cost > 0) || (b->target_node->cost < 0
			&& b->cost < 0))
		total_cost = ps_max(ps_abs(b->target_node->cost), ps_abs(b->cost));
	else
		total_cost = ps_abs(b->target_node->cost) + ps_abs(b->cost);
	return (total_cost);
}

int	ps_max(int cost_a, int cost_b)
{
	if (cost_a > cost_b)
		return (cost_a);
	return (cost_b);
}
