/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:06:35 by afretta-          #+#    #+#             */
/*   Updated: 2026/01/22 15:17:21 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_smallest_to_b(t_stack_node **a, t_stack_node **b);

void	sort_three(t_stack_node **a)
{
	t_stack_node	*highest_node;

	if (!a || !*a || !(*a)->next || !(*a)->next->next)
		return ;
	highest_node = find_highest(*a);
	if (!highest_node)
		return ;
	if (*a == highest_node)
		rotate_a(a);
	else if ((*a)->next == highest_node)
		rev_rotate_a(a);
	if ((*a)->value > (*a)->next->value)
		swap_a(a);
}

void	sort_until_five(t_stack_node **a, t_stack_node **b)
{
	size_t	len;

	len = stack_len(*a);
	if (len == 4)
		push_smallest_to_b(a, b);
	else if (len == 5)
	{
		push_smallest_to_b(a, b);
		push_smallest_to_b(a, b);
	}
	sort_three(a);
	while (*b)
		push_a(a, b);
}

static void	push_smallest_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*smallest;
	size_t			len;
	int				middle;

	smallest = find_lowest(*a);
	len = stack_len(*a);
	middle = len / 2;
	set_current_position(*a);
	while (*a != smallest)
	{
		if (smallest->index >= middle)
			rotate_a(a);
		else
			rev_rotate_a(a);
	}
	push_b(a, b);
}
