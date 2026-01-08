/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:40:41 by afretta-          #+#    #+#             */
/*   Updated: 2026/01/08 09:52:28 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_sort_asc(t_stack_node **a)
{
	t_stack_node	*smallest_value;
	size_t			len;
	int				medium;

	if (!a || !*a)
		return ;
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

void	final_sort_desc(t_stack_node **b)
{
	t_stack_node	*biggest_value;
	size_t			len;
	int				medium;

	if (!b || !*b)
		return ;
	biggest_value = find_highest(*b);
	len = stack_len(*b);
	medium = len / 2;
	if (biggest_value->index <= medium)
		while (*b != biggest_value)
			rotate_b(b);
	else
		while (*b != biggest_value)
			rev_rotate_b(b);
}
