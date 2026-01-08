/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:40:41 by afretta-          #+#    #+#             */
/*   Updated: 2026/01/08 17:23:04 by afretta-         ###   ########.fr       */
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

