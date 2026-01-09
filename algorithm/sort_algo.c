/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 10:53:29 by afretta-          #+#    #+#             */
/*   Updated: 2026/01/09 11:04:20 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	set_nodes(t_stack_node *a, t_stack_node *b, char dest);
static void	move_nodes(t_stack_node **a, t_stack_node **b, char dest);
static void	last_moves(t_stack_node **a, t_stack_node **b, t_stack_node *cheap, char dest);

void	sort_stack(t_stack_node **a, t_stack_node **b) //remake
{
	size_t	len_a;

	len_a = stack_len(*a);
	set_rank(*a, len_a);
	if (len_a <= 100)
		//divide by
	else if (len_a <= 500)
		//divide by 5
	else
		//divide by 11

	while (len_a > 3)
	{
		//send
		set_nodes(*a, *b, 'b');
		move_nodes(a, b, 'b');
		len_a--;
	}
	if (!is_sorted(*a))
		tiny_sort(a);
	while (*b)
	{
		set_nodes(*a, *b, 'a');
		move_nodes(a, b, 'a');
	}
	final_sort_asc(a);
}

static void	set_nodes(t_stack_node *a, t_stack_node *b, char dest)
{
	set_current_position(a);
	set_current_position(b);
	if (dest == 'b')
	{
		set_a_target_node(a, b);
		set_cost_move(a, b);
		set_cheapest_move(a);
	}
	else
	{
		set_b_target_node(a, b);
		set_cost_move(a, b);
		set_cheapest_move(b);
	}
}

static void	move_nodes(t_stack_node **a, t_stack_node **b, char dest)
{
	t_stack_node	*cheapest_node;

	cheapest_node = NULL;
	if (dest == 'a')
		cheapest_node = find_cheapest(*b);
	else
		cheapest_node = find_cheapest(*a);
	if (!cheapest_node || !cheapest_node->target_node)
		return ;
	if (dest == 'a')
	{
		if (cheapest_node->cost > 0 && cheapest_node->target_node->cost > 0)
			special_rotate(a, b, cheapest_node);
		else if (cheapest_node->cost < 0 && cheapest_node->target_node->cost < 0)
			special_rev_rotate(a, b, cheapest_node);
	}
	else
	{
		if (cheapest_node->cost > 0 && cheapest_node->target_node->cost > 0)
			special_rotate(b, a, cheapest_node);
		else if (cheapest_node->cost < 0 && cheapest_node->target_node->cost < 0)
			special_rev_rotate(b, a, cheapest_node);
	}
	last_moves(a, b, cheapest_node, dest);
}

static void	last_moves(t_stack_node **a, t_stack_node **b, t_stack_node *cheap, char dest)
{
	if (dest == 'a')
	{
		final_rotations(b, cheap);
		final_rotations(a, cheap->target_node);
		push_a(a, b);
	}
	else
	{
		final_rotations(b, cheap->target_node);
		final_rotations(a, cheap);
		push_b(a, b);
	}
}
