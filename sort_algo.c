/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 10:53:29 by afretta-          #+#    #+#             */
/*   Updated: 2026/01/02 18:15:27 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include<stdio.h>

static void	init_nodes(t_stack_node *a, t_stack_node *b);
// static void	move_nodes(t_stack_node **a, t_stack_node **b);
// static void	final_sort(t_stack_node **a);

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
		init_nodes(*a, *b); // todo
		move_nodes(a, b); // todo
	}
	set_current_position(a);
	// final_sort(a); //todo: rot or rev_rot until smallest node is at the top
}

static void	init_nodes(t_stack_node *a, t_stack_node *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_cost_move(a, b); //todo
	//set cheapest
}

// static void	move_nodes(t_stack_node **a, t_stack_node **b) // todo

// static void	final_sort(t_stack_node **a) //todo
