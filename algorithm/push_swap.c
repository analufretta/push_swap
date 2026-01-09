/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 10:53:29 by afretta-          #+#    #+#             */
/*   Updated: 2026/01/09 15:25:11 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void push_a_to_b(t_stack_node **a, t_stack_node **b, int len, int chunk_size);
static void push_b_to_a(t_stack_node **a, t_stack_node **b, int chunk_size);


void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	size_t	len;
	int		chunk_size;

	len = stack_len(*a);
	set_rank(*a, len);
	chunk_size = define_chunk_size(len);
	set_chunk(*a, len, chunk_size);
	push_a_to_b(a, b, len, chunk_size);
	if (!is_sorted(*a))
		sort_three(a);
	push_b_to_a(a, b, chunk_size);
	final_sort_asc(a); //review
}

static void push_a_to_b(t_stack_node **a, t_stack_node **b, int len, int chunk_size)
{
	while(len > 3)
	{
		allow_nodes(*a); //todo
		set_current_position(*a);
		set_current_position(*b);
		set_target_node_ab(*a, *b); //todo
		set_cost_move(*a); //redo
		set_cost_move(*b); //redo
		set_cheapest_move(*a); //check if it is correct
		rotate_cheapest_node(*a, *b); //todo
		push_b(a, b);
		len--;
	}
}

static void push_b_to_a(t_stack_node **a, t_stack_node **b, int chunk_size)
{
	t_stack_node *target;

	while(*b)
	{
		set_current_position(*a);
		set_current_position(*b);
		target = find_highest_rank(*b); //todo: use chunk ans rage to find more effitiently the highest one
		set_target_node_ba(target, *a); //todo
		set_cost_move(*a); //check if it is correct
		calc_target_move(*a, *b, target); //todo: set target as cheapest && calc rotations
		rotate_cheapest_node(*b, *a); //todo
		push_a(a, b);
	}
}
