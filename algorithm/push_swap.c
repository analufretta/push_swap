/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 10:53:29 by afretta-          #+#    #+#             */
/*   Updated: 2026/01/21 09:39:42 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	push_a_to_b(t_stack_node **a, t_stack_node **b, int len,
				int chunk_size);
static void	push_b_to_a(t_stack_node **a, t_stack_node **b);

void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	size_t	len;
	int		chunks;

	len = stack_len(*a);
	set_rank(*a, len);
	chunks = define_chunk_size(len);
	set_chunk(*a, len, chunks);
	push_a_to_b(a, b, len, chunks);
	if (!is_sorted(*a))
		sort_three(a);
	push_b_to_a(a, b);
	final_sort_asc(a);
}

static void	push_a_to_b(t_stack_node **a, t_stack_node **b, int len, int chunks)
{
	while (len > 3)
	{
		set_allowed_nodes(*a, chunks);
		set_current_position(*a);
		set_cost_move(*a);
		set_cheapest_node(*a);
		rotate_cheapest_a(a);
		push_b(a, b);
		len--;
	}
}

static void	push_b_to_a(t_stack_node **a, t_stack_node **b)
{
	while (*b)
	{
		set_current_position(*a);
		set_current_position(*b);
		set_cost_move(*a);
		set_cost_move(*b);
		set_target_node(*a, *b);
		set_cheapest_move(*b);
		rotate_cheapest_nodes(a, b);
		push_a(a, b);
	}
}
