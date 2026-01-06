/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 10:53:29 by afretta-          #+#    #+#             */
/*   Updated: 2026/01/06 12:43:24 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	init_nodes(t_stack_node *a, t_stack_node *b);
static void	move_nodes(t_stack_node **a, t_stack_node **b);
static void	final_sort(t_stack_node **a);

void	tiny_sort(t_stack_node **a)
{
	t_stack_node	*highest_node;

	highest_node = find_highest(*a);
	if (*a == highest_node)
		rotate_a(a);
	else if ((*a)->next == highest_node)
		rev_rotate_a(a);
	if ((*a)->value > (*a)->next->value)
		swap_a(a);
}

void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	size_t	len_a;

	len_a = stack_len(*a);
	while (len_a > 3)
	{
		push_b(a, b);
		len_a--;
	}
	if (!is_sorted(*a))
		tiny_sort(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	set_current_position(*a);
	final_sort(a);
}

static void	init_nodes(t_stack_node *a, t_stack_node *b)
{
	if (!b)
		return ;
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_cost_move(a, b);
	set_cheapest_move(b);
}

static void	move_nodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = find_cheapest(*b);
	if (cheapest_node->cost >= 0 && cheapest_node->target_node->cost >= 0)
		special_rotate(a, b, cheapest_node);
	else if (cheapest_node->cost < 0 && cheapest_node->target_node->cost < 0)
		special_rev_rotate(a, b, cheapest_node);
	final_rotations(b, cheapest_node, 'b');
	final_rotations(a, cheapest_node, 'a');
	push_a(a, b);
}

static void	final_sort(t_stack_node **a)
{
	t_stack_node	*smallest_value;
	size_t			len;
	int				medium;

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
