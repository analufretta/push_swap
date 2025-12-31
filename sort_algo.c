/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 10:53:29 by afretta-          #+#    #+#             */
/*   Updated: 2025/12/31 15:01:37 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	tiny_sort(t_stack_node **a)
{
	t_stack_node *highest_node;

	highest_node = find_highest(*a);
	if (*a == highest_node)
		rotate_a(a);
	else if ((*a)->next == highest_node)
		rev_rotate_a(a);
	if ((*a)->value > (*a)->next->value)
		swap_a(a);
}
